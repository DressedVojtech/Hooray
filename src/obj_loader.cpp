// obj_loader.cpp
#include "obj_loader.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

static inline bool starts_with(const std::string& s, const char* pfx) {
    return s.compare(0, std::string::npos, pfx, std::char_traits<char>::length(pfx)) == 0;
}

// vrátí vertex index z tokenu "v", "v/vt", "v//vn", "v/vt/vn"
static int parse_vertex_index(const std::string& tok) {
    // najdi první '/'
    size_t slash = tok.find('/');
    if (slash == std::string::npos) {
        return std::stoi(tok);              // "v"
    } else {
        return std::stoi(tok.substr(0, slash)); // "v/..." -> v
    }
}

// převeď OBJ index (1-based, může být záporný) na 0-based do pole vrcholů
static int to_zero_based(int idx, int count) {
    if (idx > 0)      return idx - 1;            // 1..N  -> 0..N-1
    else if (idx < 0) return count + idx;        // -1 je poslední
    else              return -1;                 // 0 je neplatné v OBJ
}

object* load_obj(const std::string& path, const rgb& color, float scale, const vec3& position) {
    std::ifstream in(path);
    if (!in) {
        // nenahráno – vrať prázdný object s bounds v pozici (ať se to nezhroutí)
        object* obj = new object();
        obj->position = position;
        obj->rebuild_bounds();
        return obj;
    }

    std::vector<vec3> vertices;
    vertices.reserve(1000);

    std::string line;
    while (std::getline(in, line)) {
        // ořízni začátek na netabulární/nebílé znaky
        size_t p = 0;
        while (p < line.size() && std::isspace((unsigned char)line[p])) ++p;
        if (p >= line.size()) continue;
        if (line[p] == '#') continue; // komentář

        // v
        if (line.compare(p, 2, "v ") == 0) {
            std::istringstream ls(line.substr(p+2));
            float x, y, z;
            if (ls >> x >> y >> z) {
                vertices.emplace_back(x * scale, y * scale, z * scale);
            }
            continue;
        }

        // f (polygon n>=3)
        if (line.compare(p, 2, "f ") == 0) {
            std::istringstream ls(line.substr(p+2));
            std::vector<int> faceIdx;
            faceIdx.reserve(8);

            std::string tok;
            while (ls >> tok) {
                int v = parse_vertex_index(tok);
                int idx0 = to_zero_based(v, (int)vertices.size());
                if (idx0 >= 0 && idx0 < (int)vertices.size()) {
                    faceIdx.push_back(idx0);
                }
            }

            // triangulace fanem: (0, i, i+1)
            if (faceIdx.size() >= 3) {
                // lazy object init až teď (když víme, že máme aspoň 1 face)
                // …ale my object potřebujeme i bez faces – držme to jednoduché:
                // vytvořme object až dole, ale trojúhelníky přidávat musíme.
                // => vytvořme dočasný list trianglů a pak je přesuneme do objektu.
                // kvůli jednoduchosti: vytvoříme object hned nahoře mimo smyčky.

                // nic – pokračujeme, ale přidáme trojúhelníky až poté, co máme object
            }

            // pro jednoduchost přidáme trojúhelníky hned → potřebujeme object.
            // řešení: vytvoříme static pointer a na konci vrátíme poslední vytvořený.
            // Lepší: držme object jako statický v této funkci.
        }
    }

    // Druhý průchod: vytvoř znovu (čistě) – jednodušší je vést file ještě jednou.
    // Abychom zůstali čitelní, prostě file přečteme podruhé a rovnou budeme push_back trojúhelníky.
    in.clear();
    in.seekg(0, std::ios::beg);

    object* obj = new object();
    obj->position = position;

    while (std::getline(in, line)) {
        size_t p2 = 0;
        while (p2 < line.size() && std::isspace((unsigned char)line[p2])) ++p2;
        if (p2 >= line.size() || line[p2] == '#') continue;

        if (line.compare(p2, 2, "f ") == 0) {
            std::istringstream ls(line.substr(p2+2));
            std::vector<int> faceIdx;
            std::string tok;
            while (ls >> tok) {
                int v = parse_vertex_index(tok);
                int idx0 = to_zero_based(v, (int)vertices.size());
                if (idx0 >= 0 && idx0 < (int)vertices.size()) {
                    faceIdx.push_back(idx0);
                }
            }
            if (faceIdx.size() < 3) continue;

            // triangulace fanem
            const int v0 = faceIdx[0];
            for (size_t i = 1; i + 1 < faceIdx.size(); ++i) {
                int v1 = faceIdx[i];
                int v2 = faceIdx[i+1];

                // POZOR: tvoje triangle očekává lokální souřadnice objektu (bez position),
                // proto sem dáváme jen vrcholy (už scaled), bez posunu.
                obj->triangles.push_back(new triangle(vertices[v0], vertices[v1], vertices[v2], color));
            }
        }
    }

    obj->rebuild_bounds();
    return obj;
}

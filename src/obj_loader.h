// obj_loader.h
#pragma once
#include <string>
#include "object.h"
#include "rgb.h"
#include "vec3.h"

// Načte OBJ z disku, vynásobí vrcholy 'scale', nastaví 'position' objektu,
// obarví všechny stěny barvou 'color' a vrátí hotový object* (volající ho pak delete-ně).
object* load_obj(const std::string& path,
                 const rgb& color = rgb(0.8f, 0.8f, 0.8f),
                 float scale = 1.0f,
                 const vec3& position = vec3(0.0f, 0.0f, 0.0f));

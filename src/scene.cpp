#include "scene.h"

scene::scene(rgb BACKGROUND, int WIDTH, int HEIGHT, vec3 CAM_POS, float FOCAL_LENGTH, /*std::vector<light_source> LIGHT_SOURCES,*/ std::vector<object*> OBJECTS) {
    bg_color = BACKGROUND;
    screen_width = WIDTH;
    screen_height = HEIGHT;
    cam_pos = CAM_POS;
    distance = FOCAL_LENGTH;
    objects = OBJECTS;
    // light_sources = LIGHT_SOURCES;
}

scene::scene(rgb BACKGROUND, int WIDTH, int HEIGHT, vec3 CAM_POS, float FOCAL_LENGTH) {
    bg_color = BACKGROUND;
    screen_width = WIDTH;
    screen_height = HEIGHT;
    cam_pos = CAM_POS;
    distance = FOCAL_LENGTH;
}

scene::scene(std::vector<object*> OBJECTS) {
    bg_color = rgb();
    screen_width = 1920;
    screen_height = 1080;
    cam_pos = vec3();
    distance = 10;
    objects = OBJECTS;
    // light_sources.push_back({0, 0, 0}, 1);
}

void scene::render() {
    bitmap colors(screen_width, screen_height);

    for (int x = 0; x < screen_height; x++) {
        for (int y = 0; y < screen_width; y++) {
            std::cout << x << ", " << y << std::endl;
            float t_min = FLT_MAX;
            int index_o = -1;
            int index_t = -1;

            vec3 pixel_world(
                cam_pos.x - (screen_width  / 2.0f) + y,
                cam_pos.y + distance,
                cam_pos.z + (screen_height / 2.0f) - x
            );

            vec3 dir = pixel_world - cam_pos;

            float len = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
            if (len > 0.0f) {
                dir = dir / len;
            }

            line RAY = { cam_pos, dir };

            for (int i = 0; i < objects.size(); i++) {
                if ((*objects[i]).bounds.hit(RAY, 0.001f, 1000000)) {
                    for (int j = 0; j < (*objects[i]).triangles.size(); j++) {
                        AABB b;
                        b.expand((*objects[i]).triangles[j]->p0 + (*objects[i]).position);
                        b.expand((*objects[i]).triangles[j]->p1 + (*objects[i]).position);
                        b.expand((*objects[i]).triangles[j]->p2 + (*objects[i]).position);

                        if (b.hit(RAY, 0.001f, 1000000)) {
                            float t = (*objects[i]).triangles[j]->intersection(RAY);
                            if (t > 0.0f && t < t_min) {
                                t_min = t;
                                index_t = j;
                                index_o = i;
                            }
                        }
                    }
                }
            }

            if ((index_o != -1) && (index_t != -1)) {
                colors.setCell(
                    rgba((*objects[index_o]).triangles[index_t]->color, 1.0f),
                    x, y
                );
            } else {
                colors.setCell(bg_color, x, y);
            }
        }
    }

    bm.push_back(colors);
}
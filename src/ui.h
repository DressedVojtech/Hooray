#ifndef ui_H
#define ui_H
#include <string>
#include "scene.h"

class ui {
    public:
        bool areSafeFilesPresent;
        std::string path;
        scene Scene;

        void tui();
};


#endif
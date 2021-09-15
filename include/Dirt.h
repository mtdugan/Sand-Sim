#include "raylib.h"
#include <stdlib.h>
#include "Solid.h"

using namespace std;

#ifndef DIRT_H
#define DIRT_H


class Dirt: public Solid {    
    public:
        Dirt();
    private:    
};

Dirt::Dirt()  {
    set_id(DIRT);
    set_color(BROWN);
    set_inertia(150);
    set_density(50);
}

#endif

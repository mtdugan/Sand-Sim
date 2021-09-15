#include "raylib.h"
#include <stdlib.h>
#include "Solid.h"

using namespace std;

#ifndef ROCK_H
#define ROCK_H


class Rock: public Solid {    
    public:
        Rock();
    private:    
};

Rock::Rock()  {
    set_id(ROCK);
    set_color(ROCK_C);
    set_inertia(600);
    set_density(50);
}

#endif

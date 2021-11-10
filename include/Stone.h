#include "raylib.h"
#include <stdlib.h>
#include "Solid.h"

#ifndef Stone_H
#define Stone_H


class Stone: public Solid {    
    public:
        Stone();
    private:    
};

Stone::Stone()  {
    set_id(STONE);
    set_color(GRAY);
    set_inertia(100);
    set_density(50);
}

#endif

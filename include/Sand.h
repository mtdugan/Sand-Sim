#include "raylib.h"
#include <stdlib.h>
#include "Solid.h"

using namespace std;

#ifndef SAND_H
#define SAND_H


class Sand: public Solid {    
    public:
        Sand();
    private:    
};

Sand::Sand()  {
    set_id(SAND);
    set_color(YELLOW);
    set_inertia(1);
    set_density(50);
}

#endif

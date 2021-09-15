#include "raylib.h"
#include <stdlib.h>
#include "Liquid.h"

#ifndef WATER_H
#define WATER_H


class Water: public Liquid {    
    public:
        Water();
    private:    
};

Water::Water()  {
    set_id(WATER);
    set_color(BLUE);
    set_flow_speed(5);
    set_evaporation(4);
    set_density(10);
}

#endif

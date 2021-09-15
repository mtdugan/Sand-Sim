#include "raylib.h"
#include <stdlib.h>
#include "Liquid.h"

#ifndef GASOLINE_H
#define GASOLINE_H

class Gasoline: public Liquid {    
    public:
        Gasoline();
    private:    
};

Gasoline::Gasoline()  {
    set_id(GASOLINE);
    set_color(GASOLINE_C);
    set_flow_speed(4);
    set_evaporation(6);
    set_density(4);
}

#endif

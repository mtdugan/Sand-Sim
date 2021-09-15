#include "raylib.h"
#include <stdlib.h>
#include "Liquid.h"

#ifndef OIL_H
#define OIL_H

class Oil: public Liquid {    
    public:
        Oil();
    private:    
};

Oil::Oil()  {
    set_id(OIL);
    set_color(OIL_C);
    set_flow_speed(2);
    set_evaporation(2);
    set_density(5);
}

#endif

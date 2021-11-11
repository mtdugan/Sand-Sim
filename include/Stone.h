#include "raylib.h"
#include <stdlib.h>
#include "Solid.h"

#ifndef Stone_H
#define Stone_H


class Stone: public Solid {    
    public:
        Stone();
        void update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y);
    private:    
};

Stone::Stone()  {
    set_id(STONE);
    set_color(GRAY);
    set_inertia(100);
    set_density(50);
}

void Stone::update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y) {}

#endif

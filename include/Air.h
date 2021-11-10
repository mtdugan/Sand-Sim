#include "raylib.h"
#include <stdlib.h>
#include "Cell.h"

#ifndef AIR_H
#define AIR_H


class Air: public Cell {    
    public:
        Air();
        void update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y);
    private:    
};

Air::Air()  {
    set_id(AIR);
    set_color(DARKGRAY);
    set_density(0);
}

void Air::update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y) {}

#endif

#include "raylib.h"
#include <stdlib.h>
#include "Cell.h"

#ifndef BEDROCK_H
#define BEDROCK_H


class Bedrock: public Solid {    
    public:
        Bedrock();
        void update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y);
    private:    
};

Bedrock::Bedrock()  {
    set_id(BEDROCK);
    set_color(BEDROCK_C);
    set_inertia(100);
    set_density(100);
}

void Bedrock::update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y) {
    new_world[x][y] = old_world[x][y];
}

#endif

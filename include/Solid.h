#include "raylib.h"
#include <stdlib.h>
#include "Cell.h"

#ifndef SOLID_H
#define SOLID_H


class Solid: public Cell {    
    public:
        Solid();
        int get_inertia();
        void set_inertia(int value);
        void update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y);
    private:    
        int inertia; // 0-200

};

Solid::Solid() {

}

int Solid::get_inertia() {
    return inertia;
}
void Solid::set_inertia(int value) {
    inertia = value;
}

void Solid::update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y) {
    if (!get_moving() && old_world[x][y+1]->get_density() >= get_density())
        return;

    set_target_x(x);
    set_target_y(y);    
    if (old_world[x][y+1]->get_density() < get_density()) {
        // Falling because object below has lower density
        old_world[x][y-1]->set_moving(true);
        old_world[x-1][y]->set_moving(true);
        old_world[x+1][y]->set_moving(true);
        set_target_y(y+1);
    }
    else if (get_inertia() > GetRandomValue(0,1000)) {
        // Inertia won: Stay
        set_moving(false);
    }
    else if (old_world[x-1][y+1]->get_density() < get_density()) {
        // Move down to the left
        set_target_x(x-1);
        set_target_y(y+1);
    }
    else if (old_world[x+1][y+1]->get_density() < get_density()) {
        // Move down to the right
        set_target_x(x+1);
        set_target_y(y+1);
    }

    // Execute move
    if (new_world[get_target_x()][get_target_y()]->get_updated_this_frame() == false) {
        if (get_target_x() != x || get_target_y() != y) {
            new_world[get_target_x()][get_target_y()] = old_world[x][y];        
            new_world[x][y] = old_world[get_target_x()][get_target_y()];
            
            new_world[get_target_x()][get_target_y()]->set_updated_this_frame(true); 
            new_world[x][y]->set_updated_this_frame(true);
        }
    }
    return;
}

#endif

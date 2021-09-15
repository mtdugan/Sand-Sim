#include "raylib.h"
#include <stdlib.h>
#include "Cell.h"
#include "Air.h"

#ifndef LIQUID_H
#define LIQUID_H

#define RIGHT 0
#define LEFT 1



class Liquid: public Cell {    
    public:
        Liquid();
        int get_flow_direction();
        void set_flow_direction(int value);
        int get_flow_speed();
        void set_flow_speed(int value);
        int get_evaporation();
        void set_evaporation(int value);
        void update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y);
    private:    
        int flow_direction;
        int flow_speed;     // 1-4
        int evaporation;    // 0 - 5000

};

Liquid::Liquid()  {
    set_flow_direction(GetRandomValue(0,1));
}

int Liquid::get_flow_direction() {
    return flow_direction;
}
void Liquid::set_flow_direction(int value) {
    flow_direction = value;
}

int Liquid::get_flow_speed() {
    return flow_speed;
}
void Liquid::set_flow_speed(int value) {
    flow_speed = value;
}

int Liquid::get_evaporation() {
    return evaporation;
}
void Liquid::set_evaporation(int value) {
    evaporation = value;
}

void Liquid::update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y) {
    if (get_updated_this_frame() || (old_world[x][y+1]->get_density() > get_density() && old_world[x-1][y]->get_density() > get_density() && old_world[x+1][y]->get_density() > get_density()))  {         // dont think i need a already upadated check
        return;
    }
    set_target_x(x);
    set_target_y(y);  
    if (old_world[x][y+1]->get_density() < get_density()) {
        // Falling because object below has lower density
        set_target_y(y+1);
        old_world[x][y+1]->set_moving(true);
        old_world[x-1][y]->set_moving(true);
        old_world[x+1][y]->set_moving(true);
    }
    else if (get_flow_direction() == LEFT) {
        if (old_world[x-1][y+1]->get_density() < get_density()) {
            // Move down to the left
            set_target_x(x-1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x-i][y+1]->get_density() < get_density())
                    set_target_x(x-i);
                else
                    break;
            }
            set_target_y(y+1);
        }
        else if (old_world[x-1][y]->get_density() < get_density()) {
            // Move to the left
            set_target_x(x-1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x-i][y]->get_density() < get_density())
                    set_target_x(x-i);
                else
                    break;
            }
            set_target_y(y);
        }
        else if (old_world[x+1][y+1]->get_density() < get_density()) {
            // Move down to the right
            set_target_x(x+1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x+i][y+1]->get_density() < get_density())
                    set_target_x(x+i);
                else
                    break;
            }
            set_target_y(y+1);
        }
        else if (old_world[x+1][y]->get_density() < get_density()) {
            // Move to the right
            set_target_x(x+1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x+i][y]->get_density() < get_density())
                    set_target_x(x+i);
                else
                    break;
            }
            set_target_y(y);
        }
    }
    else if (get_flow_direction() == RIGHT) {
        if (old_world[x+1][y+1]->get_density() < get_density()) {
            // Move down to the right
            set_target_x(x+1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x+i][y+1]->get_density() < get_density())
                    set_target_x(x+i);
                else
                    break;
            }
            set_target_y(y+1);
        }
        else if (old_world[x+1][y]->get_density() < get_density()) {
            // Move to the right
            set_target_x(x+1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x+i][y]->get_density() < get_density())
                    set_target_x(x+i);
                else
                    break;
            }
            set_target_y(y);
        }
        else if (old_world[x-1][y+1]->get_density() < get_density()) {
            // Move down to the left
            set_target_x(x-1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x-i][y+1]->get_density() < get_density())
                    set_target_x(x-i);
                else
                    break;
            }
            set_target_y(y+1);
        }
        else if (old_world[x-1][y]->get_density() < get_density()) {
            // Move to the left
            set_target_x(x-1);
            for (int i = 1; i < get_flow_speed(); i++) {
                if (old_world[x-i][y]->get_density() < get_density())
                    set_target_x(x-i);
                else
                    break;
            }
            set_target_y(y);
        }
    }
//MAYBE STUFF BELOW IS UNIQUE TO EACH LIQUID FOR EFFETS AND WHAT NOT. MOVEMENT IS THE SAME BUT NOT WAHT LAVA DOES TO WATER VS OIL?
    // Execute move
    if (new_world[get_target_x()][get_target_y()]->get_updated_this_frame() == false) {
        if (old_world[x-1][y]->get_density() < get_density() || old_world[x+1][y]->get_density() < get_density()) {
            // Air around water. Maybe evaporate
            if (get_evaporation() > GetRandomValue(0,5000))
                old_world[x][y] = new Air();
        }
        if (get_target_x() != x || get_target_y() != y) {
            
            new_world[get_target_x()][get_target_y()] = old_world[x][y];        
            new_world[x][y] = old_world[get_target_x()][get_target_y()];
            
            new_world[get_target_x()][get_target_y()]->set_updated_this_frame(true); 
            new_world[x][y]->set_updated_this_frame(true);
        }
    }

    if (get_target_x() < x)
        set_flow_direction(LEFT);
    else if (get_target_x() > x)
        set_flow_direction(RIGHT);

    return;
}

#endif

#include "raylib.h"
#include <stdlib.h>
#include <iostream>

#ifndef CELL_H
#define CELL_H

#define AIR 1
#define SAND 2
#define BEDROCK 3
#define WATER 4
#define STONE 4
#define OIL 5
#define DIRT 6
#define ROCK 7
#define GASOLINE 7
#define LAVA 7
#define FIRE 8

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 720;
const int CELL_WIDTH = 5;
const int CELL_HEIGHT = 5;
const int WORLD_WIDTH = WINDOW_WIDTH/CELL_WIDTH;
const int WORLD_HEIGHT = WINDOW_HEIGHT/CELL_HEIGHT;
const int BEDROCK_THICKNESS = 5;

class Cell {    
    public:
        Cell();
        int get_id();
        void set_id(int value);
        Color get_color();
        void set_color(Color c);
        int get_width();
        void set_width(int value);
        int get_height();
        void set_target_x(int value);
        int get_target_x();
        void set_target_y(int value);
        int get_target_y();
        void set_density(int value);
        int get_density();
        void set_height(int value);
        bool get_moving();
        void set_moving(bool value);
        bool get_updated_this_frame();
        void set_updated_this_frame(bool value);
        virtual void update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y);
        void draw_cell(int x, int y);
      private:
        int id;
        Color color;
        int width, height;
        int target_x, target_y;
        int density;    // 0 - 100
        bool moving;
        bool updated_this_frame;
        // TODO: SHOULD EVERy CELL HAVE AN X AND Y? SO THEN WE DONT NEED TO PASS IN INT X AND Y

};

Cell::Cell()  {
    set_width(CELL_WIDTH);
    set_height(CELL_HEIGHT);
    set_id(0);
    set_color(PINK);
    set_moving(true);
    set_updated_this_frame(true);  
}

int Cell::get_id() {return id;}
void Cell::set_id(int value) {id = value;}

Color Cell::get_color() {return color;}
void Cell::set_color(Color c) {color = c;}

int Cell::get_width() {return width;}
void Cell::set_width(int value) {width = value;}

int Cell::get_height() {return height;}
void Cell::set_height(int value) {height = value;}

int Cell::get_target_x() {return target_x;}
void Cell::set_target_x(int value) {target_x = value;}

int Cell::get_target_y() {return target_y;}
void Cell::set_target_y(int value) {target_y = value;}

int Cell::get_density() {return density;}
void Cell::set_density(int value) {density = value;}

bool Cell::get_moving() {return moving;}
void Cell::set_moving(bool value) {moving = value;}

bool Cell::get_updated_this_frame() {return updated_this_frame;}
void Cell::set_updated_this_frame(bool value) {updated_this_frame = value;}

void Cell::update_cell_position(Cell* old_world[][WORLD_HEIGHT], Cell* new_world[][WORLD_HEIGHT], int x, int y) {}

void Cell::draw_cell(int x, int y) {
    DrawRectangle(x + x*CELL_WIDTH + 1, y + y*CELL_HEIGHT + 1, width, height,color);
}

#endif
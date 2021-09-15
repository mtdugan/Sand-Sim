#include "include/raylib.h"
#include <stdlib.h>
#include "include/Cell.h"
#include "include/Sand.h"
#include "include/Air.h"
#include "include/Bedrock.h"
#include "include/Water.h"
#include "include/Stone.h"
#include "include/Oil.h"
#include "include/Dirt.h"
#include "include/Rock.h"
#include "include/Gasoline.h"

using namespace std;


int main() {
    float brush_size = 1.0f;

    Cell* this_world[WORLD_WIDTH][WORLD_HEIGHT];
    Cell* next_world[WORLD_WIDTH][WORLD_HEIGHT];
    
    //Intialize worlds
    for (int i = WORLD_WIDTH - 1; i >= 0; i--) {
        for (int j = WORLD_HEIGHT - 1; j >= 0; j--) {
            if (j >= WORLD_HEIGHT - BEDROCK_THICKNESS)
                this_world[i][j] = new Bedrock();  
            else if (i < BEDROCK_THICKNESS || i >= WORLD_WIDTH - BEDROCK_THICKNESS) 
                this_world[i][j] = new Bedrock();
            else
                this_world[i][j] = new Air();  
            next_world[i][j] = this_world[i][j];                
        }
    }
    // TODO: Why do i need to add these magic numbers?
    InitWindow(WINDOW_WIDTH + 250, WINDOW_HEIGHT + 150, "Need name");
    SetTargetFPS(500);
    while (!WindowShouldClose()) {
        Vector2 mouse_pos = GetMousePosition();
        brush_size += GetMouseWheelMove() * 2;

        if (brush_size < 1) 
            brush_size = 1;
        if (brush_size > 25) 
            brush_size = 25;
        // Draw
        if (IsMouseButtonDown(0) || IsMouseButtonDown(1)) {
            for (int i = 0; i < brush_size; i++) {
                for (int j = 0; j < brush_size; j++) {
                    int x = (mouse_pos.x + i*CELL_WIDTH)/(1 + CELL_WIDTH);
                    int y = (mouse_pos.y + j*CELL_HEIGHT)/(1 + CELL_HEIGHT);
                    if ((x < WORLD_WIDTH - BEDROCK_THICKNESS && y < WORLD_HEIGHT - BEDROCK_THICKNESS) && (x > BEDROCK_THICKNESS - 1 && y > 0)) { 
                        if (IsMouseButtonDown(0)) 
                            if (IsKeyDown(KEY_S))
                                next_world[x][y] = new Sand();
                            else if (IsKeyDown(KEY_W))
                                next_world[x][y] = new Water();
                            else if (IsKeyDown(KEY_O))
                                next_world[x][y] = new Oil();
                            else if (IsKeyDown(KEY_D))
                                next_world[x][y] = new Dirt();
                            else if (IsKeyDown(KEY_R))
                                next_world[x][y] = new Rock();
                            else if (IsKeyDown(KEY_G))
                                next_world[x][y] = new Gasoline();
                            else 
                                next_world[x][y] = new Stone();
                        else
                            next_world[x][y] = new Air();
                    }                                                
                }
            }
        }

        int itteration_direction = GetRandomValue(0,3);
        if (itteration_direction == 0) {
            // Update left to right, top to bottom
            for (int i = 0; i < WORLD_WIDTH - BEDROCK_THICKNESS; i++) {
                for (int j = 0; j < WORLD_HEIGHT - BEDROCK_THICKNESS; j++) {
                    this_world[i][j]->update_cell_position(this_world, next_world, i, j);
                }
            }
        }
        else if (itteration_direction == 1) {
            // Update right to left, bottom to top
            for (int i = WORLD_WIDTH - 1 - BEDROCK_THICKNESS; i >= 0; i--) {
                for (int j = WORLD_HEIGHT - 1 - BEDROCK_THICKNESS; j >= 0; j--) {
                    this_world[i][j]->update_cell_position(this_world, next_world, i, j);  
                }
            }    
        }
        else if (itteration_direction == 2) {
            // Update left to right, bottom to top
            for (int i = 0; i < WORLD_WIDTH - BEDROCK_THICKNESS; i++) {
                for (int j = WORLD_HEIGHT - 1 - BEDROCK_THICKNESS; j >= 0; j--) {
                    this_world[i][j]->update_cell_position(this_world, next_world, i, j);
                }
            }  
        }
        else {
            // Update right to left, top to bottom
            for (int i = WORLD_WIDTH - 1 - BEDROCK_THICKNESS; i >= 0; i--) {
                for (int j = 0; j < WORLD_HEIGHT - BEDROCK_THICKNESS; j++) {
                    this_world[i][j]->update_cell_position(this_world, next_world, i, j);  
                }
            }    
        }
        
        BeginDrawing();
        ClearBackground(DARKGRAY);

        for (int i = WORLD_WIDTH - 1; i >= 0; i--) {
            for (int j = WORLD_HEIGHT - 1; j >= 0; j--) {
                next_world[i][j]->draw_cell(i,j);
                this_world[i][j] = next_world[i][j];
                this_world[i][j]->set_updated_this_frame(false);
            }
        }
        
        DrawFPS(35, 10);
        DrawText(TextFormat("Brush Size: %.0f", brush_size), 35, 30, 20, LIME); 
        EndDrawing();   
    }
}
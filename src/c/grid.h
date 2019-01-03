#ifndef GRID_H   /* Include guard */
#define GRID_H
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "utils.h"
#define GRID_MAX_X_CELLS (40)
#define GRID_MAX_Y_CELLS (40)

//thats the way to define enum in c, hideous.
typedef enum TILE_TYPE {
    soil = 0,
    grass = 1,
    water = 2
} TILE_TYPE;

struct Tile {
    RecAndTexture rect_and_texture;
    TILE_TYPE tile_type;
};
typedef struct Tile Tile;

struct Grid {
    // x, y, width, height
    SDL_Rect rect;

    // Number of cells over the x axis
    int xTiles;
    // Number of cells over the y axis
    int yTiles;

    // Matrix of Tiles
    Tile tiles[GRID_MAX_X_CELLS][GRID_MAX_Y_CELLS];
};
typedef struct Grid Grid;

int grid_adjustSize(Grid *grid);
void grid_alignCenter(Grid *grid, int screenWidth, int screenHeight);

bool grid_init(SDL_Renderer* renderer, Grid *grid);
void grid_init_tile(SDL_Renderer* renderer, Grid *grid, Tile *tile, int i, int j, TILE_TYPE type);

void grid_render(Grid *grid, SDL_Renderer *renderer);
void grid_render_tile(Tile *tile, SDL_Renderer *renderer);

#endif
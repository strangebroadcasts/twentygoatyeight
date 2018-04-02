#include <gb/gb.h>
#include <gb/drawing.h>
#include <asm/types.h>

#include "game.h"
#include "tiles.h"

#define BOARD_START_X 56
#define BOARD_START_Y 24

void init()
{
    unsigned char i, j, idx;
    SPRITES_8x16;

    set_sprite_data(0, 54, gameTiles);
    SHOW_SPRITES;
    
    idx = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            move_sprite(idx, BOARD_START_X + i * 16, BOARD_START_Y + j * 16);
            idx++;
            move_sprite(idx, BOARD_START_X + 8 + i * 16, BOARD_START_Y + j * 16);
            idx++;
        }
    }

}

void draw_board()
{
    unsigned char i, j, idx;
    idx = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            set_sprite_tile(idx, TILE_GOAT);
            idx++;
            set_sprite_tile(idx, TILE_GOAT + 2);
            idx++;
        }
    }
}

void main(void)
{
    init();

    draw_board();
    while(1) {

    }
}

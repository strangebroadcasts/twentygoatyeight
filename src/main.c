#include <gb/gb.h>
#include <gb/drawing.h>
#include <time.h>

#include "game.h"
#include "tiles.h"

#define BOARD_START_X 56
#define BOARD_START_Y 24

unsigned char board[4][4];

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

    reset_board(board);
    add_piece(board);
    add_piece(board);
}

void draw_board()
{
    unsigned char i, j, idx;
    idx = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            // HACK: flip the grid
            // (should really have consistency between storage
            // and display)
            set_sprite_tile(idx, board[j][i] * 4);
            idx++;
            set_sprite_tile(idx, 2 + board[j][i] * 4);
            idx++;
        }
    }
}

void main(void)
{
    unsigned char pad;
    init();

    while(1) {
        draw_board();
        pad = waitpad(0xff);
        if (pad & J_LEFT) {
            move(board, MOVE_LEFT);
        } else if (pad & J_RIGHT) {
            move(board, MOVE_RIGHT);
        } else if (pad & J_UP) {
            move(board, MOVE_UP);
        } else if (pad & J_DOWN) {
            move(board, MOVE_DOWN);
        }

        waitpadup();
        add_piece(board);
    }
}

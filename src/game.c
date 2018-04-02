#ifndef GAME_H
#include "game.h"
#endif

#ifdef __GNUC__
#include <stdlib.h>
#else
#include <rand.h>
#endif

void shift(unsigned char board[4][4], unsigned char direction)
{
    unsigned char x, y, t;
    for(t = 0; t < 3; t++)
    {
        switch (direction) {
            case MOVE_LEFT:
            for(x = 0; x < 4; x++)
            {
                for(y = 1; y < 4; y++)
                {
                    if(board[x][y-1] == 0)
                    {
                        board[x][y-1] = board[x][y];
                        board[x][y] = 0;
                    }
                }
            }
            break;
            case MOVE_RIGHT:
            for(x = 0; x < 4; x++)
            {
                for(y = 3; y > 0; y--)
                {
                    if(board[x][y] == 0)
                    {
                        board[x][y] = board[x][y-1];
                        board[x][y-1] = 0;
                    }
                }
            }
            break;
            case MOVE_UP:
            for(y = 0; y < 4; y++)
            {
                for(x = 1; x < 4; x++)
                {
                    if(board[x-1][y] == 0)
                    {
                        board[x-1][y] = board[x][y];
                        board[x][y] = 0;
                    }
                }
            }
            
            break;
            case MOVE_DOWN:
            for(y = 0; y < 4; y++)
            {
                for(x = 0; x < 3; x++)
                {
                    if(board[x+1][y] == 0)
                    {
                        board[x+1][y] = board[x][y];
                        board[x][y] = 0;
                    }
                }
            }
            break;
        }
    }
}

void merge(unsigned char board[4][4], unsigned char direction)
{
    unsigned char x, y; 
    switch (direction) {
        case MOVE_LEFT:
        for(x = 0; x < 4; x++)
        {
            for(y = 1; y < 4; y++)
            {
                if(board[x][y-1] == board[x][y] && board[x][y] != 0)
                {
                    board[x][y-1] = board[x][y] + 1;
                    board[x][y] = 0;
                }
            }
        }
        break;
        case MOVE_RIGHT:
        for(x = 0; x < 4; x++)
        {
            for(y = 3; y > 0; y--)
            {
                if(board[x][y] == board[x][y-1] && board[x][y] != 0)
                {
                    board[x][y] = board[x][y-1] + 1;
                    board[x][y-1] = 0;
                }
            }
        }
        break;
        case MOVE_UP:
        for(y = 0; y < 4; y++)
        {
            for(x = 1; x < 4; x++)
            {
                if(board[x-1][y] == board[x][y] && board[x][y] != 0)
                {
                    board[x-1][y] = board[x][y] + 1;
                    board[x][y] = 0;
                }
            }
        }
        
        break;
        case MOVE_DOWN:
        for(y = 0; y < 4; y++)
        {
            for(x = 0; x < 3; x++)
            {
                if(board[x+1][y] == board[x][y] && board[x][y] != 0)
                {
                    board[x+1][y] = board[x][y] + 1;
                    board[x][y] = 0;
                }
            }
        }
        break;
    }
}

void move(unsigned char board[4][4], unsigned char direction)
{
    shift(board, direction);
    merge(board, direction);
    shift(board, direction);
}

void add_piece(unsigned char board[4][4])
{
    // Count the number of available tiles:
    unsigned char i, j, availableTiles, selectedTile;
    availableTiles = 0;
    for(i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if(board[i][j] == 0)
            {
                availableTiles++;
            } 
        }
    }

    if (availableTiles == 0) {
        return;
    }

    selectedTile = (unsigned char)(rand()) % availableTiles;
    for(i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if(board[i][j] != 0)
            {
                continue;
            }

            if(selectedTile == 0)
            {
                board[i][j] = 1;
                return;
            }
            selectedTile--;

        }
    }   
}

void reset(unsigned char board[4][4])
{
    unsigned char i, j;
    for(i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
}

unsigned char game_state(unsigned char board[4][4])
{
    unsigned char i, j;
    for(i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if(board[i][j] >= 11)
            {
                return GAME_WON;
            } 
        }
    }

    return GAME_ONGOING;
}
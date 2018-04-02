#include <stdio.h>
#include <assert.h>

#include "../game.h"

void test_plain_moves();

int boards_same(unsigned char a[4][4], unsigned char b[4][4])
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if(a[i][j] != b[i][j])
            {
                return 0;
            } 
        }
    }
    return 1;
}

void test_plain_move_right() 
{
    printf("Testing movement right...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0}
    };
    unsigned char target[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 1}
    };
    move(board, MOVE_RIGHT);
    assert(boards_same(board, target));
}

void test_plain_move_left() 
{
    printf("Testing movement left...\n");
    unsigned char board[4][4] = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1}
    };
    unsigned char target[4][4] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0}
    };
    move(board, MOVE_LEFT);
    assert(boards_same(board, target));
}

void test_plain_move_up() 
{
    printf("Testing movement up...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1}
    };
    unsigned char target[4][4] = {
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    move(board, MOVE_UP);
    assert(boards_same(board, target));
}

void test_plain_move_down() 
{
    printf("Testing movement down...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    unsigned char target[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 1}
    };
    move(board, MOVE_DOWN);
    assert(boards_same(board, target));
}

void test_merge_left() 
{
    printf("Testing merging left...\n");
    unsigned char board[4][4] = {
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 2, 0, 0}
    };
    unsigned char target[4][4] = {
        {2, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {3, 0, 0, 0}
    };
    move(board, MOVE_LEFT);
    assert(boards_same(board, target));
}

void test_merge_right() 
{
    printf("Testing merging right...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 4, 4}
    };
    unsigned char target[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 2},
        {0, 0, 0, 0},
        {0, 0, 0, 5}
    };
    move(board, MOVE_RIGHT);
    assert(boards_same(board, target));
}

void test_merge_up() 
{
    printf("Testing merging up...\n");
    unsigned char board[4][4] = {
        {0, 4, 0, 1},
        {0, 4, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    unsigned char target[4][4] = {
        {0, 5, 0, 2},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    move(board, MOVE_UP);
    assert(boards_same(board, target));
}

void test_merge_down() 
{
    printf("Testing merging down...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 3, 0, 2},
        {0, 3, 0, 2}
    };
    unsigned char target[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 4, 0, 3}
    };
    move(board, MOVE_DOWN);
    assert(boards_same(board, target));
}

void test_sample_board() 
{
    printf("Testing some sample moves...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 2},
        {0, 3, 0, 2}
    };

    move(board, MOVE_RIGHT);
    unsigned char firstTarget[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 2},
        {0, 0, 3, 2}
    };
    assert(boards_same(board, firstTarget));

    move(board, MOVE_DOWN);
    unsigned char secondTarget[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 3, 3}
    };
    assert(boards_same(board, secondTarget));

    move(board, MOVE_RIGHT);
    unsigned char thirdTarget[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 4}
    };
    assert(boards_same(board, thirdTarget));
}



int main(int argc, char *argv[])
{
    test_plain_move_left();
    test_plain_move_right();
    test_plain_move_up();
    test_plain_move_down();
    test_merge_left();
    test_merge_right();
    test_merge_up();
    test_merge_down();
    test_sample_board();
    printf("All tests complete!\n");
    return 0;
}


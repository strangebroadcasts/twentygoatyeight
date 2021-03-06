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

void test_add_piece_empty() 
{
    printf("Testing adding piece to empty board...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    unsigned char empty[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    add_piece(board);
    assert(!boards_same(board, empty));
}

void test_add_piece_full() 
{
    printf("Testing adding piece to full board...\n");
    unsigned char board[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    unsigned char filled[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    add_piece(board);
    assert(boards_same(board, filled));
}

void test_game_state_checks() 
{
    printf("Testing game state checks...\n");
    // There are open spaces, and the game can proceed:
    unsigned char ongoing[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 3},
        {0, 2, 0, 0},
        {0, 0, 2, 0}
    };
    assert(game_state(ongoing) == GAME_ONGOING);

    // We've hit 2048, and the game is won:
    unsigned char won[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 11},
        {0, 2, 0, 0},
        {0, 0, 2, 0}
    };
    assert(game_state(won) == GAME_WON);

    // No moves are possible, and the game is lost:
    unsigned char lost[4][4] = {
        {1, 2, 1, 2},
        {2, 1, 2, 1},
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };
    assert(game_state(lost) == GAME_LOST);
}

void test_correct_merging_1()
{
    printf("Testing merging edge case #1...\n");
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {2, 0, 0, 0}
    };

    unsigned char target[4][4] = {
        {2, 0, 0, 0},
        {2, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    move(board, MOVE_UP);
    assert(boards_same(board, target));
}

void test_correct_merging_2()
{
    printf("Testing merging edge case #2...\n");
    unsigned char board_down[4][4] = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {2, 0, 0, 0},
        {2, 0, 0, 0}
    };

    unsigned char target_down[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0},
        {3, 0, 0, 0}
    };

    move(board_down, MOVE_DOWN);
    assert(boards_same(board_down, target_down));

    unsigned char board_up[4][4] = {
        {2, 0, 0, 0},
        {2, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };

    unsigned char target_up[4][4] = {
        {3, 0, 0, 0},
        {2, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    move(board_up, MOVE_UP);
    assert(boards_same(board_up, target_up));

    unsigned char board_left[4][4] = {
        {2, 2, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    unsigned char target_left[4][4] = {
        {3, 2, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    move(board_left, MOVE_LEFT);
    assert(boards_same(board_left, target_left));

    unsigned char board_right[4][4] = {
        {1, 1, 2, 2},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    unsigned char target_right[4][4] = {
        {0, 0, 2, 3},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    move(board_right, MOVE_RIGHT);
    assert(boards_same(board_right, target_right));
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
    test_add_piece_empty();
    test_add_piece_full();
    test_game_state_checks();
    test_correct_merging_1();
    test_correct_merging_2();
    printf("All tests complete!\n");
    return 0;
}


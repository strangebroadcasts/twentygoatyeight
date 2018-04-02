#include <stdio.h>
#include <assert.h>

#include "../game.h"

void test_plain_moves();

int main(int argc, char *argv[])
{
    test_plain_moves();
    printf("All tests complete!\n");
    return 0;
}

void test_plain_moves() 
{
    unsigned char board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
}
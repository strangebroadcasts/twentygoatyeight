#define MOVE_LEFT 0
#define MOVE_UP 1
#define MOVE_RIGHT 2
#define MOVE_DOWN 3

#define GAME_ONGOING 0
#define GAME_WON 1
#define GAME_LOST 2

void move(unsigned char board[4][4], unsigned char direction);
void reset_board(unsigned char board[4][4]);
void add_piece(unsigned char board[4][4]);
unsigned char game_state(unsigned char board[4][4]);

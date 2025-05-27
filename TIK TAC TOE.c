#include <stdio.h>

// print the current state of the board
void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
}

//  checks if a player has won
int check_winner(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;     // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;     // Check other diagonal
    return 0;
}

// it checks if the board is full (a draw)
int is_board_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0; // the cell is empty, the board is not full
        }
    }
    return 1; // All cells are filled, the board is full
}

// To play the Tic-Tac-Toe game
void play_tic_tac_toe() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char current_player = 'X';

    while (1) {
        // Print the current state of the board
        print_board(board);

        // turn player's move
        int row, col;
        printf("Enter row: %c: ", current_player);
        scanf("%d", &row);
        printf("Enter column: %c: ", current_player);
        scanf("%d", &col);

        // it Checks if the cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = current_player;

            // Check if the current player wins
            if (check_winner(board, current_player)) {
                print_board(board);
                printf("Player %c wins!\n", current_player);
                break;
            }

            // Check if it's a draw
            if (is_board_full(board)) {
                print_board(board);
                printf("It's a draw!\n");
                break;
            }

            // chance will come to other player for the next one
            current_player = (current_player == 'X') ? 'O' : 'X';
        } else {
            printf("Cell already occupied. Try again.\n");
        }
    }
}
 int main() {
        play_tic_tac_toe();
   return 0;
 }





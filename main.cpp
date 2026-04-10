#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Function prototypes
void drawBoard(const vector < vector < char > > & board);
bool placeMarker(vector < vector < char > > & board, int slot, char marker);
int checkWinner(const vector < vector < char > > & board);
void game();

int main() {
    char replay;
    do {
        game();
        cout << "Game Over! Play again? (y/n): ";
        cin >> replay;
    } while (replay == 'y' || replay == 'Y');

    return 0;
}

void drawBoard(const vector < vector < char > > & board) {
    system ("clear || cls"); // Clears the console for a dynamic feel
    cout << "\n PROFESSIONAL TIC TAC TOE \n\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "-----------" << endl;
    }
    cout << endl;
}

bool placeMarker(vector < vector < char > > & board, int slot, char marker) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = marker;
    return true;
}

int checkWinner(const vector <vector <char > > & board) {
    // Rows and Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

void game() {
    vector < vector < char > > board(3, vector < char > (3));
    board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
    board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
    board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
    char currentMarker = 'X';
    int currentPlayer = 1;
    int winner = 0;

    for (int i = 0; i < 9; i++) {
        drawBoard(board);
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter slot (1-9): ";
        cin >> slot;

        if (!placeMarker(board, slot, currentMarker)) {
            cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }

        winner = checkWinner(board);
        if (winner != 0) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " Wins!\n";
            break;
        }

        // Swap player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }

    if (winner == 0) {
        drawBoard(board);
        cout << "It's a Tie!\n";
    }
}
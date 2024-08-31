#include <iostream>
#include<limits>
using namespace std;

char b[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int r = 0, c = 0;
bool draw = false;

void board() {
    system("cls"); // Clear the console screen
    cout << "\t\t\t\t\t\t\tTIC TAC TOE GAME" << endl;
    cout << "\t\t\t\t\t\t\t****************" << endl;
    cout << "\t\t\t\t\t\t\t  W E L C O M E" << endl;
    cout << "\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~" << endl;
    cout << "Player1 [X]\nPlayer2 [O]\n" << endl;
    cout << "\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << b[0][0] << "  |  " << b[0][1] << "  |  " << b[0][2] << "\n";
    cout << "\t\t\t\t\t\t_____|_____|_____\n";
    cout << "\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << b[1][0] << "  |  " << b[1][1] << "  |  " << b[1][2] << "\n";
    cout << "\t\t\t\t\t\t_____|_____|_____\n";
    cout << "\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << b[2][0] << "  |  " << b[2][1] << "  |  " << b[2][2] << "\n";
    cout << "\t\t\t\t\t\t     |     |     \n";
}

void switchs() {
    int choice;
    bool validInput = false;

    while (!validInput) {
        if (turn == 'X') {
            cout << "Player 1 [X] turn: ";
        } else if (turn == 'O') {
            cout << "Player 2 [O] turn: ";
        }

        cin >> choice;

        if (cin.fail()) { // Check if input is not an integer
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Please enter a valid number (1-9)\n";
            continue;
        }

        if (choice >= 1 && choice <= 9) {
            validInput = true;
        } else {
            cout << "Please enter a valid choice (1-9)\n";
            continue;
        }

        switch (choice) {
            case 1: r = 0; c = 0; break;
            case 2: r = 0; c = 1; break;
            case 3: r = 0; c = 2; break;
            case 4: r = 1; c = 0; break;
            case 5: r = 1; c = 1; break;
            case 6: r = 1; c = 2; break;
            case 7: r = 2; c = 0; break;
            case 8: r = 2; c = 1; break;
            case 9: r = 2; c = 2; break;
        }

        if (b[r][c] != 'X' && b[r][c] != 'O') {
            b[r][c] = turn;
            turn = (turn == 'X') ? 'O' : 'X';
        } else {
            cout << "Box already filled! Please choose another.\n";
            validInput = false; // Prompt again if the chosen box is already filled
        }
    }

    board();
}

bool gameover() {
    // Check for a win
    for (int i = 0; i < 3; i++) {
        if ((b[i][0] == b[i][1] && b[i][0] == b[i][2]) || (b[0][i] == b[1][i] && b[0][i] == b[2][i])) {
            return false;
        }
    }
    if ((b[0][0] == b[1][1] && b[0][0] == b[2][2]) || (b[0][2] == b[1][1] && b[0][2] == b[2][0])) {
        return false;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] != 'X' && b[i][j] != 'O') {
                return true;
            }
        }
    }

    draw = true;
    return false;
}

int main() {
    while (gameover()) {
        board();
        switchs();
    }

    if (turn == 'X' && !draw) {
        cout << "Player 2 [O] WINS THE GAME!!!" << endl;
    } else if (turn == 'O' && !draw) {
        cout << "Player 1 [X] WINS THE GAME!!!" << endl;
    } else {
        cout << "Game DRAW!!!" << endl;
    }

    return 0;
}


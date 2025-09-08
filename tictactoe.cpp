#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>  // for numeric_limits used in I/O validation

bool isWin(char game[3][3]){
    bool win = false;
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    // column
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    // diagonal
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    return win;
}

int  main(){
    int i, j;
    char game[3][3] = {' '}; // Tic-tac-toe
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    bool won = false; //whether someone has won
    
    std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;
    for (int n=0; n<9; n++){
            turn = !turn;  // use the not-operator to change true to false or false to true.

            // ===== I/O fixes start =====
            // Robust prompt, input validation, 1-based -> 0-based conversion, range & occupancy checks.
            while (true) {
                if (turn == false)
                    std::cout << "Player 1: ";
                else
                    std::cout << "Player 2: ";
                std::cout << "Which cell to mark? i:[1..3], j:[1..3]: ";

                int ui, uj;
                if (!(std::cin >> ui >> uj)) { // handle non-numeric input
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter two integers in 1..3.\n";
                    continue;
                }

                i = ui - 1;  // convert to 0..2
                j = uj - 1;

                if (i < 0 || i > 2 || j < 0 || j > 2) {
                    std::cout << "Out of range. Indices must be 1..3.\n";
                    continue;
                }
                if (game[i][j] == 'X' || game[i][j] == 'O') {
                    std::cout << "Cell occupied. Choose another.\n";
                    continue;
                }
                break; // valid input and free cell
            }
            // ===== I/O fixes end =====

            if (turn == false)
               game[i][j] = 'X';
            else 
               game[i][j] = 'O';
            if (isWin(game)){
                std::cout << "Win!" << std::endl;
                won = true; //someone has won
                break; // need to terminate the problem
            }
        }
    //if after 9 steps there is nobody win
    if (!won) {
       std::cout << "Tie!" << std::endl;
    }

    // show the game to console
    std::cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << std::endl;
    std::cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << std::endl;
    std::cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << std::endl;
    return 1;
}
#include "tictactoe.h"

int main() {
    TicTacToe game;
    char player1Symbol;
    char player2Symbol;
    char ip;
    int row, col;

    std::cout << "Player 1, select your Symbol: ";
    std::cin >> player1Symbol;
    if(player1Symbol != 'X' && player1Symbol != 'O') {
        std::cout << "Invalid symbol! Defaulting to 'X'." << std::endl;
        player1Symbol = 'X'; // Default symbol if input is invalid
    }

    player2Symbol = (player1Symbol == 'X') ? 'O' : 'X'; // Automatically assign the other symbol

    std::cout << "Player 1, your Symbol is: " << player1Symbol << std::endl;
    std::cout << "Player 2, your Symbol is: " << player2Symbol << std::endl;

    while(!game.checkWin(player1Symbol) && !game.checkWin(player2Symbol) && !game.isBoardFull()) {
        std::cout << "Player 1, enter your move: ";
        std::cin >> ip;

        game.getRowCol(ip, row, col);

        if(game.makeMove(row, col, player1Symbol)) {
            game.displayBoard();
            if(game.checkWin(player1Symbol)) {
                char choice;
                std::cout << "Player 1 wins!" << std::endl;
                std::cout << "Do you want to play again? (y/n): ";
                std::cin >> choice;
                if(choice == 'y' || choice == 'Y') {
                    game.resetGame();
                    continue; // Restart the loop for a new game
                }
                else{
                    std::cout << "Thanks for playing!" << std::endl;
                    return 0; // Exit the game
                }
            }
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
            continue; // Skip to next iteration for valid input
        }

        if(game.isBoardFull()) {
            char choice;
            std::cout << "The game is a draw!" << std::endl;
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> choice;
            if(choice == 'y' || choice == 'Y') {
                game.resetGame();
                continue; // Restart the loop for a new game
            }
            else {
                std::cout << "Thanks for playing!" << std::endl;
                return 0; // Exit the game
            }
        }

        std::cout << "Player 2, enter your move: ";
        std::cin >> ip;
        
        game.getRowCol(ip, row, col);

        if(game.makeMove(row, col, player2Symbol)) {
            game.displayBoard();
            if(game.checkWin(player2Symbol)) {
                char choice;
                std::cout << "Player 2 wins!" << std::endl;
                std::cout << "Do you want to play again? (y/n): ";
                std::cin >> choice;
                if(choice == 'y' || choice == 'Y') {
                    game.resetGame();
                    continue; // Restart the loop for a new game
                }
                else{
                    std::cout << "Thanks for playing!" << std::endl;
                    return 0; // Exit the game
                }
            }
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
            continue; // Skip to next iteration for valid input
        }

        if(game.isBoardFull()) {
            std::cout << "The game is a draw!" << std::endl;
            return 0;
        }
    }
    return 0;
}
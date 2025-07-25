#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <stdlib.h>

class TicTacToe {
    private:
        std::vector<std::vector<char>> board;
        const int size = 3; // Size of the Tic Tac Toe board
        int count = 0; // Counter for the board initialization
        void initializeBoard(){
            clearScreen();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    std::cout << i + j + 1 + count;
                    if (j < size - 1) std::cout << "|";
                }
                std::cout << std::endl;
                if (i < size - 1) {
                    for (int k = 0; k < size * 2 - 1; ++k) {
                        std::cout << "-";
                    }
                    std::cout << std::endl;
                }
                count+= size - 1;
            }
            std::cout << "\nPlease remember the numbers above as they represent the positions on the board." << std::endl;
            board.resize(size, std::vector<char>(size, ' ')); // Initialize the board with empty spaces
        }
        bool isValidMove(int row, int col){
            return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ';
        }
        void clearScreen(){
            system("clear || cls"); // Clear the console screen
            std::cout << "---------------------------" << std::endl;
            std::cout << "        Tic Tac Toe        " << std::endl;
            std::cout << "    Created by DarkulaX    " << std::endl;
            std::cout << "   Modified on 25/7/2025   " << std::endl;
            std::cout << "---------------------------" << std::endl;
        }
    public:
        TicTacToe(){
            initializeBoard();
        }
        void displayBoard(){
            clearScreen();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    std::cout << board[i][j];
                    if (j < size - 1) std::cout << "|";
                }
                std::cout << std::endl;
                if (i < size - 1) {
                    for (int k = 0; k < size * 2 - 1; ++k) {
                        std::cout << "-";
                    }
                    std::cout << std::endl;
                }
            }
            count = 1;
            std::cout << std::endl; 
        }
        bool makeMove(int row, int col, char player){
            if (isValidMove(row, col)) {
                board[row][col] = player;
                return true;
            }
            return false;
        }
        bool checkWin(char player) {
            if(board[0][0] == player && board[0][1] == player && board[0][2] == player) return true; // Row 1
            if(board[1][0] == player && board[1][1] == player && board[1][2] == player) return true; // Row 2
            if(board[2][0] == player && board[2][1] == player && board[2][2] == player) return true; // Row 3
            if(board[0][0] == player && board[1][0] == player && board[2][0] == player) return true; // Column 1
            if(board[0][1] == player && board[1][1] == player && board[2][1] == player) return true; // Column 2
            if(board[0][2] == player && board[1][2] == player && board[2][2] == player) return true; // Column 3
            if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal 1
            if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal 2
            return false;
        }
        bool isBoardFull() {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[i][j] == ' ') {
                        return false; // Found an empty space
                    }
                }
            }
            return true; // No empty spaces found
        }
        void resetGame(){
            initializeBoard();
            displayBoard();
        }
        void getRowCol(char ip, int &row, int &col) {
            switch (ip)
            {
                case '1':
                    row = 0; col = 0;
                    break;
                case '2':
                    row = 0; col = 1;
                    break;
                case '3':
                    row = 0; col = 2;
                    break;
                case '4':
                    row = 1; col = 0;
                    break;
                case '5':
                    row = 1; col = 1;
                    break;
                case '6':
                    row = 1; col = 2;
                    break;
                case '7':
                    row = 2; col = 0;
                    break;
                case '8':
                    row = 2; col = 1;
                    break;
                case '9':
                    row = 2; col = 2;
                    break;
                default:
                    break;
            }
        }
};

#endif // TICTACTOE_H
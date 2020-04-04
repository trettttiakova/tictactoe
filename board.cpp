//
// Created by Zoe Tretiakova on 2020-04-04.
//

#include "board.h"

board::board(int size) {
    this->size = size;

    //  initialize board
    for (int i = 0; i < size; i++) {
        brd.emplace_back();
        for (int j = 0; j < size; j++) {
            brd[i].push_back('.');
        }
    }

    //  initialize counters
    for (int i = 0; i < 2; i++) {
        vertical_cnt.emplace_back();
        horizontal_cnt.emplace_back();
        for (int j = 0; j < size; j++) {
            vertical_cnt[i].push_back(0);
            horizontal_cnt[i].push_back(0);
        }
    }
}

bool board::set(int x, int y, char character) {
    if (x >= size || y >= size || brd[x][y] != '.') {
        return false;
    }
    brd[x][y] = character;
    vertical_cnt[character == 'x' ? 0 : 1][x]++;
    horizontal_cnt[character == 'x' ? 0 : 1][y]++;
    return true;
}

bool board::check(char character) {
    for (int value : vertical_cnt[character == 'x' ? 0 : 1]) {
        if (value == size) {
            return true;
        }
    }
    for (int value : horizontal_cnt[character == 'x' ? 0 : 1]) {
        if (value == size) {
            return true;
        }
    }
    //  check diagonals
    bool diagonal = true;
    for (int i = 0; i < size; i++) {
        if (brd[i][i] != character) {
            diagonal = false;
            break;
        }
    }
    if (diagonal) {
        return true;
    }
    diagonal = true;
    for (int i = 0; i < size; i++) {
        if (brd[i][size - 1 - i] != character) {
            diagonal = false;
            break;
        }
    }
    return diagonal;

}

void board::show() {
    std::cout << "   ";
    for (int j = 0; j < size; j++) {
        std::cout << "   " << j + 1 << "  ";
    }
    std::cout << '\n';
    std::cout << "   ";
    for (int j = 0; j < size; j++) {
        std::cout << " _____";
    }
    std::cout << '\n';
    for (int i = 0; i < size; i++) {
        std::cout << "   ";
        for (int j = 0; j < size; j++) {
            std::cout << "|     ";
        }
        std::cout << "|\n";
        std::cout << i + 1 << "  ";
        for (int j = 0; j < size; j++) {
            std::cout << "|  " << (brd[i][j] == '.' ? ' ' : brd[i][j]) << "  ";
        }
        std::cout << "|\n";
        std::cout << "   ";
        for (int j = 0; j < size; j++) {
            std::cout << "|_____";
        }
        std::cout << "|\n";
    }
}

std::vector<std::pair<int, int>> board::free_cells() {
    std::vector<std::pair<int, int>> cells;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (brd[i][j] == '.') {
                cells.emplace_back(i, j);
            }
        }
    }
    return cells;
}

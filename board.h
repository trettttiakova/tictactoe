//
// Created by Zoe Tretiakova on 2020-04-04.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <iostream>
#include <vector>

class board {
private:
    int size;
    std::vector<std::vector<char>> brd;
    std::vector<std::vector<int>> vertical_cnt, horizontal_cnt;
public:
    board() : board(3) {};
    board(int size);
    bool set(int x, int y, char character);
    bool check(char character);
    void show();
};


#endif //TICTACTOE_BOARD_H

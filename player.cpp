//
// Created by Zoe Tretiakova on 2020-04-04.
//

#include "player.h"

player::player(char character) {
    this->character = character;
}

void player::move(board *brd) {
    int x, y;
    std::cout << "(" << character << ") Your move:\n";
    std::cin >> x >> y;
    x--;
    y--;
    while (!brd->set(x, y, character)) {
        std::cout << "Wrong input, please try again.\n";
        std::cout << "Your move:\n";
        std::cin >> x >> y;
        x--;
        y--;
    }
}

char player::get_character() {
    return character;
}

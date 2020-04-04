//
// Created by Zoe Tretiakova on 2020-04-04.
//

#include "player.h"

player::player(char character) {
    this->character = character;
}

void player::move(board *brd) {
    if (bot) {
        std::vector<std::pair<int, int>> free_cells = brd->free_cells();
        int random_decision = rand() % free_cells.size();
        brd->set(free_cells[random_decision].first,
                 free_cells[random_decision].second,
                 this->get_character());
    }
    else {
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
}

char player::get_character() {
    return character;
}

void player::set_bot() {
    srand(time(0));
    bot = true;
}

//
// Created by Zoe Tretiakova on 2020-04-04.
//

#include "game.h"

void game::start() {
    out.open("results.out");
    int input;
    std::cout << "Send me the size of the board (send 0 or less if you want to stop):\n";
    std::cin >> input;
    while (input > 0) {
        round(input);
        std::cout << "Send me the size of the board (send 0 or less if you want to stop):\n";
        std::cin >> input;
    }

    out.close();
}

void game::round(int size) {
    board brd = board(size);
    player current_player = player1;
    player next_player = player2;
    while (true) {
        brd.show();
        current_player.move(&brd);
        if (brd.check(current_player.get_character())) {
            brd.show();
            std::cout << "***** WE HAVE A WINNER! ***** \n" << current_player.get_character() << " wins!\n\n";
            out << current_player.get_character() << " wins!\n";
            break;
        }
        std::swap(current_player, next_player);
    }
}

//
// Created by Zoe Tretiakova on 2020-04-04.
//

#include "game.h"

void game::start() {
    int input;
    std::cout << "Type 1 if you have a second player,\nType 0 if you need a bot:\n";
    std::cin >> input;
    while (input < 0 || input > 1) {
        std::cout << "Wring format :( try again.\nType 1 if ypu have a second player,\nType 0 if you need a bot:\n";
        std::cin >> input;
    }
    if (input == 0) {
        player2.set_bot();
    }

    out.open("results.out");

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

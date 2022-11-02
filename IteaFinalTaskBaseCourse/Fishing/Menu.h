#pragma once

#include <iostream>


class Menu {
public:

    enum mainMenu {
        Catching = 1,
        ChangeWater,
        ChangeBait,
        CheckCurrentCatch,
        EndOfFishing
    };

public:
    static void choiseMenu( Game& game, int& choise ) {
        std::cout << std::endl << "Choose, what you want to do next: " << std::endl;
        std::cout << "1 - Continue the fishing" << std::endl;
        std::cout << "2 - Change water to other" << std::endl;
        std::cout << "3 - Change bait to other" << std::endl;
        std::cout << "4 - Check your current catch" << std::endl;
        std::cout << "5 - Finish the fishing" << std::endl;
        std::cin >> choise;
        while( true ) {
            switch( choise ) {
                case Catching:
                    game.catching();
                    return;
                case ChangeWater:
                    game.chooseWater();
                    return;
                case ChangeBait:
                    game.chooseBait();
                    return;
                case CheckCurrentCatch:
                    game.checkCurrentCatch();
                    return;
                case EndOfFishing:
                    return;
                default:
                    std::cout << "You enter wront number! Please try again!" << std::endl;
                    break;
            }
        }

    }
};

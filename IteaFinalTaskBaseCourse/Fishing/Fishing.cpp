#include <iostream>
#include <string>
#include <chrono>

#include "ReadFromFile.h"
#include "Game.h"
#include "Menu.h"
#include "WriteToFile.h"
#include "StructData.h"

int main() {
    srand( time( nullptr ) );
    int timeOfGame {};

    DataFish dataFish;
    DataWater dataWater;
    DataBait dataBait;

    ReadFromFile::readFishFromFile( dataFish );
    ReadFromFile::readBaitFromFile( dataBait );
    ReadFromFile::readWaterFromFile( dataWater );

    Game game( dataFish, dataWater, dataBait );
    int choise {};


    game.catching();

    do {
        auto begin { std::chrono::steady_clock::now() };

        Menu::choiseMenu( game, choise );

        timeOfGame += std::chrono::duration_cast< std::chrono::minutes >( std::chrono::steady_clock::now() - begin ).count();

    } while( choise != static_cast< int > ( Menu::EndOfFishing ) && game.getCurrentFishWeight() <= game.getPaidFishWeight() && timeOfGame < game.getCurrentFishingTime() );


    std::cout << std::endl << "Your fishing is finished!" << std::endl << std::endl;
    game.checkCurrentCatch();
    WriteToFile::writeToFile( "Data\\Result.txt", game.getCurrentCatch() );

    return 0;
}

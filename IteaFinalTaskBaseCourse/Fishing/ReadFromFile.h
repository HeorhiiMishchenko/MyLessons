#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <optional>
#include <sstream>
#include "StructData.h"

class ReadFromFile {
private:
    static std::optional <std::vector<std::string>> readFromFile( const std::string path );
    static std::optional <std::vector<std::string>> split( const std::string str, int numberOfParameters, char separator = ' ' );

public:
    static void readFishFromFile( DataFish& fish );
    static void readWaterFromFile( DataWater& water );
    static void readBaitFromFile( DataBait& bait );
};


std::optional <std::vector<std::string>> ReadFromFile::readFromFile( const std::string path ) {
    std::vector <std::string> result;
    std::string currentLine {};

    std::ifstream myFile { path };
    if( !myFile.is_open() )
        return std::nullopt;

    while( std::getline( myFile, currentLine ) )
        result.push_back( currentLine );

    return result;
}

std::optional <std::vector<std::string>> ReadFromFile::split( const std::string str, int numberOfParameters, char separator ) {
    std::vector <std::string> result;
    std::vector <std::string> split;
    std::stringstream ss { str };
    std::string item;
    while( std::getline( ss, item, separator ) )
        result.push_back( item );

    if( result.size() != numberOfParameters )
        return std::nullopt;

    return result;
}

void ReadFromFile::readFishFromFile( DataFish& fish ) {
    auto fileData { readFromFile( "Data\\Fish.txt" ) };
    int numberOfParameters { 3 };
    if( fileData != std::nullopt ) {
        auto crucianData { split( fileData.value()[0],numberOfParameters ) };
        fish.crucian.setFishName( crucianData.value()[0] );
        fish.crucian.setMinMaxFishWeight( std::stoi( crucianData.value()[1] ), std::stoi( crucianData.value()[2] ) );

        auto perchData { split( fileData.value()[1],numberOfParameters ) };
        fish.perch.setFishName( perchData.value()[0] );
        fish.perch.setMinMaxFishWeight( std::stoi( perchData.value()[1] ), std::stoi( perchData.value()[2] ) );

        auto pikeData { split( fileData.value()[2],numberOfParameters ) };
        fish.pike.setFishName( pikeData.value()[0] );
        fish.pike.setMinMaxFishWeight( std::stoi( pikeData.value()[1] ), std::stoi( pikeData.value()[2] ) );
    } else {
        std::cout << "Cant read file!" << std::endl;
        system( "pause" );
    }
}

void ReadFromFile::readWaterFromFile( DataWater& water ) {
    auto fileData { readFromFile( "Data\\Water.txt" ) };
    int numberOfParameters { 2 };
    if( fileData != std::nullopt ) {
        auto riverData { split( fileData.value()[0],numberOfParameters ) };
        water.river.setWaterName( riverData.value()[0] );
        water.river.setcatchingFishChance( std::stoi( riverData.value()[1] ) );

        auto lakeData { split( fileData.value()[1],numberOfParameters ) };
        water.lake.setWaterName( lakeData.value()[0] );
        water.lake.setcatchingFishChance( std::stoi( lakeData.value()[1] ) );

        auto reservoirData { split( fileData.value()[2] ,numberOfParameters ) };
        water.reservoir.setWaterName( reservoirData.value()[0] );
        water.reservoir.setcatchingFishChance( std::stoi( reservoirData.value()[1] ) );

    } else {
        std::cout << "Cant read file!" << std::endl;
        system( "pause" );
    }
}

void ReadFromFile::readBaitFromFile( DataBait& bait ) {
    auto fileData { readFromFile( "Data\\Bait.txt" ) };
    int numberOfParameters { 2 };
    if( fileData != std::nullopt ) {
        auto bloodwormData { split( fileData.value()[0],numberOfParameters ) };
        bait.bloodworm.setBaitName( bloodwormData.value()[0] );
        bait.bloodworm.setCatchBonus( stoi( bloodwormData.value()[1] ) );

        auto earthwormData { split( fileData.value()[1],numberOfParameters ) };
        bait.earthworm.setBaitName( earthwormData.value()[0] );
        bait.earthworm.setCatchBonus( stoi( earthwormData.value()[1] ) );

        auto maggotData { split( fileData.value()[2],numberOfParameters ) };
        bait.maggot.setBaitName( maggotData.value()[0] );
        bait.maggot.setCatchBonus( stoi( maggotData.value()[1] ) );

    } else {
        std::cout << "Cant read file!" << std::endl;
        system( "pause" );
    }
}


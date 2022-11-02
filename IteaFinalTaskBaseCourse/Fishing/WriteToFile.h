#pragma once

#include <fstream>
#include <iostream>
#include <vector>

class WriteToFile {
public:

    static void writeToFile( const std::string& path, const std::vector<std::pair <int, std::string>>& data ) {
        std::ofstream outFile { path, std::ios::app };

        if( !outFile.is_open() )
            std::cout << "Can't open file!" << std::endl;

        for( auto& values : data ) {
            outFile << values.second << ", " << values.first << " kilograms" << std::endl;
        }

        outFile.close();
    }
};

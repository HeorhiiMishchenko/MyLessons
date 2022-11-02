#include <iostream>

int main()
{
    int rows{};                                             //init number of rows of the pyramid 
    char symbol{};                                          //init symbol of drawing

    std::cout << "Enter number of rows: ";                  
    std::cin >> rows;                                       //request for the number of rows
    std::cout << "Enter a symbol for drawing: ";            
    std::cin >> symbol;                                     //request for symbol for drawing

    for (int i{1}; i <= rows; i++)                          //drawing
    {
        for (int j{0}; j < rows; j++)                       //cycle drawing a pyramid to the left of the middle
        {
            if(i < rows - j)
                std::cout << " ";
            else
                std::cout << symbol; 
        }
        for (int k{ rows }; k < rows*2; k++)                //cycle drawing a pyramid to the right of the middle
        {
            if( rows + i > k )
                std::cout << symbol; 
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

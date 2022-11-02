#include <iostream>
#include <cstdlib>

int getNumber( int min, int count ) //get random number function
{
    return min + rand() % count;
}

int nameOfMinValue( int array[], int size ) //getting the name of the element with the minimum value
{
    int minValue = array[0];
    int nameOfMinValue {};

    for( int i { 1 }; i < size; i++ ) {
        if( array[i] < minValue ) {
            minValue = array[i];
            nameOfMinValue = i;
        }
    }
    return nameOfMinValue;
}

int nameOfMaxValue( int array[], int size ) //getting the name of the element with the maximum value
{
    int maxValue = array[0];
    int nameOfMaxValue {};

    for( int i { 1 }; i < size; i++ ) {
        if( array[i] > maxValue ) {
            maxValue = array[i];
            nameOfMaxValue = i;
        }
    }
    return nameOfMaxValue;
}

int main() {
    const int throws { 100 }; //number of rolls of the dice
    int sides[6] {}; //number of sides of a dice

    srand( time( nullptr ) );

    for( int i {}; i < throws; i++ )  //dice rolls and counting the number of hits on each side
    {
        switch( getNumber( 1, 6 ) ) {
            case 1:
                sides[0]++;
                break;
            case 2:
                sides[1]++;
                break;
            case 3:
                sides[2]++;
                break;
            case 4:
                sides[3]++;
                break;
            case 5:
                sides[4]++;
                break;
            case 6:
                sides[5]++;
                break;
            default:
                std::cout << "Program fault";
                return 0;
                break;
        }
    }

    //displaying the number of hits on each side
    const auto sideSize { 6 };
    for( int i {}; i < sideSize; i++ )
        std::cout << "Number of dropouts side " << i + 1 << " is " << sides[i] << std::endl;

    //Search and display the side that fell out most often
    std::cout << "Side " << nameOfMaxValue( sides, sizeof( sides ) / sizeof( int ) ) + 1 << " rolled the most times" << std::endl;

    //Finding and displaying the side that fell out the least
    std::cout << "Side " << nameOfMinValue( sides, sizeof( sides ) / sizeof( int ) ) + 1 << " rolled the fewest times" << std::endl;

    return 0;
}

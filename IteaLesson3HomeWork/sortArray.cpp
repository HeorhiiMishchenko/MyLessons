#include <iostream>

void sortArray( int* array, int size ) // function "bubble sort"
{
    bool swapped {};
    do {
        swapped = false;

        for( int i = 1; i < size; i++ ) {
            if( *( array + i - 1 ) > *( array + i ) ) {
                std::swap( *( array + i - 1 ), *( array + i ) );
                swapped = true;
            }
        }
    } while( swapped != false );
}
int main() {
    const int sizeArray = 10;                   // init size of array
    int testArray[sizeArray] {};                 // init array

    for( int i {}; i < sizeArray; i++ )           // filling an array with numbers
        std::cin >> *( testArray + i );

    sortArray( testArray, sizeArray );            // call sort array function

    for( int i {}; i < sizeArray; i++ )           // sorted array output to console
        std::cout << *( testArray + i ) << " ";
}
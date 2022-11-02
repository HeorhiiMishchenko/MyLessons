#include "Vector.h"

void testVector() {
    Vector vector{ 10 };

    srand(time(nullptr));                                               
    auto arrayFilling = [&](const int& number) {                              //fill the vector with random values
        for (int i{}; i < number; i++) {
            vector.pushBack(rand() % 100);
        }
    };
    
    vector.printVector();
    vector.clear();
    std::cout << "Size of vector is " << vector.size() << std::endl;

    //checking methods when the vector size is zero
    //-------------------------------------------------
    vector.printVector();
    vector.sort();
    vector.swap(1, 2);
    vector.append(568, 2);
    std::cout << "-----------------------------------------------------------------\n";
    //-------------------------------------------------

    //checking methods for a non-zero vector size
    //-------------------------------------------------
    arrayFilling(4);
    std::cout << "Size of vector is " << vector.size() << std::endl;
    vector.printVector();
    vector.resize(8);
    vector.printVector();
    vector.resize(2);
    vector.printVector();
    arrayFilling(8);
    vector.printVector();
    std::cout << vector.min() << std::endl;
    std::cout << vector.max() << std::endl;
    std::cout << vector.front() << std::endl;
    std::cout << vector.back() << std::endl;
    vector.sort();
    vector.printVector();
    std::cout << "Size of vector is " << vector.size() << std::endl;
    vector.swap(0, 15);
    vector.printVector();
    vector.swap(0, 9);
    vector.printVector();
    vector.append(12321, 15);
    vector.printVector();
    vector.append(12321, 5);
    vector.printVector();
}

int main() {
    testVector();
}

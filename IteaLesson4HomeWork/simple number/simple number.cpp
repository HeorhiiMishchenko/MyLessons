#include <iostream>
#include <math.h>

void searchSimpleNumber(int number)
{
    if (number <= 0)                                                            //checking if a number is natural
    {
        std::cout << "You entered not a natural number!" << std::endl;
        return;
    }
    if (number == 1)                                                            //checking that a number is one
    {
        std::cout << "1 belongs to the special category \"one\"" << std::endl;
        return;
    } 
    for (int i{ 2 }; i <= static_cast <int>(sqrt(number)); i++)             //checking a number for simplicity. divisor search algorithm
    {
        if (number % i == 0)
        {
            std::cout << number << " is a composite number" << std::endl;
            return;
        }
    }
    std::cout << number << " is a simple number" << std::endl;                    //conclusion that a number is simple
}

int main()
{
    int number{};

    std::cout << "Enter a natural number you want to check: ";
    std::cin >> number;

    searchSimpleNumber(number);

    return 0;
}

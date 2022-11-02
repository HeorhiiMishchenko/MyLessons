#include <iostream>

long factorial(int number) //factorial function
{
    int result{1};

    if (number <= 1)
        return result;
    else
        while (number > 0)
        {
            result *= number;
            number--;
        }
    return result;
}

int main()
{
    int number{};

    std::cout << "Enter a non-negative number for which you want to calculate the factorial: ";
    std::cin >> number;
    if (number >= 0)                                                                           //check that a non-negative number is entered
        std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;    //output factorial for the requested number
    else
        std::cout << "You entered a negative number!" << std::endl;                            //output a message that a negative number is entered

    return 0;
}

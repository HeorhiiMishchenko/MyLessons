#include <iostream>

int factorial(int number) //factorial function
{
    if (number <= 1)
        return 1;
    else
        return number * factorial(number - 1);  
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

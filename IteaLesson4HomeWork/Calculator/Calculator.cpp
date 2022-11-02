#include <iostream>
#include <cmath>

inline void addition(double temp1, double temp2)                                //addition function
{
    std::cout << "Result is " << temp1 + temp2 << std::endl;
}

inline void subtraction(double temp1, double temp2)                             //subtraction function
{
    std::cout << "Result is " << temp1 - temp2 << std::endl;
}

inline void multiplication(double temp1, double temp2)                          //multiplication function
{
    std::cout << "Result is " << temp1 * temp2 << std::endl;
}

inline void division(double temp1, double temp2)                                //division function
{
    if (temp2 != 0)
        std::cout << "Result is " << temp1 / temp2 << std::endl;
    else std::cout << "Division by zero is not allowed!";
}

inline void exponentiation(double temp1, double temp2)                          //exponentiation function
{
    std::cout << "Result is " << pow(temp1, temp2) << std::endl;
}


int main()
{
    double temp1{};                                                 //init first temp
    double temp2{};                                                 //init second temp
    char mathOperator{};                                            //init math operator 

    std::cout << "Enter expression" << std::endl;
    std::cin >> temp1 >> mathOperator >> temp2;                     //request to enter a mathematical expression (+, -, *, /, ^)

   switch (mathOperator)                                            //choice of mathematical operation
    {
   case '+':
        addition(temp1, temp2);
        break;
    case '-':
        subtraction(temp1, temp2);
        break;
    case '*':
        multiplication(temp1, temp2);
        break;
    case '/':
        division(temp1, temp2);
        break;
    case '^':
        exponentiation(temp1, temp2);
        break;
    default: std::cout << "You entered wrong expression!";          //error if an unsupported math operator is entered
        break;
    }

   return 0;
}

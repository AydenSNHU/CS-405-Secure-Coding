// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct CustomException : public std::exception {
    virtual const char* what() const throw()
    {
        return "This is a custom exception. Dial 867-5309 with any issues you might have with it\n";
    } // the making of my custom exception
};

bool do_even_more_custom_application_logic()
{
    
    
    // TODO: Throw any standard exception
    

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    throw std::bad_exception(); // just throwing a standard exception here

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try
    {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
        // try catch block as an exception handler
    }
    catch (std::exception& exception)
    {
        std::cerr << "Exception caught in do_even_more_custom_application_logic: " << exception.what() << std::endl;
    } // reporting where it was caught from, and giving the message of the exception

    throw CustomException(); // throwing my custom exception

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0)
        throw std::runtime_error("Divide by zero runtime error");
    // throwing a runtime error because you can't divide by zero, silly
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    } // another try catch, for catching runtime error from dodivision
    catch (std::runtime_error& exception) {
        std::cout << "Exception caught by do_division: " << exception.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.

    try {
        do_division();
    } // catching errors from dodivision
    catch (std::runtime_error& exception) {
        std::cout << "Caught in main: " << exception.what() << std::endl;
    }

    try {
        do_custom_application_logic();
    } // catching errors from customapplicationlogic
    catch (std::exception& exception) {
        std::cout << "Caught in main: " << exception.what() << std::endl;
    } // just need one block because the custom exception is derived from the std::exception
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
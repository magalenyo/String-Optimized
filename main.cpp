// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "String.h"

int main()
{
    String* test = new String();
    test = new String("How's it going");
    test->print();
    delete test;

    String* stringA = new String("Hi, I'm a string");
    String* stringB = new String(*stringA);
    stringB->print();

    String* stringConcatA = new String("This is a");
    String* stringConcatB = new String("new concat string");
    String* result = *stringConcatA + *stringConcatB;
    result->print();
    std::cout << result->length() << std::endl;

    String* firstIf = new String("hellohello");
    String* secondIf = new String("hellohello ");
    if (*firstIf == *secondIf) {
        std::cout << "Strings are the same" << std::endl;
    }
    else {
        std::cout << "Strings are NOT the same" << std::endl;
    }

    String* firstIfSecondTry = new String("hellohello");
    if (*firstIfSecondTry == "hellohello") {         // como puede ser que me est� pillando el primer operador!?!?!?!?
        std::cout << "Strings are the same" << std::endl;
    }
    else {
        std::cout << "Strings are NOT the same" << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

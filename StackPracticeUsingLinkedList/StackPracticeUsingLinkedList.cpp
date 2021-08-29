// StackPracticeUsingLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"

int main()
{
    Stack* stack = new Stack(1); // 1 ; length:1
    stack->PrintPeakValue(); // should print 1
    stack->Push(2); // 1 --> 2;  length: 2
    stack->Push(3); // 1 --> 2 --> 3; length: 3 
    stack->Print(); // should print 1 --> 2 --> 3; length: 3 
    stack->Pop(); // 1 --> 2 ; length:2
    stack->PrintPeakValue(); // should print 2
    stack->Print(); // sould print 1 --> 2 ; length 2;
}




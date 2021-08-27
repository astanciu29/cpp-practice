// LinkedListPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList* linkedList = new LinkedList(5); // 5 ; length = 1
    linkedList->Append(3); // 5 --> 3; length = 2
    linkedList->Preppend(1); // 1 --> 5 --> 3; length = 3
    linkedList->Print(); // should print 1 --> 5 --> 3 ; length = 3
    linkedList->Remove(20); //should print error - The index you are trying to remove does not exist!
    linkedList->Remove(-20); //should print error - The index you are trying to remove is not a positive number!
    linkedList->Append(-3); // 1 --> 5 --> 3 -->-3 ;length = 4
    linkedList->Append(34); //1 --> 5 --> 3 -->-3 --> 34 ; length = 5
    linkedList->Remove(1); // 5 --> 3 -->-3 --> 34 ; length = 4
    linkedList->Remove(3); // 5 --> 3 --> 34 ; length = 3
    linkedList->Print(); // should print  5 --> 3 --> 34  ; length = 3
    linkedList->Insert(1, 0); // 0 --> 5 --> 3 --> 34 ; length = 4
    linkedList->Insert(3, 2); // 0 --> 5 -->2 --> 3 --> 34 ; length = 5
    linkedList->Insert(5, 100); // 0 --> 5 -->2 --> 3 --> 100 --> 34; length = 6
    linkedList->Insert(50, 101); // 0 --> 5 -->2 --> 3 --> 100 --> 34 -->101; length = 7
    linkedList->Remove(6); // 0 --> 5 -->2 --> 3 --> 100  -->101; length = 6
    linkedList->Remove(2); // 0  -->2 --> 3 --> 100  -->101; length = 5
    linkedList->Print(); //should print 0  -->2 --> 3 --> 100  -->101; length = 5
}



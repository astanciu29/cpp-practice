// DoublyLinkedListPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DoublyLinkedList.h"
#include <iostream>

int main()
{
	DoublyLinkedList* doublyLinkedList = new DoublyLinkedList(1); // 1 ; length =1
	doublyLinkedList->Append(2); // 1 --> 2 ; length =2
	doublyLinkedList->Preppend(0); // 0 --> 1 --> 2; length = 3 
	doublyLinkedList->Print(); // should print 0 --> 1 --> 2; length = 3 
	doublyLinkedList->ReverseValues();
	doublyLinkedList->Print(); // should print 2 --> 1 --> 0; length = 3 
	doublyLinkedList->Insert(4, 3); // 2 --> 1 --> 0 --> 3; length = 4
	doublyLinkedList->Insert(1, -1); // -1 --> 2 --> 1 --> 0 --> 3; length = 5
	doublyLinkedList->Insert(2, 100); // -1 --> 100 --> 2 --> 1 --> 0 --> 3; length = 6
	doublyLinkedList->Print(); // should print -1 --> 100 --> 2 --> 1 --> 0 --> 3; length = 6
	doublyLinkedList->Remove(1); //100 --> 2 --> 1 --> 0 --> 3; length = 5
	doublyLinkedList->Remove(3); //100 --> 2  --> 0 --> 3; length = 4
	doublyLinkedList->Remove(4); //100 --> 2  --> 0 ; length = 3
	doublyLinkedList->Print(); // should print 100 --> 2  --> 0 ; length = 3
}


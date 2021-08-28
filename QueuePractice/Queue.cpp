#include <iostream>
#include "Queue.h"

Queue::Queue() : First(nullptr), Last(nullptr), Length(0) {};

Queue::Queue(int value) 
{
	Node* nodeToEnqueue = new Node(value);
	this->First = nodeToEnqueue;
	this->Last = nodeToEnqueue;
	this->Length = 1;
}

/// <summary>
/// Adds an element to the end of the queue.
/// </summary>
/// <param name="value"></param>
void Queue::Enqueue(int value)
{
	Node* nodeToEnqueue = new Node(value);
	this->Last->Next = nodeToEnqueue;
	this->Last = nodeToEnqueue;
	this->Length += 1;
}

/// <summary>
/// Removes an element from the beginning of the queue.
/// </summary>
void Queue::Dequeue() 
{
	Node* nodeToDequeue = this->First;
	this->First = this->First->Next;
	delete nodeToDequeue;
	this->Length -= 1;
}

/// <summary>
/// Returns the first element of the queue, if it exists.
/// </summary>
/// <returns></returns>
Node* Queue::Peak() const 
{
	if (this->First)
		return this->First;
	else
		std::cout << "Empty queue" << std::endl;
	return nullptr;
}

/// <summary>
/// Displays the first element of the queue on the console, if it exists.
/// </summary>
void Queue::PrintPeakValue() const 
{	
	std::cout << "The first element of the queue is: " << this->Peak()->GetValue() << std::endl;
}

/// <summary>
/// Displays all the elements of the queue on the console.
/// </summary>
void Queue::Print() const 
{
	Node* iterator = this->First;
	while (iterator != this->Last) {
		std::cout << iterator->GetValue() << " --> ";
		iterator = iterator->Next;
	}
	std::cout << this->Last->GetValue() << std::endl;
	std::cout << "The lenght of the queue is: " << this->Length<< std::endl<<std::endl;
}



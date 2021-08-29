#include <iostream>
#include "Stack.h"

Stack::Stack():Top(nullptr), Bottom(nullptr), Length(0){}

Stack::Stack(int value) {
	Node* nodeToBePushed = new Node(value);
	this->Bottom = nodeToBePushed;
	this->Top = nodeToBePushed;
	this->Length = 1;
}

	/// <summary>
	/// Adds an element at the top of the stack.
	/// </summary>
	/// <param name="value"></param>
void Stack::Push(int value) {
	Node* nodeToBePushed = new Node(value);
	this->Top->Next = nodeToBePushed;
	this->Top = nodeToBePushed;
	this->Top->Next = nullptr;
	this->Length += 1;
}

	/// <summary>
	/// Removes an element from the top of the stack.
	/// </summary>
void Stack::Pop() {
	Node* iterator = this->Bottom;	

	this->Length -= 1;

	int iterator_index{ 1 };

	while (iterator_index < this->Length) 
	{
		iterator = iterator->Next;
		iterator_index += 1;
	}	
	this->Top = iterator;
	delete iterator->Next;	
}

	/// <summary>
	/// Returns the first element of the stack, if it exists.
	/// </summary>
	/// <returns></returns>
Node* Stack::Peak() const {
	if (this->Top) {
		return this->Top;
	}
	else {
		std::cout << " Empty stack!" << std::endl;
	}
	return nullptr;
}

	/// <summary>
	/// Displays the first element of the stack on the console, if it exists.
	/// </summary>
void Stack::PrintPeakValue() const {
	std::cout << "The top value in the stack is:  " << this->Peak()->GetValue() << std::endl;
}

	/// <summary>
	/// Displays all the elements of the queue on the console.
	/// </summary>
void Stack::Print() const {
	Node* iterator = this->Bottom;
	std::cout << "The elements of the stack are:";
	while (iterator != this->Top) 
	{
		std::cout << iterator->GetValue() << "-->";
		iterator = iterator->Next;
	}
	std::cout << this->Top->GetValue() << std::endl;
	std::cout << "The lenght of the stack is: " << this->Length << std::endl << std::endl;
}
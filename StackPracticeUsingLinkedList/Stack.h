#include "Node.h"
#pragma once
class Stack
{
private:
	/// <summary>
	/// The top element of the stack.
	/// </summary>
	Node* Top;

	/// <summary>
	/// The bottom element of the stack.
	/// </summary>
	Node* Bottom;

	/// <summary>
	/// The length of the stack.
	/// </summary>
	unsigned Length;

public:
	Stack();
	Stack(int value);

	/// <summary>
	/// Returns the first element of the stack, if it exists.
	/// </summary>
	/// <returns></returns>
	Node* Peak() const;

	/// <summary>
	/// Adds an element at the top of the stack.
	/// </summary>
	/// <param name="value"></param>
	void Push(int value);

	/// <summary>
	/// Removes an element from the top of the stack.
	/// </summary>
	void Pop();

	/// <summary>
	/// Displays all the elements of the queue on the console.
	/// </summary>
	void Print() const;

	/// <summary>
	/// Displays the first element of the stack on the console, if it exists.
	/// </summary>
	void PrintPeakValue() const;
};


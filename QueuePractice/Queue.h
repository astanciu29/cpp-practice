#include "Node.h"
#pragma once
class Queue
{
private:
	/// <summary>
	/// The first element of the queue.
	/// </summary>
	Node* First{ nullptr };

	/// <summary>
	/// The last element in the queue.
	/// </summary>
	Node* Last{ nullptr };

	/// <summary>
	/// The length of the queue.
	/// </summary>
	unsigned Length{ 0 };

public:
	Queue();
	Queue(int value);

	/// <summary>
	/// Returns the first element of the queue, if it exists.
	/// </summary>
	/// <returns></returns>
	Node* Peak() const ;

	/// <summary>
	/// Displays the first element of the queue on the console, if it exists.
	/// </summary>
	void PrintPeakValue() const;

	/// <summary>
	/// Adds an element to the end of the queue.
	/// </summary>
	/// <param name="value"></param>
	void Enqueue(int value);

	/// <summary>
	/// Removes an element from the beginning of the queue.
	/// </summary>
	void Dequeue();	

	/// <summary>
	/// Displays all the elements of the queue on the console.
	/// </summary>
	void Print() const;
};


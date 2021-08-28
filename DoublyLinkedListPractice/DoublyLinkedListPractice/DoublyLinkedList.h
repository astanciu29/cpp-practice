#include "Node.h"
#pragma once

class DoublyLinkedList
{
private:
	/// <summary>
	/// The first node in the linked list.
	/// </summary>
	Node* Head{ nullptr };

	/// <summary>
	/// The last node in the linked list.
	/// </summary>
	Node* Tail{ nullptr };

	/// <summary>
	/// The length of the linked list.
	/// </summary>
	unsigned Length{ 0 };

public:
	DoublyLinkedList() = default;
	DoublyLinkedList(int value);

	/// <summary>
	/// Adds a value to the end of the list.
	/// </summary>
	/// <param name="value">The int value used to create the Node that will be appended.</param>
	void Append(int value);

	/// <summary>
	/// Adds a value at the start of the list.
	/// </summary>
	/// <param name="value">The int value used to create the Node that will be preppended.</param>
	void Preppend(int value);

	/// <summary>
	/// Inserts a value in the list at an existing index.
	/// </summary>
	/// <param name="value">The int value used to create the Node that will be inserted.</param>
	/// <param name="index"></param>
	void Insert(int index, int value);

	/// <summary>
	/// Removes a node from the linked list.
	/// </summary>
	/// <param name="index"> The index of the node that will be removed. </param>
	void Remove(int index);

	/// <summary>
	/// Reverses the direction of the list. 
	/// </summary>
	void ReverseValues();

	/// <summary>
	/// Displays the values of the list on the console.
	/// </summary>
	void Print();

	/// <summary>
	/// Iterates through the nodes in the linked list.
	/// </summary>
	/// <param name="index"></param>
	/// <returns> A pointer to a node from the list that coresponds to the index received as parameter. </returns>
	Node* TraverseToIndex(unsigned index);


};


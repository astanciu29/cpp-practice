#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(int value)
{
	Node* nodeToAdd = new Node(value);
	this->Head = nodeToAdd;
	this->Tail = nodeToAdd;
	this->Length = 1;
}

/// <summary>
/// Adds a value to the end of the list.
/// </summary>
/// <param name="value">The int value used to create the Node that will be appended.</param>
void LinkedList::Append(int value) 
{
	Node* nodeToAdd = new Node(value);
	this->Tail->Next = nodeToAdd;
	this->Tail = nodeToAdd;
	this->Length += 1;
}

/// <summary>
/// Adds a value at the start of the list.
/// </summary>
/// <param name="value">The int value used to create the Node that will be preppended.</param>
void LinkedList::Preppend(int value) 
{
	Node* nodeToAdd = new Node(value);
	nodeToAdd->Next = this->Head;
	this->Head = nodeToAdd;
	this->Length += 1;
}

/// <summary>
/// Iterates through the nodes in the linked list.
/// </summary>
/// <param name="index"></param>
/// <returns> A pointer to a node from the list that coresponds to the index received as parameter. </returns>
Node* LinkedList::TraverseToIndex(int index) 
{
	if (index > this->Length)
	{
		std::cout << std::endl << index << " - The index you are trying to remove does not exist!" << std::endl;
		return nullptr;
	}
	else if (index <= 0)
	{
		std::cout << std::endl << index << " - The index " << index << " you are trying to remove is not a positive number!" << std::endl;
		return nullptr;
	}
	else
	{
		int iterator_index {1};
		Node* iterator = this->Head;

		while (iterator_index < index - 1) {
			iterator = iterator->Next;
			iterator_index += 1;
		}
		return iterator;
	}
}

/// <summary>
/// Inserts a value in the list at an existing index.
/// </summary>
/// <param name="value">The int value used to create the Node that will be inserted.</param>
/// <param name="index"></param>
void LinkedList::Insert(int index, int value)
{
	//if we add a node to the front of the list
	if (index == 1)
	{
		this->Preppend(value);
	}
	//if we add a node to the back of the list
	else if (index > this->Length) 
	{
		this->Append(value);
	}
	// if we add a node to the interior of the list
	else 
	{
		Node* nodeToAdd = new Node(value);
		Node* penultimateNodeToIndex = this->TraverseToIndex(index); 
		nodeToAdd->Next = penultimateNodeToIndex->Next;
		penultimateNodeToIndex->Next = nodeToAdd;
		this->Length += 1;
	}
	 // nodetoadd ->next = head->next	
}

/// <summary>
/// Removes a node from the linked list.
/// </summary>
/// <param name="index"> The index of the node that will be removed. </param>
void LinkedList::Remove(int index) 
{
	Node* nodeToRemove{ nullptr };
	Node* penultimateNodeToIndex = this->TraverseToIndex(index);

	if (penultimateNodeToIndex) {
		//if we remove the last node
		if (index == this->Length) {
			nodeToRemove = this->Tail;
			penultimateNodeToIndex->Next = nullptr;
		}
		//if we remove the first node
		else if (index == 1) {
			nodeToRemove = this->Head;
			this->Head = this->Head->Next;
		}
		////if we remove an interior node
		else {
			nodeToRemove = penultimateNodeToIndex->Next;
			if (penultimateNodeToIndex->Next && penultimateNodeToIndex->Next->Next)
				penultimateNodeToIndex->Next = penultimateNodeToIndex->Next->Next;
			else if (penultimateNodeToIndex->Next)
				penultimateNodeToIndex->Next = nullptr;
		}		
			
		delete nodeToRemove;
		this->Length -= 1;
	}
	else 
	{
		std::cout <<  "Cannot remove node!" << std::endl << std::endl;
	}
}

/// <summary>
/// Displays the values of the list on the console.
/// </summary>
void LinkedList::Print() 
{
	Node* iterator = this->Head;
	std::cout << "The values of the linked list are:" << std::endl;
	while (iterator != this->Tail) {
		std::cout << iterator->GetValue() << " --> ";
		iterator=iterator->Next;
	}
	std::cout << this->Tail->GetValue() << std::endl;
	std::cout << "The length of the linked list is: " <<this->Length<< std::endl << std::endl;
}
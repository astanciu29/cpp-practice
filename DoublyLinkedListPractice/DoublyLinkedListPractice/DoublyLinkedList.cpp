#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(int value) 
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
void DoublyLinkedList::Append(int value)
{
	Node* nodeToAdd = new Node(value);
	this->Tail->Next = nodeToAdd;
	nodeToAdd->Previous = this->Tail;
	this->Tail = nodeToAdd;
	this->Length += 1;
}

/// <summary>
/// Adds a value at the start of the list.
/// </summary>
/// <param name="value">The int value used to create the Node that will be preppended.</param>
void DoublyLinkedList::Preppend(int value)
{
	Node* nodeToAdd = new Node(value);
	nodeToAdd->Next = this->Head;
	this->Head->Previous = nodeToAdd;
	this->Head = nodeToAdd;
	this->Length += 1;
}

/// <summary>
/// Iterates through the nodes in the linked list.
/// </summary>
/// <param name="index"></param>
/// <returns> A pointer to a node from the list that coresponds to the index received as parameter. </returns>
Node* DoublyLinkedList::TraverseToIndex(unsigned index)
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
		unsigned iterator_index{ 1 };
		Node* iterator = this->Head;

		while (iterator_index < index - 1) {
			iterator = iterator->Next;
			iterator_index += 1;
		}
		return iterator;
	}
}

/// <summary>
/// Reverses the values in the linked list.
/// </summary>
void DoublyLinkedList::ReverseValues() 
{
	unsigned iterator_head_index{ 1 };
	unsigned iterator_tail_index{ this->Length };

	Node* iterator_head = this->Head;
	Node* iterator_tail = this->Tail;

	while (iterator_head_index != iterator_tail_index) {
		Node* auxiliary = new Node(iterator_head->GetValue());		

		iterator_head->SetValue(iterator_tail->GetValue());
		iterator_tail->SetValue(auxiliary->GetValue());

		iterator_head_index += 1;
		iterator_tail_index -= 1;
	}
}

/// <summary>
/// Displays the values of the list on the console.
/// </summary>
void DoublyLinkedList::Print()
{
	Node* iterator = this->Head;
	std::cout << "The values of the linked list are:" << std::endl;
	while (iterator != this->Tail) {
		std::cout << iterator->GetValue() << " --> ";
		iterator = iterator->Next;
	}
	std::cout << this->Tail->GetValue() << std::endl;
	std::cout << "The length of the linked list is: " << this->Length << std::endl << std::endl;
}

/// <summary>
/// Inserts a value in the list at an existing index.
/// </summary>
/// <param name="value">The int value used to create the Node that will be inserted.</param>
/// <param name="index"></param>
void DoublyLinkedList::Insert(int index, int value)
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
		nodeToAdd->Previous = penultimateNodeToIndex;
		penultimateNodeToIndex->Next = nodeToAdd;
		this->Length += 1;
	}
}

/// <summary>
/// Removes a node from the linked list.
/// </summary>
/// <param name="index"> The index of the node that will be removed. </param>
void DoublyLinkedList::Remove(int index)
{
	Node* nodeToRemove{ nullptr };
	Node* penultimateNodeToIndex = this->TraverseToIndex(index);

	if (penultimateNodeToIndex) {
		//if we remove the last node
		if (index == this->Length) {
			nodeToRemove = this->Tail;
			penultimateNodeToIndex->Next = nullptr;
			this->Tail->Previous = nullptr;
			this->Tail = penultimateNodeToIndex;
		}
		//if we remove the first node
		else if (index == 1) {
			nodeToRemove = this->Head;
			this->Head = this->Head->Next;
			this->Head->Next->Previous = nullptr;
		}
		////if we remove an interior node
		else {
			nodeToRemove = penultimateNodeToIndex->Next;

			// if there are at least 2 more node to the Tail
			if (penultimateNodeToIndex->Next && penultimateNodeToIndex->Next->Next) 
			{
				penultimateNodeToIndex->Next = penultimateNodeToIndex->Next->Next;
				penultimateNodeToIndex->Next->Next->Previous = penultimateNodeToIndex;
			}				

			// if the node removed is the one right before the Tail
			else 
			{
				penultimateNodeToIndex->Next = this->Tail;
				this->Tail->Previous = penultimateNodeToIndex;				
			}			
		}
		delete nodeToRemove;
		this->Length -= 1;
	}
	else
	{
		std::cout << "Cannot remove node!" << std::endl << std::endl;
	}
}
#pragma once
class Node
{
private:
	/// <summary>
	/// The value stored in the node.
	/// </summary>
	int Value;
public:
	/// <summary>
	/// A reference to the next node in the linked list.
	/// </summary>
	Node* Next;

	Node() = default;
	Node(int value);


	/// <summary>
	/// Returns the value value stored in the node.
	/// </summary>
	/// <returns></returns>
	int GetValue() const;

	/// <summary>
	/// Returns the value of the next element in list, if it exists.
	/// </summary>
	/// <returns></returns>
	int GetNextValue() const;

	~Node() = default;
};


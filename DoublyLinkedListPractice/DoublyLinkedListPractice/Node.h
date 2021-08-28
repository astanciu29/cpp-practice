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

	/// <summary>
	/// A reference to the previous node in the linked list.
	/// </summary>
	Node* Previous;

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

	/// <summary>
	/// Returns the value of the previous element in list, if it exists.
	/// </summary>
	/// <returns></returns>
	int GetPreviousValue() const;

	void SetValue(int value);

	~Node() = default;
};


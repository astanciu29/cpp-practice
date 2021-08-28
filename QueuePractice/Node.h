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
	/// A reference to the next element in the queue.
	/// </summary>
	Node* Next;

	Node() = default;
	Node(int value);

	/// <summary>
	/// Returns the value value stored in the node.
	/// </summary>
	/// <returns></returns>
	int GetValue() const;

	~Node() = default;
};


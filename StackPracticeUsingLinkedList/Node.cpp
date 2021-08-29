#include "Node.h"

Node:: Node(int value): Value(value), Next(nullptr){}

/// <summary>
/// Returns the value value stored in the node.
/// </summary>
/// <returns></returns>
int Node::GetValue() const {
	return this->Value;
}


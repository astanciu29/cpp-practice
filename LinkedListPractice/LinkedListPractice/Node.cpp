#include <iostream>
#include "Node.h"


Node::Node(int value): Value(value), Next(nullptr)
{
}

/// <summary>
/// Returns the value value stored in the node.
/// </summary>
/// <returns></returns>
int Node::GetValue() const {
	return this->Value;
}

/// <summary>
/// Returns the value of the next element in list, if it exists.
/// </summary>
/// <returns></returns>
int Node::GetNextValue() const 
{
	try {
		if (this->Next)
			return this->Next->Value;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
		//  throw e; // copy-initializes a new exception object of type std::exception
		throw;
	}
}
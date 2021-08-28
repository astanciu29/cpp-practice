#include <iostream>
#include "Queue.h"

int main()
{
    Queue* queue = new Queue(1); // 1 ; length: 1 
    queue->Enqueue(2); // 1--> 2 ; length: 2
    queue->Print(); //should print 1--> 2 ; length: 2
    queue->PrintPeakValue(); // should print 1;
    queue->Dequeue(); // 2; length: 1
    queue->PrintPeakValue(); // should print 2;
    queue->Print(); // should print 2; length:1
}
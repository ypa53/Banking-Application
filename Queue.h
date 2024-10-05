/* 
 * Queue.h
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 */
 
#ifndef QUEUE_H
#define QUEUE_H
template <class ElementType>
class Queue {

/* You cannot remove/modify the data members below, 
   except for the "int elements[INITIAL_CAPACITY];". 
   However, you can add more data members.              */
	
    private:
        static unsigned int const INITIAL_CAPACITY = 10; // Constant INITIAL_CAPACITY
        ElementType * elements = nullptr;                       // To do: replace this by int * elements -> Question 4.a) - DONE! - The Queue

        unsigned int elementCount = 0;                  // Number of elements in the Queue - if you need it!
        unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex = 0;                    // Index of front element (next dequeued/peeked element)
        unsigned int backindex = 0;                     // Index of where the next element will be enqueued                     

/* You can add private methods. */
        // Description: Change the size of the array to newLen
        // Precondition: newlen >= INITIAL_SIZE
        unsigned int resize(unsigned newLen);
        
        // Description: Output all elements of the Queue. For testing Purposes
        void printQueue();

    public:
 
/* You cannot remove/modify the public methods below. 
   This also applies to their documentation. 
   However, you can add public methods if you need them 
   like "printQueue()", etc.                            */

        // Description: Constructor
        Queue();

        // Description: Destructor
        // Postcondition: elements[] is recycled
        ~Queue();

        // Description: Inserts element x at the back of Queue
        // Time Efficiency: O(1)
        bool enqueue(ElementType & newElement);

        // Description: Removes the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        void dequeue();

        // Description: Returns a copy of the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
       ElementType & peek() const;

        // Description: Returns true if and only if Queue empty
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
};
#include "Queue.cpp"
#endif



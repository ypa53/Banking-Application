/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 */
#include <iostream>
#include "EmptyDataCollectionException.h"
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
template <class ElementType> 
Queue<ElementType>::Queue() {}

// Description: Destructor
// Postcondition: elements[] is recycled
template <class ElementType> 
Queue<ElementType>::~Queue() {
    if ( elements ) {
        delete [] elements;
        elements = nullptr; // A good habit (against dangling pointer) to adopt!
    }
}

// Description: Inserts element x at the back of Queue
// Time Efficiency: O(1)
template <class ElementType> 
bool Queue<ElementType>::enqueue(ElementType& newElement) {

    if ( elements == nullptr ) 
        capacity = resize(capacity);
    else {
       if ( elementCount == capacity ) {
	      // Full:  double the capacity
	      capacity = resize(capacity * 2);
	      // cout << "resizing to " << capacity << "   "; print();
       }
    }
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
    return true;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
template <class ElementType> 
void Queue<ElementType>::dequeue() {

     if(isEmpty())
    {
    
    	throw EmptyDataCollectionException("Empty");
    
    }else
    // if ( !isEmpty() ) ???
    if ( elementCount <= capacity / 4 ) {
        if ( capacity / 2 >= INITIAL_CAPACITY ) {
            capacity = resize(capacity / 2);
            // cout << "resizing to " << capacity << "   "; print();
        }
    }
    elementCount--;
    frontindex = (frontindex + 1) % capacity;

    // print();
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
template <class ElementType> 
ElementType & Queue<ElementType>::peek() const {
	// if ( !isEmpty() ) ???
    if(isEmpty())
   	{
   		throw EmptyDataCollectionException("Empty");
   	}
   	else
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
template <class ElementType> 
bool Queue<ElementType>::isEmpty() const {
    if(elementCount == 0)
   	{
   		return true;
   	}
   	return false;
}

// Description: Output all elements of the Queue. For testing Purposes
template <class ElementType> 
void Queue<ElementType>::printQueue() {
    cout << "{";
    for (unsigned int i = 0; i < elementCount; i++) {
        cout << elements[(i+frontindex) % capacity];
        if (i + 1 < elementCount) {
            cout << ',';
        }
    }
    cout << "}" << endl;
} 


// Description: Change the size of the array to newLen
// Precondition: newlen >= INITIAL_SIZE
template <class ElementType> 
unsigned int Queue<ElementType>::resize(unsigned newLen) {

    // No size change => nothing to do
    if ( newLen == capacity && elements ) return capacity;

    // Precondition check
    if ( newLen < INITIAL_CAPACITY ) return INITIAL_CAPACITY;

    // Allocate new space of capacity "newLen"
    ElementType * newElements = new ElementType[newLen];
	if ( newElements == NULL ) return capacity;
	
    // Copy elements to new array
    for ( unsigned int i = 0; i < elementCount; i++) {
        newElements[i] = elements[(i+frontindex) % capacity];
    }

    // Release old space
    delete [] elements;
    elements = newElements;

    // Update data members
    frontindex = 0;
    backindex = (elementCount % newLen);
    return newLen; // To be assigned to capacity
} 


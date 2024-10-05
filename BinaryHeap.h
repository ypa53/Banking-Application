/* 
 * BinaryHeap.h
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 * 
 *
 */  

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

//#include <string>

using namespace std;

template <class ElementType>

class BinaryHeap {

 	
private:
    static unsigned int const INITIAL_CAPACITY = 10; 
    unsigned int elementCount = 0;
    unsigned int capacity = INITIAL_CAPACITY;
    //BinaryHeap<ElementType> * elements = new BinaryHeap<ElementType>[capacity];
    ElementType* elements = new ElementType[capacity];
    //unsigned int resize(unsigned newLen);


public:

    // Default Constructor
    BinaryHeap();
    ~BinaryHeap();
    

   // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   unsigned int getElementCount() const;

   // Description: Inserts newElement into the Binary Heap. 
   //              It returns true if successful, otherwise false.      
   // Time Efficiency: O(log2 n)
   bool insert(ElementType & newElement);
      
   // Description: Removes (but does not return) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   ElementType & retrieve() const;
   
   void reHeapDown(unsigned int indexOfRoot);
 

    
    
    
}; // end of BinaryHeap.h
#include "BinaryHeap.cpp"
#endif



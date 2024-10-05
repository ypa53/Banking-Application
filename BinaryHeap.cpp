/* 
 * BinaryHeap.cpp
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 * 
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;
  
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
    //elementCount = 0;
   //  capacity = cap;
    //elements = new BinaryHeap<ElementType>[capacity];
}

template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
    delete[] elements;
    elements = nullptr; 
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   reHeapDown(0);
   
   return;   
}

// Utility method
// Description: Recursively put the array back into a ____________ Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;  // 2i + 1
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;  // 2i + 1

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount-1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
}


// Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   template <class ElementType>
   unsigned int BinaryHeap<ElementType>::getElementCount() const
   {
   	   return elementCount;
   }

   // Description: Inserts newElement into the Binary Heap. 
   //              It returns true if successful, otherwise false.      
   // Time Efficiency: O(log2 n)
   template <class ElementType>
   bool BinaryHeap<ElementType>::insert(ElementType & newElement) // min heap
   {
      /*elements
	   if(newElement == nullptr)
	   {
	      return false;
	   }*/
      
 
   // {
	      elements[elementCount] = newElement;
	      elementCount++;
	      reHeapDown(0);
	      return true;

    return false;
      
   }
   


   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   template <class ElementType>
   ElementType & BinaryHeap<ElementType>::retrieve() const // return the last one
   {
   	if(elementCount == 0) 
   	{
   	
   		throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
   	
   	}else 
   	
      {
	   	//elements[0] = elements[elementCount-1];
	   	return elements[0];
   	
      }
   }
 
//  template <class ElementType>
// void List<ElementType>::printList() const {

//    Node<ElementType> * current = head;
   
//    cout << "{"; //Nice format!
//    // Traverse the list
//    while (current != nullptr){
//       cout << current->data; // Print data
//       current = current->next; // Go to next Node
//       if (current != nullptr){
//          cout << ","; // Print a comma unless at the end of the list
//       }
//    }
//    cout << "}"; // Don't print a newline - it might not be wanted
// }
 
 
 
  


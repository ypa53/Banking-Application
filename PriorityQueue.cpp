

#include <iostream>
//#include "BinaryHeap.h" 
#include "PriorityQueue.h"  // Header file
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;
  
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{

pq = new BinaryHeap<ElementType>();

}

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(PriorityQueue & aPriorityQueue)
{
   

}

template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
   delete[] pq;
   pq = nullptr; 

}

// Description: Returns true if this Priority Queue is empty, otherwise false.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   template <class ElementType>
   bool PriorityQueue<ElementType>::isEmpty() const
   {
      if(pq->getElementCount() == 0)
      {
         return true;
      }else return false;
   }

   // Description: Inserts newElement in this Priority Queue and
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   template <class ElementType>
   bool PriorityQueue<ElementType>::enqueue(ElementType & newElement)
   {
      // if(pq == nullptr){
      //    pq = new BinaryHeap<ElementType>();
      // }
      elementCount++;
      return pq->insert(newElement);
   }

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   template <class ElementType>
   void PriorityQueue<ElementType>::dequeue()
   {
      pq->remove();
      elementCount--;
   }
   
   // Description: Returns (but does not remove) the element with the next
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   template <class ElementType>
   ElementType & PriorityQueue<ElementType>::peek() const
   {
      return pq->retrieve();
   }

   template <class ElementType>
   unsigned int PriorityQueue<ElementType>::getElementCount() const
   {
   	   return elementCount;
   }
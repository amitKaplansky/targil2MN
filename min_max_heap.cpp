#include "min_max_heap.h"

Pair min_max_heap::deleteMax() // delete heapNode from max_heap (deletes the pointer also from min_heap) change from both heaps the relevant ind and do fix heap
{
   const heapNode* temp = max_heap.max();
   Pair res = temp->pair;

   int minInd = temp->indMin;
   max_heap.deleteMax();
   min_heap.deleteFromHeap(minInd);

   return res;
}

Pair min_max_heap::deleteMin() // delete heapNode from min_heap (deletes the pointer also from max_heap) change from both heaps the relevant ind and do fix heap
{
    const heapNode* temp = min_heap.min();
    Pair res = temp->pair;

    int maxInd = temp->indMax;
    min_heap.deleteMin();
    max_heap.deleteFromHeap(maxInd);

    return res;
}
void min_max_heap::insert(heapNode*& newNode) // insert to both heaps
{
    max_heap.insert(newNode);
    min_heap.insert(newNode);
}

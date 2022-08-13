#pragma once
#include "max_heap.h"
#include "min_heap.h"

class min_max_heap
{
    private:
        max_heap max_heap;
        min_heap min_heap;

    public:

        void insert(heapNode*& newNode);
        Pair max() const { return max_heap.max()->pair;}
        Pair min() const { return min_heap.min()->pair;}
        int getSize() const { return max_heap.getLSize();}
        void createEmpty() { max_heap.makeEmpty(); min_heap.makeEmpty();}

        Pair deleteMax();
        Pair deleteMin();
};

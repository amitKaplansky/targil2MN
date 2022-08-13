#pragma once
#include "pair.h"
#include "min_heap.h"

class max_heap
{
    public:
        enum class size{max = 100} ;

    private:
        heapNode* data[(int)size::max]= {};
        int pSize = (int)size::max;
        int lSize = 0;
        static int Left(int node);
        static int Right(int node);
        static int Parent(int node);

        void fixHeap(int node);

    public:

        ~max_heap() {
            for (int i = 0; i < lSize; i++)
                delete data[i];
        }

        const heapNode* max() const { return  data[0];}
        void deleteMax();
        void insert(heapNode*& newNode); // returns index in heap
        int getLSize() const {return lSize;}
        void deleteFromHeap(int ind);
        void makeEmpty() { lSize = 0;}
        void swapInd(int& a, int& b);

};
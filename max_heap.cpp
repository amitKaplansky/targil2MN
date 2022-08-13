#include "max_heap.h"


int max_heap:: Left(int node)
{
    return (2*node + 1);
}
int max_heap:: Right(int node)
{
    return (2*node + 2);
}
int max_heap::Parent(int node)
{
    return (node -1)/2;
}
void max_heap:: fixHeap(int node)
{
    int max;
    int left = Left(node);
    int right = Right(node);

    if(left < lSize) {
        if (data[left]->pair.priority > data[node]->pair.priority)
            max = left;
    }
    else
        max = node;
    if(right < lSize) {
        if (data[right]->pair.priority > data[max]->pair.priority)
            max = right;
    }

    if(max != node)
    {
        heapNode* temp;
        temp = data[node];
        data[node] = data[max];
        data[max] = temp;
        data[node]->indMax = max;
        data[max]->indMax = node;
        fixHeap(max);
    }
}

void max_heap:: deleteMax()
{
    if(lSize < 1)
    {
        exit (0);
    }

    delete data[0]; // free pointer
    --lSize;

    data[0] = data[lSize];
    data[0]->indMax = 0;

    if(lSize > 1)
        fixHeap(0);
}
void max_heap:: insert(heapNode*& newNode)
{
    if(lSize == pSize)
    {
        exit(0);
    }

    int i = lSize;
    ++lSize;

    data[lSize -1] = newNode;
    data[lSize -1]->indMax = lSize -1;

    while(i > 0 && (data[Parent(i)]->pair.priority < newNode->pair.priority))
    {
        swapInd(data[i]->indMax,data[Parent(i)]->indMax);
        heapNode* temp;
        temp = data[Parent(i)];
        data[Parent(i)] = data[i];
        data[i] = temp;
        i = Parent(i);
    }
    data[i] = newNode;
    newNode->indMax = i;

}
void max_heap:: deleteFromHeap(int ind)
{
    if(lSize <= 2)
        --lSize;
    else{
        data[ind] = data[lSize-1];
        data[ind]->indMax = ind;
        --lSize;
        if (lSize > 1)
            fixHeap(ind);
    }
}

void max_heap:: swapInd(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
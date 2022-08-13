#include "min_heap.h"

int min_heap:: Left(int node)
{
    return (2*node + 1);
}
int min_heap:: Right(int node)
{
    return (2*node + 2);
}
int min_heap::Parent(int node)
{
    return (node -1)/2;
}
void min_heap:: fixHeap(int node)
{
    int min;
    int left = Left(node);
    int right = Right(node);

    if(left < lSize) {
        if (data[left]->pair.priority < data[node]->pair.priority)
            min = left;
    }
    else
        min = node;

    if(right < lSize) {
        if (data[right]->pair.priority < data[min]->pair.priority)
            min = right;
    }

    if(min != node)
    {
        heapNode* temp;
        temp = data[node];
        data[node] = data[min];
        data[min] = temp;
        data[node]->indMin = min;
        data[min]->indMin = node;
        fixHeap(min);
    }
}

void min_heap:: deleteMin()
{
    if(lSize < 1)
    {
        exit (0);
    }
    delete data[0]; // free pointer
    --lSize;

    data[0] = data[lSize];
    data[0]->indMin = 0;

    if(lSize > 1)
        fixHeap(0);
}
void min_heap:: insert(heapNode*& newNode)// insert ind to heap node and also add it to fix heap
{
    if(lSize == pSize)
    {
        exit(0);
    }
    int i = lSize;
    ++lSize;

    data[lSize -1] = newNode;
    data[lSize -1]->indMin = lSize -1;

    while(i > 0 && (data[Parent(i)]->pair.priority > newNode->pair.priority))
    {
        swapInd(data[i]->indMin,data[Parent(i)]->indMin);
        heapNode* temp;
        temp = data[Parent(i)];
        data[Parent(i)] = data[i];
        data[i] = temp;
        i = Parent(i);
    }
    data[i] = newNode;
    newNode->indMax = i;
}
void min_heap:: deleteFromHeap(int ind)
{
    if(lSize <= 2)
        --lSize;
    else{
        data[ind] = data[lSize -1];
        data[ind]->indMin = ind;
        --lSize;
        if (lSize > 1)
            fixHeap(ind);
    }
}
void min_heap:: swapInd(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


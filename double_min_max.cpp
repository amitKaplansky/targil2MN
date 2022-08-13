#include "double_min_max.h"

Pair double_min_max::DeleteMax()
{
    Pair res;
    if(bigSize == 0)
    {
        if(smallSize == 0)
        {
            cout << " Wrong input " << endl;
            exit(1);
        }
        else
        {
            res = small.deleteMax();
        }
    }
    else {
        res = big.deleteMax();
        setBigSize();

        //if(smallSize == bigSize + 1) - before the delete smallSize == bigSize, no changes in this case
        //if(smallSize == bigSize + 2) // - before the delete smallSize == bigSize + 1 (UpdateHeaps)
        UpdateHeaps();
    }
    return res;
}
Pair double_min_max::DeleteMin()
{
    if(smallSize == 0)
    {
        cout << " Wrong input " << endl;
        exit(1);
    }

    Pair res = small.deleteMin();
    setSmallSize();

    //if(smallSize == bigSize) -  before smallSize == bigSize + 1 , no changes in this case
    //if(smallSize == bigSize - 1) // before (smallSize == bigSize) added to big (UpdateHeaps)

    UpdateHeaps();

    return res;
}
void double_min_max::Insert(int priority,string& value)
{
    Pair newPair = {priority, value};

    if(smallSize + bigSize == (int)size::max)
    {
        cout << "Heap is full, no place to add more" << endl;
        exit(0);
    }

    heapNode* node = new heapNode;
    node->pair = newPair;

    if(smallSize == 0) // if heap is empty, add auto to small heap
    {
        small.insert(node);
        setSmallSize();
    }
    else
    {
        Pair median = Median();

        if (newPair.priority > median.priority) // add newPair the big heaps
        {
            big.insert(node);
            setBigSize();
        } else // add newPair to small heaps
        {
            small.insert(node);
            setSmallSize();
        }

        UpdateHeaps();

    }
}
void double_min_max::UpdateHeaps() // in case big is bigger the small, or small + 2 == big
{
    // if(smallSize == bigSize) - do nothing, before adding newPair (smallSize == bigSize + 1), added to big

    //if(smallSize == bigSize + 1) do nothing. before adding newPair (smallSize == bigSize), added to small

    if(smallSize == bigSize + 2) // before (smallSize == bigSize +1), added to small
    {
        // in this case - median needs to be deleted from small_heap, and insert to big_heap
        Pair temp = small.deleteMax(); // delete median
        heapNode* node = new heapNode; // create new node to add in big_ heap
        node->pair = temp;
        big.insert(node); // add node to big heaps
        setBigSize(); // update sizes of small and big heaps
        setSmallSize();
    }
    else if(smallSize == bigSize - 1) // before (smallSize == bigSize) added to big
    {
            // in this case - the smallest from big_heap needs to move to small_heap
            Pair temp = big.deleteMin(); // delete smallest for big_heap
            heapNode* node = new heapNode;
            node->pair = temp;
            small.insert(node);// add node to small heaps
            setSmallSize(); // update sizes of small and big heaps
            setBigSize();
    }
}
Pair double_min_max:: Max() const
{
    if(bigSize == 0)
    {
        if(smallSize == 0)
        {
            cout << "Error - heaps are empty" << endl;
            exit(1);
        }
        else
        {
            return Median();
        }
    }

     return big.max();
}
Pair double_min_max::Min() const
{
    if(smallSize == 0)
    {
        cout << "Error - heaps are empty" << endl;
        exit(1);
    }
    return small.min();
}
Pair double_min_max:: Median() const
{
    if(smallSize == 0)
    {
        cout << "Error - heaps are empty" << endl;
        exit(1);
    }
    return small.max();
}

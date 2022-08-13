#pragma once
#include "min_max_heap.h"

class double_min_max
{
    private:
        min_max_heap big;
        min_max_heap small;
        int smallSize = 0, bigSize = 0;

        void UpdateHeaps();

    public:

        enum class size{max = 100};

        Pair Max() const; // a
        Pair DeleteMax(); // b
        Pair Min() const; // c
        Pair DeleteMin(); // d
        void createEmpty() { big.createEmpty(); small.createEmpty(); setBigSize(); setSmallSize(); } // e
        void Insert(int priority,string& value); // f
        Pair Median() const;  // g

        void setSmallSize() { smallSize = small.getSize();}
        void setBigSize() { bigSize = big.getSize();}
        int getBigSize() const {return bigSize;}
        int getSmallSize() const {return smallSize;}


};
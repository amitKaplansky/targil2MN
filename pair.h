#pragma once

#include <string>
#include <iostream>
using namespace std;


struct Pair
{
    int priority;
    string data;
};
struct heapNode {

    Pair pair;
    int indMax;
    int indMin;

};
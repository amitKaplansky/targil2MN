#pragma once

#include <string>
#include <iostream>
#include "double_min_max.h"
using namespace std;

int validNumOfInputs();
void fourHeaps();
bool userLine(string& line , double_min_max& heap, bool& firstE);
bool checkString(const char* a,double_min_max& heap, bool& firstE);
bool heapFunctions(const char* line, double_min_max& heap, bool& firstE);
bool fValid(const char* line, double_min_max& heap);




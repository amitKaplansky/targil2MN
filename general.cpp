#include "general.h"

void fourHeaps()
{
    double_min_max heap;
    string userInput;
    int numOfInputs;
    bool valid = true;
    bool firstE = false;


    numOfInputs = validNumOfInputs();

    if(numOfInputs == -1)
    {
        cout << "Wrong input" << endl;
        exit(1);
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(std::cin, userInput);

    while((numOfInputs != 0) && (userInput != "") && valid)
    {
        valid = userLine(userInput, heap , firstE);

        --numOfInputs;
        getline(std::cin, userInput);
    }
    if((numOfInputs == 0 && (userInput != "")) || (numOfInputs != 0 && (userInput == "")))
    {
        cout << "Wrong input" << endl;
        exit(1);
    }
    if(!valid)
    {
        cout << "Wrong input" << endl;
        exit(1);
    }

}
int validNumOfInputs()
{
    int res;
    cin >> res;

    if(res > 0)
    {
        return res;
    }

    return -1;
}

bool userLine(string& line, double_min_max& heap, bool& firstE)
{
    bool res = true;

    res = checkString(line.data(), heap, firstE);

    return res;
}

bool checkString(const char* a, double_min_max& heap, bool& firstE)
{
    if(a[0] != 'a' && a[0] != 'b' && a[0] != 'c' && a[0] != 'd' && a[0] != 'e' && a[0] != 'f' && a[0] != 'g')
        return false;

    else if(a[0] != 'e' && !firstE)
        return  false;

    else
        return heapFunctions(a, heap, firstE);
}
bool heapFunctions(const char* line, double_min_max& heap, bool& firstE)
{
    Pair temp;

    switch (line[0])
    {
        case 'a':
            temp =  heap.Max();
            cout << temp.priority << " " <<  temp.data << endl;
            break;
        case 'b':
            if(heap.getSmallSize() == 0)
            {
                cout << "Wrong input" << endl;
                exit(1);
            }
            else {
                temp = heap.DeleteMax();
                cout << temp.priority << " " << temp.data << endl;
                temp.data.clear();
            }
            break;
        case 'c':
            temp =  heap.Min();
            cout << temp.priority <<  " " << temp.data << endl;
            break;
        case 'd':
            if(heap.getSmallSize() == 0)
            {
                cout << "Wrong input" << endl;
                exit(1);
            }
            else {
                temp = heap.DeleteMin();
                cout << temp.priority << " " << temp.data << endl;
                temp.data.clear();
            }
            break;
        case 'e':
            if(firstE)
            {
                cout << "Wrong input" << endl;
                exit(1);
            }
            else {
                heap.createEmpty();
                firstE = true;
            }
            break;
        case 'f':
            return fValid(line, heap);
            break;
        case 'g':
            temp = heap.Median();
            cout  << temp.priority <<  " " << temp.data << endl;
            break;
    }
    return true;
}
bool fValid(const char* line, double_min_max& heap)
{
    int priority;
    string data;

    int size = (int)strlen(line);
    if(size < 5)
    {
        return false;
    }

    if(line[1] != ' ' && ((line[2] - '0' < 0 && line[2] - '9' > 9) || line[2] != '-')) {
        cout << "Invalid string " << endl;
        return false;
    }

    priority = atoi(line + 1);

    int i = 2;

    while(line[i] != ' ')
    {
        i++;
    }
    i++;

    if(size - i <= 0 )
        return false;

    for(int j = 0 ; j < size - i ; j++)
    {
        data += line[i + j];
    }

    heap.Insert(priority, data);

    return true;
}

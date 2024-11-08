#pragma once
#ifndef Q2
#define Q2

#include <vector>

using namespace std;

//starts from end and finds last occurrence of target
template<typename ItemType>
int linear_search(vector<ItemType>& items, ItemType& target, size_t pos_last) {
    if (pos_last < 0) //base case, not found
        return -1;
    if (target == items[pos_last]) //if it is found, return the position of the last occurrence
        return pos_last;
    else
        return linear_search(items, target, pos_last - 1); //recursive call starting from the end
}




#endif

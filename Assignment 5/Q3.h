#include <list>
#include <iostream>

using namespace std;

// Function to perform insertion sort on a list of integers
void insertion_sort(list<int>& thelist) {
    if (thelist.size() <= 1) {
        return; // No need to sort if the list has 0 or 1 element
    }

    // Start from the second element
    list<int>::iterator j_itr = thelist.begin();
    ++j_itr; // Move to the second element

    for (; j_itr != thelist.end(); ++j_itr) {
        int key = *j_itr; // Store the value of the current element
        list<int>::iterator i_itr = j_itr;
        --i_itr; // Move i_itr to the element before j_itr

        // Find the correct position for `key`
        list<int>::iterator next_itr = j_itr; // Initialize next_itr to j_itr
        while (i_itr != thelist.begin() && *i_itr > key) {
            *next_itr = *i_itr; // Shift the value to the right
            next_itr = i_itr;  // Move next_itr one step left
            --i_itr;           // Move i_itr one step left
        }

        // Special case for inserting at the very beginning
        if (i_itr == thelist.begin() && *i_itr > key) {
            *next_itr = *i_itr; // Shift the first element
            *i_itr = key;       // Insert `key` at the beginning
        }
        else {
            *next_itr = key; // Place `key` in its correct position
        }
    }
}



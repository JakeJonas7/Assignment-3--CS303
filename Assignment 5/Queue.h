#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename ItemType>
class Queue {
private:
    ItemType* the_data; //array to hold queue data
    static const size_t DEFAULT_CAPACITY = 10; //default capacity of queue
    size_t capacity; //current capacity
    size_t num_items; //current number of items in queue
    size_t front_index; //index of front item
    size_t rear_index; //index of rear item

public:
    Queue(size_t size = DEFAULT_CAPACITY);
    
    void push(const ItemType& item); //Add item to queue
    void pop(); //Remove item from front of queue
    ItemType front() const; //return front item
    size_t size(); //return current size
    bool empty() const; //check if empty
    void move_to_rear(); //move item from front to rear
    void reallocate(); //double the queue capacity if it is full
    void print_Queue(); //print queue contents
    void insertion_sort(); //use insertion sort on queue
};

#include "Queue.h"
using namespace std;

template<typename ItemType>
Queue<ItemType>::Queue(size_t size) : the_data(new ItemType[size]), capacity(size), num_items(0), front_index(0), rear_index(-1) {}

template<typename ItemType>
void Queue<ItemType>::push(const ItemType& item) {
    if (num_items == capacity) {
        reallocate(); //resize if queue is full
    }
    num_items++;
    rear_index = (rear_index + 1) % capacity;
    the_data[rear_index] = item;
}

template<typename ItemType>
void Queue<ItemType>::pop() {

    if (empty()) {
        throw std::runtime_error("Queue is empty, failed to pop.");
    }
    front_index = (front_index + 1) % capacity;
    num_items--;
}

template<typename ItemType>
ItemType Queue<ItemType>::front() const {
    return the_data[front_index];
}

template<typename ItemType>
bool Queue<ItemType>::empty() const {
    return num_items == 0;
}

template<typename ItemType>
size_t Queue<ItemType>::size() {
    return num_items;
}

template<typename ItemType>
void Queue<ItemType>::reallocate() {
    //create a larger array and copy elements in order

    size_t new_capacity = 2 * capacity;
    ItemType* new_data = new ItemType[new_capacity];
    size_t j = front_index;

    for (size_t i = 0; i < num_items; i++) {
        new_data[i] = the_data[j];
        j = (j + 1) % capacity;
    }

    front_index = 0;
    rear_index = num_items - 1;
    capacity = new_capacity;
    swap(the_data, new_data);
    delete[] new_data;
}


template<typename ItemType>
void Queue<ItemType>::move_to_rear() {
    if (num_items > 1) {
        ItemType temp = the_data[front_index];
        pop(); //remove front element
        push(temp); //add to rear

    }
}

template<typename ItemType>
void Queue<ItemType>::print_Queue() {
    Queue<ItemType> displayQueue(capacity);
    while (!empty()) {
        ItemType item = front();
        cout << item << " ";
        displayQueue.push(item);
        pop();
    }
    cout << endl;
    while (!displayQueue.empty()) {
        push(displayQueue.front());
        displayQueue.pop();

    }


}

template<typename ItemType>
void Queue<ItemType>::insertion_sort() {
    int i, j, key;
    bool insertionNeeded = false;

    for (j = 1; j < size(); j++) {
        key = the_data[j];
        insertionNeeded = false;

        for (i = j - 1; i >= 0; i--) {
            if (key < the_data[i]) {
                the_data[i + 1] = the_data[i];
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded)
            the_data[i + 1] = key;

    }
}


#endif 


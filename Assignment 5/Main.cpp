#include <iostream>
#include "Q3.h"
#include "Queue.h"
#include "Q2.h"
#include <list>
using namespace std;

int main() {
	Queue<int> queue;

	for (int i = 1; i <= 10; i++) { //2,4,6,8,10,12,14,16,18,20
		queue.push(2 * i);
	}

	//Display initial queue 
	cout << "Q1:" << endl;
	cout << "Current Queue: ";
	queue.print_Queue();
	cout << endl;

	//display front element and remove first two elements
	cout << "The front element of the queue: " << queue.front() << endl;
	queue.pop(); //popping 2
	queue.pop(); //popping 4

	//display front element afer pops and queue size
	cout << "The front element of the queue after popping the first two elements: " << queue.front() << endl; //6
	cout << "Size of the queue is now: " << queue.size() << endl; //8

	//push two elements to queue
	cout << endl;
	cout << "Pushing 50 and 60 to the queue" << endl;
	queue.push(50); //pushing 50
	queue.push(60); //pushing 60

	//display after adding two elements
	cout << "Current Queue: ";
	queue.print_Queue();
	cout << endl;
	cout << "Displaying the front element of the queue after pushing two elements: " << queue.front() << endl; //6
	cout << "Size of the queue is now: " << queue.size() << endl; //10

	queue.move_to_rear(); //moving 6 to rear
	cout << "Displaying the front element of the queue after moving the front element to the rear: " << queue.front() << endl; //8

	//check if quue is empty
	cout << "Is the queue empty? " << (queue.empty() ? "Yes, it is empty" : "No, it is not empty") << endl; //No
	cout << "Current Queue: ";
	queue.print_Queue();
	cout << endl;
	cout << "Q2:" << endl;

	//Search for occurrence of value 1 in vector
	vector<int> q2 = { 1,3,4,8,2,1,7,9,10,1,5 };
	int value = 1;

	int last_position = linear_search(q2, value, q2.size() - 1);

	cout << "The last position of the target element " << value << " is at index " << last_position << endl;
	cout << endl;

	//Sort list using insertion sort
	cout << "Q3:" << endl;

	list<int> myList = { 5, 4, 3, 2, 1 };

	cout << "Before sorting: ";
	for (int n : myList) {
		cout << n << " ";
	}
	cout << endl;

	//sort list and display it
	insertion_sort(myList);

	cout << "After sorting: ";
	for (int n : myList) {
		cout << n << " ";
	}
	cout << endl;

	










}




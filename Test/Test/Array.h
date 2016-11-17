#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define INCRE 2;	// incremental factor 
// when the array is full, the array's size will be multiplied by incremental factor

template<typename T> class Array {
public:
	// constructor
	Array(int size = 10);

	// copy Constructor
	Array(const Array & a);

	// destructor
	inline ~Array();

	// initiate the array
	void init();

	// print the array
	void printArray();

	// check if the array is Empty
	inline bool isEmpty();

	// check if the array is full
	inline bool isFull();

	// get the size of an array
	inline int getSize();

	// set the size of an array
	void setSize(int size);

	// get the number of elements in the array
	inline int getEleNumber();

	// get the element of index i
	T& operator[](int index);
	
	// add an element at the index i
	void addElement(int index, T element);

	// add a last element
	void addLast(T element);

	// add a first element
	void addFirst(T element);

	// delete the element at the index i
	void removeElement(int index);

	// delete the first element
	void removeFirst();

	// delete the last element
	void removeLast();

	// increase the size of an array
	void resize(int n);

private:
	// relocate the elements between the index of first and last (mode = 0 ; push backward, mode =1 ; push forward)
	void relocate(int first, int last, int mode);

	T* arr;		
	int top;	// index of the last element
	int size;	// Size of an array
};

// constructor
template <typename T> Array<T>::Array(int size = 10) {
	// set the size of an array
	this->size = size;

	// allocate memories needed for an array
	this->arr = new T[size];

	// initate the values of elements
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = 0;
	}

	// set the number of elements to zero
	this->top = -1;
}

// copy constructor
template <typename T> Array<T>::Array(const Array & a) {
	cout << "Array copy constructor" << endl;

	// set the size of an array
	this->size = a.getSize();

	// allocate memories needed for an array
	this->arr = new T[this->size];

	// initate the values of elements
	for (int i = 0; i < this->size; i++) {
		if (i < a.getSize()) {
			this->arr[i] = a[i];
		}
		else {
			this->arr[i] = 0;
		}
	}

	// set the number of elements to zero
	this->top = a.getEleNumber()-1;
}

// destructor
template <typename T> Array<T>::~Array() {
	delete[] this->arr;
}

// initiate the array
template <typename T> void Array<T>::init() {
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = NULL;
	}
}

// print the array
template <typename T> void Array<T>::printArray() {
	cout << "=== array ===" << endl;
	for (int i = 0; i <= this->top; i++) {
		cout << " " << this->arr[i] << endl;
	}
	cout << "=============" << endl;
}

// check if the array is Empty
template <typename T> bool Array<T>::isEmpty() {
	if (this->top < 0) {
		return true;
	}

	return false;
}

// check if the array is full
template <typename T> bool Array<T>::isFull() {
	if (this->top+1 == this->size) {
		return true;
	}

	return false;
}

// get the size of an array
template <typename T> int Array<T>::getSize() {
	return this->size;
}

// set the size of an array
template<typename T> void Array<T>::setSize(int size) {
	// reset the size of an array and the last index
	this->size = size;
	this->top = size - 1;

	T* temp = new T[size];

	// the number of elements that will be copied to a new array
	int numEle = this->top + 1;
	if (numEle>size) {
		numEle = size;
	}

	// copy the elements to a new array
	for (int i = 0; i < numEle; i++) {
		temp[i] = this->arr[i];
	}
}

// get the number of elements in the array
template <typename T> int Array<T>::getEleNumber() {
	return this->top + 1;
}

// get the element of index i
template <typename T> T& Array<T>::operator[](int index) {
	// correct index
	if (index >= 0 && index <= this->top+1) {
		// in the case of add a new element
		if (index == this->top + 1) {
			// check if the array is full
			if (this->isFull()) {
				int arraySize = this->size*INCRE;
				this->resize(arraySize);
			}

			this->top++;
		}
		return this->arr[index];
	}

	// index is wrong
	string message = "Wrong index";
	cout << message << " in the getElement function" << endl;
	throw message;
}

// add an element at the index i
template <typename T> void Array<T>::addElement(int index, T element) {
	// check if the array is full
	if (this->isFull()) {
		int arraySize= this->size*INCRE;
		this->resize(arraySize);
	}

	// correct index
	if (index >= 0 && index <= this->top + 1) {
		// relocate the existing elements for new element
		this->relocate(index, this->top, 0);

		this->arr[index] = element;

		// increase the last index
		this->top++;
	}

	// wrong index
	string message = "wrong index";
	cout << message << "in the addElement function" << endl;
	throw message;
}

// add a last element
template <typename T> void Array<T>::addLast(T element) {
	// if the array is full, extend the array
	if (this->isFull()) {
		int arraySize = this->size*INCRE;
		this->resize(arraySize);
	}

	// increase the last index
	this->top++;

	// add the element
	this->arr[this->top] = element;
}

// add a first element
template <typename T> void Array<T>::addFirst(T element) {
	// if the array is full, extend the array
	if (this->isFull()) {
		int arraySize = this->size*INCRE;
		this->resize(arraySize);
	}

	// push back all elements by one index
	this->relocate(0, this->top, 0);

	// increase the last index
	this->top++;

	// add a new element
	this->arr[0] = element;
}

// delete the element at the index i
template <typename T> void Array<T>::removeElement(int index) {
	if (index >= 0 && index <= this->top) {
		// overload the existing element with the other existing element
		this->relocate(index + 1, this->top, 1);

		// decrease the number of element
		this->top--;
	}

	// wrong index
	string message = "wrong index";
	cout << message << "in the removeElement function" << endl;
	throw message;
}

// delete the first element
template <typename T> void Array<T>::removeFirst() {
	if (!this->isEmpty()) {
		this->relocate(1, this->top, 1);

		this->top--;
	}

	string message = "The array is empty";
	cout << message << endl;
	throw message;
}

// delete the last element
template <typename T> void Array<T>::removeLast() {
	if (!this->isEmpty()) {
		this->top--;
	}

	string message = "The array is empty";
	cout << message << endl;
	throw message;
}

// increase the size of an array
template <typename T> void Array<T>::resize(int n) {
		int size = n;			// The number of elements to be copied
		
		if (size > this->size) {
			size = this->size;
		}

		// reset the size of an array
		this->size = n;

		// resize the array 
		T* temp = new T[this->size];

		// copy the elements
		for (int i = 0; i < size; i++) {
			temp[i] = this->arr[i];
		}

		// initiate the other elements
		for (int j = size; j < this->size; j++) {
			temp[j] = 0;
		}

		// delete the previous memories
		delete[] this->arr;

		// repointing
		this->arr = temp;
	}

// relocate the elements between the index of first and last (mode = 0 ; push backward, mode =1 ; push forward)
template <typename T> void Array<T>::relocate(int first, int last, int mode) {
		if (mode == 0) {
			for (int i = last; i >= first; i--) {
				this->arr[i + 1] = this->arr[i];
			}
		}
		else {
			for (int i = first; i <= last; i++) {
				this->arr[first - 1] = this->arr[first];
			}
		}
}
#pragma once
#include "Array.h"
#include <iostream>

using namespace std;
/*Get Size
*Insert
*Remove
*Add
*Resizing
*Get Capacity
*set Capacity*/

template <class V>
class Vector : Array <V>{
private:
	int currsize;
	int increase;
public:
	Vector(); //initializer
	Vector(int _size); //create vector with specified size
	Vector(int _currSize, V& val); //create vector with a specified size and then initialize the elements
	Vector(const Vector<V>& copyVec); //copy constructor
	Vector(const Array<V>& ac); //copy constructor for array
	~Vector(); //destructor
	int getSize() const; //get the vector size
	int getCapacity() const; //get capacity vector size
	void insert(int index, const V& item); //insert item into the vector
	void add(const V& item); //add an item to the back of the vector, similar to a push_back
	void operator=(const Vector<V>& v); //Copy data
	void operator=(const Array<V>& ac); //copy data
	void resize(unsigned int); //resize vector
	void remove(int index); //remove an element
	void setIncFractor(int incr);
	int getIncreaseFactor() const;
};

template <class V>
Vector<V>::Vector() : Array<V>::Array() {
	currsize = 0;
	increase = 5;
}

template <class V>
Vector<V>::Vector(int _size) : Array<V>(_size) {
	currsize = 0;
	increase = _size;
}

template <class V>
Vector<V>::Vector(int _currSize, V& val) : Array<V>(_currSize, val) {
	currsize = _currSize;
	increase = val;
}

template <class V>
Vector<V>::~Vector() {
	currsize = 0;
	increase = 0;
}

template <class V>
Vector<V>::Vector(const Vector<V>& copyVec) : Array<V>(copyVec) {
	currsize = copyVec.currsize;
	increase = copyVec.increase;
}

template <class V>
Vector<V>::Vector(const Array<V>& copyVec) : Array<V>(copyVec) {
	currsize = copyVec.getSize();
	increase = (currsize + 1) / 2;
}

template <class V>
void Vector<V>::operator=(const Vector<V>& v) {
	Array<V>::copy(v);
	currsize = v.currsize;
	increase = v.increase;
}

template <class V>
void Vector<V>::operator=(const Array<V>& ac) {
	Array<V>::copy(ac);
	currsize = ac.getSize();
	increase = (currsize + 1) / 2;
}

template <class V>
int Vector<V>::getSize() const {
	return currsize;
}

template <class V>
int Vector<V>::getCapacity() const {
	return size;
}

template <class V>
int Vector<V>::getIncreaseFactor() const {
	return increase;
}

template <class V>
void Vector<V>::resize(unsigned int size) {
	int curr = this->currsize;

	if (curr > size) { //if current size is larger than the new size
		curr = size;
	}

	V* temp = new V[size]; //create temp array with new size

	if (this->currsize != 0) {
		for (unsigned int i = 0; i < curr; i++) {
			temp[i] = this->arr[i]; //copy current data
		}

		//delete old array
		delete this->arr;
	}

	//set array to temp array
	this->arr = temp;

	//set the new size
	this->size = size;
}

template <class V>
void Vector<V>::setIncFractor(int incr) {
	if (incr >= 0)
		increase = incr;
}

template <class V>
void Vector<V>::insert(int index, const V& item) {
	if ((index < 0) || (index > currsize)) {
		cout << "Throw exception" << endl;
	}

	currsize++;

	for (unsigned int i = currsize - 1; i > index; i--) {
		(*this)[i] = (*this)[i - 1];
	}

	(*this)[index] = item;
}

template <class V>
void Vector<V>::add(const V& item) {
	insert(currsize, item);
}

template <class V>
void Vector<V>::remove(int index) {
	if ((index < 0) || (index > currsize)) {
		cout << "Throw exception" << endl;
	}

	for (unsigned int i = index; i < currsize - 1; i++) {
		(*this)[i] = (*this)[i + 1];
	}

	currsize--;
}
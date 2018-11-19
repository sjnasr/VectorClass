#pragma once
#include <iostream>
using namespace std;

template <class A>
class Array {
private:
	A* arr;
	int size;
public:
	Array();
	Array(int _size); //first constructor
	Array(int _size, const A& val); //second constructor
	Array(const Array& copyArr);
	~Array();
	int getSize() { return size; } //returns the size
	bool isEmpty(); //checks if array is empty
	void copy(const A& ac); //copy the elements
	void operator= (const A& ac);
	A& operator[] (int key);
	void Add(int key, int value);
	int getValue(int key);

	int searchElement(A key);
	A sort();
	friend void swap(A *input, A *input2);
	friend ostream& operator<<(ostream& s, Array<A>& ac);
};
template<class A>
ostream& operator<< (ostream& s, Array<A>& ac) {
	s << "[";

	for (int i = 0; i < ac.size(); i++) {
		if (i > 0) {
			s << ",";
		}
		s << ac[i];
	}

	s << "]";
	return s;
}

template <class A>
Array<A>::Array() {
	size = 0;
	arr = new A[1];
	if (arr == NULL)
		cout << "Do exception handling" << endl;
	size = 1;
}

template <class A>
Array<A>::Array(int _size) {
	this->arr = new A[_size];
	if (arr == NULL) {
		cout << "Do exeception handling" << endl;
	}
	size = _size;
}

template <class A>
Array<A>::Array(int _size, const A& val)
{
	_size = 0;
	arr = new A[_size];
	if (arr == NULL) {
		cout << "Throw exception" << endl;
	}
	size = _size;
	for (int i = 0; i < _size; i++) {
		arr[i] = val;
	}
}

//Copy Constructor
template <class A>
Array<A>::Array(const Array& copyArr) {
	if (&copyArr != this) {
		size = 0; //default in cause allocation fails
		arr = new A[copyArr.size];
		if (arr == NULL)
			cout << "Throw exception here" << endl;
		for (int i = 0; i < size; i++) {
			arr[i] = copyArr.arr[i];
		}
	}
}

template <class A>
Array<A>::~Array() {
	if (arr != NULL)
		delete[] arr;
	arr = NULL;
	size = 0;
}

template <class A>
void Array<A>::copy(const A& ac) {
	size = 0; //default in cause allocation fails
	arr = new A[ac.size];
	if (arr == NULL)
		cout << "Throw exception here" << endl;
	for (int i = 0; i < size; i++) {
		arr[i] = ac.arr[i];
	}
}

template <class A>
void Array<A>::operator= (const A& ac) {
	if (&ac != this) {
		if (arr != NULL) {
			cout << "Throw exception here" << endl;
		}
		copy(ac);
	}
}

template <class A>
bool Array<A>::isEmpty() {
	if (size == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class A>
A& Array<A>::operator[](int key) {
	if (key < 0 || key >= getSize()) {
		cout << "Throw exception here" << endl;
	}

	return arr[key];
}



template <class A>
int Array<A>::searchElement(A key) {
	int left = 0;
	int right = size - 1;
	int mid;

	//Sort the array
	sort();

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] < key) {
			left = mid + 1;
		}
		else if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}


template <class A>
void swap(A *input, A *input2) {
	A temp = *input;
	*input = *input2;
	*input2 = temp;
}
template <class A>
A Array<A>::sort() {
	bool swapped = false;
	A temp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
	}
	return arr;
}

template <class A>
void Array<A>::Add(int key, int value)
{
	arr[key] = value;
}

template<class A>
int Array<A>::getValue(int key)
{
	return arr[key];
}
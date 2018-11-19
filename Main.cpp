#include "Vector.h"

//using namespace std;

int main() {
	Vector<int> v(10);

	//v.getCapacity();
	v.add(10);
	for (int i = 0; i < 10; i++)
	{
		v.insert(i, i);
	}

	v.remove(4);
	return 0;
}
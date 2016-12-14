#include"Array.h"
#include"Point.h"

template<> void Array<int>::temp() {
	cout << "temp" << endl;
}

template<> void Array<Point>::temp() {
	cout << "Point" << endl;
}
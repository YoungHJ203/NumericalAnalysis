#include"Point.h"

// constructor
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

// operator = overloading
void Point::operator=(Point& a) {
	this->x = a.x;
	this->y = a.y;
}

// operator = overloading
void Point::operator=(float* a) {
	int size = _msize(a) / sizeof(float);
	if (size == 2) {
		this->x = a[0];
		this->y = a[1];
	}
	else {
		cout << "Those values can't be assigned" << endl;
		return;
	}
}

// operator overloading
Point& operator+(Point& a, Point& b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point& operator-(Point& a, Point& b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point& operator*(float a, Point& b) {
	return Point(b.x*a, b.y*a);
}

Point& operator*(Point& a, float b) {
	return Point(a.x*b,a.y*b);
}
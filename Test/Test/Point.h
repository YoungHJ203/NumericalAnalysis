#pragma once
#include<memory>
#include<iostream>
using namespace std;

// two-dimensional point
class Point {
public:
	// constructor
	Point(float x=0, float y=0);

	// get and set the x coordinate
	inline float getX();

	inline void setX(float x);

	// get and set the y coordinate
	inline float getY();

	inline void setY(float y);

	// operator = overloading
	void operator=(Point& a);

	// operator = overloading
	void operator=(float* a);

	// operator overloading
	friend Point& operator+(Point& a, Point& b);

	friend Point& operator-(Point& a, Point& b);

	friend Point& operator*(float a, Point& b);

	friend Point& operator*(Point& a, float b);
private:
	float x;
	float y;
};


// get and set the x coordinate
float Point::getX() {
	return this->x;
}

void Point::setX(float x) {
	this->x = x;
}

// get and set the y coordinate
float Point::getY() {
	return this->y;
}

void Point::setY(float y) {
	this->y = y;
}
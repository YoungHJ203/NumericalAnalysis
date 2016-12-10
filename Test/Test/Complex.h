#pragma once
#include<iostream>
using namespace std;

class Complex {
public:
	// default constructor
	Complex() {
		real = imag = 0;
	}

	// convert constructor
	Complex(float real) {
		this->real = real;
		imag = 0;
	}

	// all setting constructor
	Complex(float real, float imag) {
		this->real = real;
		this->imag = imag;
	}

	Complex& operator=(const Complex& a);

	friend ostream& operator<<(ostream&, Complex&);

	friend Complex operator+(const Complex& a, const Complex& b);

private:
	float real, imag;
};

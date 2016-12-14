#include"Complex.h"

Complex& Complex::operator=(const Complex& a){
	this->real = a.real;
	this->imag = a.imag;
	return *this;
}

Complex operator+(const Complex& a, const Complex& b) {
	return Complex(a.real + b.real, a.imag + b.imag);
}

ostream& operator<<(ostream& os, Complex& c) {
	return os << c.real << "+ " << c.imag << 'i';
}
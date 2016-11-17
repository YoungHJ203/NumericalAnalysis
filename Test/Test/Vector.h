#pragma once
#include<iostream>
using namespace std;

// Vector class
class Vector {
public:
	// constructor 
	Vector() {
		vector = new float[3];
		
		// 
		size = 3;
	}


private:
	float* vector;
	int size;			// vector size
};
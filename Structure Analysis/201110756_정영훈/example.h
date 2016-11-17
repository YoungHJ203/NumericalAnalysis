#ifndef EXAMPLE
#define EXAMPLE
using namespace std;
#include<iostream>
#include<fstream>

// example class
class example {

public:

	example() {};
	~example() {};

	// 시간에 따른 속도를 출력하는 함수 (근사식)
	void printVelocity(float, float ,float, float, int);

	// 시간에 따른 속도를 출력하는 함수 (정확한 식)
	void printExactVelocity(float,float,float,float);

	// 제곱함수
	float exponential(float, int);
}; 
#endif

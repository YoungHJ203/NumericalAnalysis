#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Polynominal.h"
using namespace std;
#define LIMIT 0.001	// 함수의 미분값을 추적하기 위한 한계값

// Newton-Raphson Method 
class NR {
public:
	// Newton-Raphson Method
	static float method(Polynominal, float, int, int);

	// Graphical method
	static void showGraph(Polynominal,float,float,float);

private:
	// Newton-Raphson Method 작동부
	static float subMethod(Polynominal, float,int,int);
};

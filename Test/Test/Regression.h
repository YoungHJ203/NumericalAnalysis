#pragma once
#include"Matrix.h"
#include"Point.h"
#include"GE.h"
#include<fstream>
#include<vector>

// Polynominal Regression Class
class Regression {
public:
	// constructor (default polynominal's order = 1)
	Regression(int n = 1);

	// destructor
	~Regression();

	// enter data points by hand
	void input();

	// enter data points through array
	void input(Array<Point>& a);

	// check if the regression is done
	bool isDone();

	// regress the given data points
	void regress();

	// print the regression function
	void printRegression();

	// save the regression function's coeffcients
	void saveRegression();
private: 
	// calculate the sum of the squares of deviation, St 
	// and calculate the sum of the squares of errors
	void calStAndSr();

	// Matrix that stores data points
	Matrix a;			// regressed polynominal coefficients	
	Matrix y;			// dependant data points
	Matrix x;			// independent data points
	int order;			// polynominal's order
	int numData;		// The number of data points
	int status;			// check whether the regression is done
	float St;			// Total sum of the squares of deviation
	float Sr;			// Sum of the squares of errors
};


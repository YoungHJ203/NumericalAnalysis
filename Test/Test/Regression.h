#pragma once
#include"Matrix.h"

// Polynominal Regression Class
class Regression {
public:
	// constructor (default polynominal's order = 1)
	Regression(int n=1) {
		// polynominal's order
		this->order = 1;

		// set the number of data points
		this->numData = 0;

		// status shows that regression isn't done
		this->status = 0;

		// The number of data points at least that are needed
		int m = this->order + 1;

		// set the Matrix that is needed
		a.resize(m, 1);
		y.resize(m, 1);
		x.resize(m, m);	
	}

	// destructor
	~Regression() {
		// return memories that are not needed anymore
		a.~Matrix();
		y.~Matrix();
		x.~Matrix();
	}

	// data input
	void input() {
		
	}

	// regress the given data points
	void regress() {
		int m = this->order + 1;		// The number of data points that are needed to regress

		// condition where data points can be regressed
		if (this->numData >= m) {
			// multiply transposed x and x

			// inverse matrix of temp

			// get the coefficients of regression function

		}

		// when the more data points are needed
		else {
			cout << "The more data points are needed to regress" << endl;
			return;
		}
	}

	// print the regression function
	void printRegression() {
	
	
	}

	// save the regression function's coeffcients
	void saveRegression() {
	
	}

private:
	// Matrix that stores data points
	Matrix a;			// regressed polynominal coefficients	
	Matrix y;			// dependant data points
	Matrix x;			// independent data points
	int order;			// polynominal's order
	int numData;		// The number of data points
	int status;			// check whether the regression is done
};
#pragma once
#include"GE.h"

class LU {
public:
	// constructor
	LU(Matrix & a) {
	
	}

	// LU decomposition
	void Decomposition(Matrix& a) {

	}

	// return L Matrix
	Matrix getL() {
		return L;
	}

	// return U Matrix
	Matrix getU() {
		return U;
	}
private:
	Matrix L;		// Lower triangular Matrix
	Matrix U;		// Upper triangular Matrix
};

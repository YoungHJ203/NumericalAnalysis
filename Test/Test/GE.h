#pragma once
#include"Matrix.h"

// Gauss-Elimination
class GE {
public:
	// Gauss Elimination (x*a = y ; a is a solution matrix)
	static Matrix elimination(Matrix x,Matrix y) {
		if (isValid(x,y)) {
			int row = x.getNRow();		// The number of Rows
			int col = x.getNCol();		// The number of Columns
			Array<float> temp(row);		// To store the answer temporarly

			// forward elimination
			for (int i = 1; i <= row ; i++) {
				// scale each row and get the row at which the scaled value is max
				int pRow = scaling(x,i);

				// partial pivoting
				if (i != pRow) {
					pivoting(x, i, pRow);
					pivoting(y, i, pRow);
				}
				

				// elimination at each row
				for (int j = i+1; j <= row; j++) {
					float factor = x(j, i) / x(i, i);
					x(j, i) = 0;					
					y(j, 1) = y(j, 1)-y(i, 1)*factor;

					for (int k = i + 1; k <= col; k++) {
						x(j, k) = x(j, k) - x(i, k)*factor;
					}
				}
			}
			x.printMatrix();
			y.printMatrix();
			// backward substitution
			for (int i = row; i >= 1; i--) {
				float sum = 0;

				// summation of all terms in the left side except the x(i,i)*a(i,1) ( x(i,i)*a(i,1) + sum = y(i,1) )
				for (int j = i + 1; j <= col; j++) {
					sum += temp[row - j]*x(i, j);
				}

				// To correct use of array, we should enter the data reversely
				temp[row - i] = (y(i, 1) - sum) / x(i, i);
			}
			temp.reverse();

			Matrix a(row, 1,temp);			// solution of linear algebraic equation
			return a;
		}
	}

private:
	// pivoting
	static void pivoting(Matrix& a, int current, int pivot) {
		for (int i = 1; i <= a.getNCol(); i++) {
			swap(a(current, i), a(pivot, i));
		}
	}

	// scaling and getting the row at which the scaled value is max
	static int scaling(Matrix& a, int row) {
		int maxRow = 0;		// row number at which the scaling number is max
		float maxValue = 0;		// max value scaled

		// scaling each rows
		for (int i = row; i <= a.getNRow(); i++) {
			int max = 0;

			// get the max value at each row
			for (int j = row; j <= a.getNCol();j++) {
				if (abs(a(i, j)) > max) {
					max = a(i, j);
				}
			}

			// in the case where the elimination can't be proceeded
			if (max == 0) {
				cout << "Unable to proceed the elimination" << endl;
				exit(0);
			}

			// set the max value and row 
			if (maxValue < abs(a(i, row) / max)) {
				maxValue = abs(a(i, row) / max);
				maxRow = i;
			}
		}

		return maxRow;
	}

	// absolute value of a number
	static float abs(float a) {
		if (a >= 0) {
			return a;
		}	
		return -a;
	}

	// swap the values
	static void swap(float& a, float& b) {
		float temp = a;
		a = b;
		b = temp;
	}

	// check if the matrix is square matrix or not
	static bool isSquare(Matrix& a) {
		if (a.getNRow() == a.getNCol()) {
			return true;
		}

		return false;
	}

	// check if those matrices are valid
	static bool isValid(Matrix& a,Matrix& b) {
		// It is possible to proceed the Gauss-elimination
		if (isSquare(a) && a.getNRow() == b.getNRow()) {
			return true;
		}

		// It is not possible to procceed the Gauss-elimination
		return false;
	}
};
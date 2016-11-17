#include"Matrix.h"

int main() {
	Matrix a(3, 3);	// 3*3 Matrix construct
	Matrix b(3, 3);	// 3*3 Matrix construct
	
	// set the initial value
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			a(i, j) = i + j;
			b(i, j) = i - j;
		}		
	}


	// check if those two matrices are same
	if (a == b) {
		cout << "\'A\' matrix is same with \'B\' matrix" << endl;
	}
	else {
		cout << "\'A\' matrix is different with \'B\' matrix" << endl;
	}

	// show each matrix's element
	cout << "\'A\' Matrix" << endl;
	a.printMatrix();

	cout << "\'B\' Matrix" << endl;
	b.printMatrix();


	cout << endl;
	cout << endl;

	Matrix c(3, 3);

	// summation
	cout << "summation of two matrices" << endl;
	c = a + b;
	cout << c << a << b;
	
	// subtraction
	cout << "subtraction of two matrices" << endl;
	c = a - b;
	cout << c;

	// multipulation
	cout << "multipulation of two matrices" << endl;
	c = a * b;
	cout << c;
}
#include"Matrix.h"

// default constructer
Matrix::Matrix() {
	this->nRow = 1;
	this->nCol = 1;
	int size = this->nRow*this->nCol;
	this->matrix.resize(size);
}

// copy constructor
Matrix::Matrix(Matrix & a) {
	this->nRow = a.nRow;
	this->nCol = a.nCol;
	int size = this->nRow*this->nCol;

	// reallocate the memories for a new matrix
	this->matrix.resize(size);
	
	// copy each value to the new matrix
	for (int i = 1; i <= this->nRow; i++) {
		for (int j = 1; j <= this->nCol; j++) {
			(*this)(i,j)= a(i,j);
		}
	}

#ifdef DEBUG
	cout << "Matrix copy constructor" << endl;
#endif

}

// size setting constructor
Matrix::Matrix(int nRow, int nCol) {
	this->nRow = nRow;
	this->nCol = nCol;
	int size = nRow*nCol;
	this->matrix.resize(size);
}

// general constructor
Matrix::Matrix(int nRow, int nCol, Array<float> a) {
	this->nRow = nRow;
	this->nCol = nCol;
	int size = this->nRow*this->nCol;

	if (size == a.getSize()) {
		this->matrix.resize(size);

		// copy each 
		for (int i = 0; i < this->nRow; i++) {
			for (int j = 0; j < this->nCol; j++) {
				this->matrix[i*this->nCol + j] = a[i*this->nCol+ j];
			}
		}
	}
	else {
		// throw exception
		string msg = "A copy constructor can't be proceeded";
		cout << msg << endl;
		throw msg;
	}
}

// convert constructor
Matrix::Matrix(float i) {
	this->nRow = 1;
	this->nCol = 1;

	// resize the matrix
	this->matrix.resize(1);

	// allocate the matrix
	(*this)(1, 1) = i;
}

// destructor
Matrix::~Matrix() {}

// print a matrix
void Matrix::printMatrix() {
	cout << "*** Matrix element ***" << endl;
	for (int i = 0; i < this->nRow; i++) {
		cout << "  ";
		for (int j = 0; j < this->nCol; j++) {
			cout << this->matrix[i*this->nCol+ j];
			cout << "\t";
		}
		cout << endl;
	}
	cout << "***********************" << endl;
}

// enter all elements directly by the user
void Matrix::enterEle() {
	// enter the entries of a matrix
	cout << endl;
	for (int i = 0; i < this->nRow; i++) {
		cout << "row " << i + 1 << " : ";
		for (int j = 0; j < this->nCol; j++) {
			cin >> this->matrix[i*nCol + j];
		}
	}
}

// get the number of Rows
unsigned int Matrix::getNRow() const {
	return this->nRow;
}

// get the number of Columns
unsigned int Matrix::getNCol() const {
	return this->nCol;
}

// reallocate the matrix
void Matrix::resize(unsigned int nRow, unsigned int nCol) {
	int row = this->nRow;	// The number of Rows to be copied
	int col = this->nCol;	// The number of Columns to be copied

	if (row > nRow) {
		row = nRow;
	}

	if (col > nCol) {
		col = nCol;
	}


	this->nRow = nRow;
	this->nCol = nCol;

	// new matrix that store temporarly the elements
	Matrix temp(nRow, nCol);

	// copy the elements of an existing matrix to the new matrix
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			temp(i, j) = (*this)(i, j);
		}
	}

	// reallocate the matrix
	this->matrix.resize(this->nRow*this->nCol);

	// recopy the elements of a new matrix to the existing matrix
	for (int i = 1; i <= this->nRow; i++) {
		for (int j = 1; j <= this->nCol; j++) {
			if (i <= row && j <= col) {
				(*this)(i, j) = temp(i, j);
			}
			else {
				(*this)(i, j) = 0;
			}
		}
	}
}

// reset the number of rows
void Matrix::setRow(unsigned int nRow) {
	this->resize(nRow, this->nCol);
}

// reset the number of columns
void Matrix::setCol(unsigned int nCol) {
	this->resize(this->nCol, nRow);
}

// method operator overloading
// allocate operator overloading
void Matrix::operator=(Matrix & a) {
	if (this->nRow != a.nRow || this->nCol != a.nCol) {
		this->nRow = a.nRow;
		this->nCol = a.nCol;
		// memory allocate for copying new elements
		this->matrix.resize(this->nRow*this->nCol);
	}

	for (int i = 1; i <= this->nRow; i++) {
		for (int j = 1; j <= this->nCol; j++) {
			(*this)(i, j) = a(i, j);
		}
	}

}

// function operator overloading (getting element)
float& Matrix::operator()(int row, int col) {	// get the element of (i,j)
												// check the given indices
	if (row >= 1 && row <= nRow && col >= 1 && col <= nCol) {
		return this->matrix[(row - 1)*this->nCol + (col - 1)];
	}

	// In the case of wrong index given
	string msg = "wrong index is given";
	cout << msg << endl;
	throw msg;
}

// function operator overloading
// + operator overloading
Matrix operator+(Matrix & a, Matrix & b) {
	// condition needed for matrix subtraction
	if (a.nRow == b.nRow && a.nCol == b.nCol) {
		Matrix c(a.nRow, a.nCol);

		for (int i = 1; i <= c.nRow; i++) {
			for (int j = 1; j <= c.nCol; j++) {
				c(i, j) = a(i, j) + b(i, j);
			}
		}

		return c;
	}

	// case where the subtraction isn't able to be proceeded
	string msg = "Unable to proceed the summation";
	cout << msg << endl;
	throw msg;
  }

// - operator overloading
Matrix operator-(Matrix & a, Matrix & b) {
	// condition needed for matrix subtraction
	if (a.nRow == b.nRow && a.nCol == b.nCol) {
		Matrix c(a.nRow, a.nCol);

		for (int i = 1; i <= c.nRow; i++) {
			for (int j = 1; j <= c.nCol; j++) {
				c(i, j) = a(i, j) - b(i, j);
			}
		}

		return c;
	}

	// case where the subtraction isn't able to be proceeded
	string msg = "Unable to proceed the subtraction";
	cout << msg << endl;
	throw msg;
}

// * operator overloading
Matrix operator*(Matrix & a, Matrix & b) {
	// condition needed for matrix multipulation
	if (a.nCol == b.nRow) {
		Matrix c(a.nRow,b.nCol);
		 
		for (int i = 1; i <= c.nRow; i++) {
			for (int j = 1; j <= c.nCol; j++) {
				float sum = 0;
				for (int k = 1; k <= a.nCol; k++) {
					sum += a(i, k)*b(k, j);
				}
				c(i, j) = sum;
			}
		}

		return c;
	}
	// constant multiplation
	else if (a.nRow == 1 && a.nCol == 1) {		// in the case that 'a' is constant
		for (int i = 1; i <= b.nRow; i++) {
			for (int j = 1; j <= b.nCol; j++) {
				b(i, j) *= a(1, 1);
			}
		}
	}
	else if (b.nRow == 1 && b.nCol == 1) {		// in the case that 'b' is constant
		for (int i = 1; i <= a.nRow; i++) {
			for (int j = 1; j <= a.nCol; j++) {
				a(i, j) *= b(1, 1);
			}
		}
	}

	// case where the multipulation isn't able to be proceeded
	string msg = "Unable to proceed the multipulation";
	cout << msg << endl;
	throw msg;
}

// == operator overloading
bool operator==(Matrix & a, Matrix & b) {
	// When those matrices have same size, they can be compared 
	if (a.nRow == b.nRow && a.nCol == b.nCol) {
		// All entities are compared 
		for (int i = 1; i <= a.nRow; i++) {
			for (int j = 1; j <= a.nCol; j++) {
				if (a(i,j) != b(i,j)) {
					return false;
				}
			}
		}
		return true;
	}

	return false;
}

ostream& operator<<(ostream& os, Matrix & a) {
	cout << "*** Matrix element ***" << endl;
	for (int i = 0; i < a.nRow; i++) {
		cout << "  ";
		for (int j = 0; j < a.nCol; j++) {
			cout << a.matrix[i*a.nRow + j];
			cout << "\t";
		}
		cout << endl;
	}
	cout << "***********************" << endl;

	return cout;
}
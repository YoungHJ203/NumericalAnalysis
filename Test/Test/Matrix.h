#pragma once
#include<iostream>
#include"Array.h"
using namespace std;

// two dimensional matrix class
class Matrix {
public:
	Matrix();									// default constructer
	Matrix(Matrix & a);							// copy constructor
	Matrix(int nRow, int nCol);					// general constructor
	Matrix(int nRow, int nCol, Array<float> a);	// general constructor
	Matrix(float i);							// convert constructor

	// destructor
	~Matrix();

	// print a matrix
	void printMatrix();

	// enter all elements directly by the user
	void enterEle();

	// get the number of Rows
	unsigned int getNRow() const;

	// get the number of Columns
	unsigned int getNCol() const;

	// reallocate the matrix
	void resize(unsigned int nRow, unsigned int nCol);

	// reset the number of rows
	void setRow(unsigned int nRow);

	// reset the number of columns
	void setCol(unsigned int nCol);

	// method operator overloading
	// allocatie operator overloading
	void operator=(Matrix & a);

	// function operator overloading 
	float& operator()(int row, int col);

	// function operator overloading
	// + operator overloading
	friend Matrix operator+(Matrix & a, Matrix & b);

	// - operator overloading
	friend Matrix operator-(Matrix & a, Matrix & b);

	// * operator overloading
	friend Matrix operator*(Matrix & a, Matrix & b);

	// == operator overloading
	friend bool operator==(Matrix & a, Matrix & b);

	// out stream operator overloading 
	friend ostream& operator<<(ostream& os, Matrix & a);
private:
	unsigned int nRow;		// the number of Rows
	unsigned int nCol;		// the number of Columns
	Array<float> matrix;	// matrix
};
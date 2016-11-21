#include"Regression.h"

// constructor (default polynominal's order = 1)
Regression::Regression(int n) {
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
Regression::~Regression() {}

// enter data points by hand
void Regression::input() {
	// current number of data points that are already entered
	int numD = this->numData;	
	// the number of data points that can be more enterd
	int residual = this->a.getNRow() - numD;	

	// when the memories are defficient
	if (residual <= 0) {
		this->a.setRow(this->a.getNRow() + 1);
		this->x.setRow(this->x.getNRow() + 1);
		this->y.setRow(this->y.getNRow() + 1);
	}

	// enter the data
	cout << "======== " << numD + 1 << " ========" << endl;
	cout << "y = " << endl;
	cin >> this->y(numD + 1, 1);

	for (int i = 1; i <= this->order + 1; i++) {
		cout << "x" << i - 1 << " = ";
		cin >> this->x(numD + 1, i);
	}

	cout << "==================================" << endl;
}

// enter data points through array
void Regression::input(Array<Point>& a) {
	// current number of data points that are already entered
	int numD = this->numData;	
	// the number of data points that are going to be entered
	int size = a.getEleNumber();		
	// the number of data points that can be entered more 
	int residual = this->a.getNRow() - numD;	

	// check if the object has enough memories
	if (residual<size) {
		this->a.setRow(numD + size);
		this->x.setRow(numD + size);
		this->y.setRow(numD + size);
	}

	// input the data points into the matrices that are needed for regression
	for (int i = numD; i < numD + size; i++) {
		this->y(i + 1, 1) = a[i].getY();
		float coef = 1;

		for (int j = 1; j <= this->order + 1; j++) {
			this->x(i + 1, j) = coef;
			coef *= a[i].getX();
		}
	}

	// increase the number ;of input data points
	this->numData += size;
}

// check if the regression is done
bool Regression::isDone() {
	return this->status;
}

// regress the given data points
void Regression::regress() {
	// The number of data points that are needed to regress
	int m = this->order + 1;		

	// condition where data points can be regressed
	if (this->numData >= m) {
		// multiply transposed x and x
		Matrix temp = x.Trans()*x;
		x.printMatrix();
		y.printMatrix();
		temp.printMatrix();
		Matrix right = x.Trans()*y;
		right.printMatrix();
		// get the coefficients of regression function
		this->a = GE::elimination(temp, right);

		// change the status 
		this->status = 1;

		this->calStAndSr();
	}

	// when the more data points are needed
	else {
		cout << "The more data points are needed to regress" << endl;
		return;
	}
}

// print the regression function
void Regression::printRegression() {
	if (this->isDone()) {
		cout << "regression polynominal function" << endl;
		cout << "y = ";
		for (int i = 0; i < this->order + 1; i++) {
			cout << this->a(i + 1, 1);
			if (i > 0) {
				cout << "x^" << i;
			}
			if (i != this->order) {
				if (this->a(i + 2, 1) >= 0) {
					cout << "+";
				}
			}
		}

		cout << endl;
		cout << "St = " << this->St << endl;
		cout << "Sr = " << this->Sr << endl;

	}
}

// save the regression function's coeffcients
void Regression::saveRegression() {
	if (this->isDone()) {
		// out file stream
		ofstream ofs;

		// file open by write mode 
		ofs.open("regression.csv", ios::out);

		// unable to open the file
		if (!ofs) {
			cout << "Unable to open the file" << endl;
			exit(0);
		}

		// writing
		for (int i = 0; i < this->order + 1; i++) {
			ofs << this->a(i + 1, 1) << ",";
		}
		ofs << endl;
		ofs << this->St << endl;
		ofs << this->Sr << endl;

		// file close
		ofs.close();
	}
}

// calculate the sum of the squares of deviation, St 
// and calculate the sum of the squares of errors
void Regression::calStAndSr() {
	// set the regression characteristic value equal to zero
	this->Sr = 0;
	this->St = 0;

	// mean value of y's
	float mean = 0;
	for (int i = 1; i <= numData; i++) {
		mean += y(i, 1);
	}
	mean /= numData;

	for (int i = 1; i <= this->numData; i++) {
		this->St += (y(i, 1) - mean)*(y(i, 1) - mean);

		float sum = 0;
		for (int j = 1; j <= this->order + 1; j++) {
			sum += x(i, j)*a(j, 1);
		}

		this->Sr += (y(i, 1) - sum)*(y(i, 1) - sum);
	}
}

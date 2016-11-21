#include"Matrix.h"
#include"Regression.h"

int main() {
	// first order polynominal regression
	Regression example(1);
	// Data points
	Array<Point> a;
	
	Point temp(5, 30);
	a.addLast(temp);
	temp.setX(6);
	temp.setY(22);
	a.addLast(temp);
	temp.setX(10);
	temp.setY(28);
	a.addLast(temp);
	temp.setX(14);
	temp.setY(14);
	a.addLast(temp);
	temp.setX(16);
	temp.setY(22);
	a.addLast(temp);
	temp.setX(20);
	temp.setY(16);
	a.addLast(temp);
	temp.setX(22);
	temp.setY(8);
	a.addLast(temp);
	temp.setX(28);
	temp.setY(8);
	a.addLast(temp);
	temp.setX(28);
	temp.setY(14);
	a.addLast(temp);
	temp.setX(36);
	temp.setY(0);
	a.addLast(temp);
	temp.setX(38);
	temp.setY(4);
	a.addLast(temp);
	example.input(a);

	// regress to the given data points
	example.regress();

	// print the solution
	example.printRegression();

	// save the solution
	example.saveRegression();
}

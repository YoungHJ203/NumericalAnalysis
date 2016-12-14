#include"RK.h"

int main() {	
	// initialize the Ordinary Differential Equation
	Polynomial ODE(2);
	ODE.getCoef(2) = 1;		// set the coefficient of the second order term
	ODE.getCoef(1) = -1;	// set the coefficient of the first order term
	ODE.getCoef(0) = 0;		// set the coefficient of the constant term
	float ti = 0;			// initial time
	float yi = 1;			// initial function value
	float tf = 3;			// final time
	float h = 0.1;			// time size

	// heun method 
	RK::method(ODE, ti, yi, tf, h, 0);

	// ralston's second order method
	RK::method(ODE, ti, yi, tf, h, 1);

	// euler's method
	RK::method(ODE, ti, yi, tf, h, 2);

	// exact solution
	ODE.setPoly(3);
	ODE.getCoef(3) = 1.0/3.0;
	ODE.getCoef(2) = -1.0/2.0;
	ODE.getCoef(1) = 0;
	ODE.getCoef(0) = 1;
	ODE.printValue(ti, tf, h); 
}

/*
#include"Matrix.h"
#include"Regression.h"
<<<<<<< HEAD
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>

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

	Array<int> temp1;
	temp1.temp();

	a.temp();

	vector<int> b;

	vector<char> ::const_iterator i;
	vector<char> str;

	str.insert(str.begin(), 'a');
	str.insert(str.begin(), 'b');
	str.insert(str.begin(), 'c');
	str.insert(str.begin(), 'd');
	str.insert(str.begin(), 'e');
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = 'e';

	vector<char>::iterator k;
	k = str.end();
	k--;
	str.erase(k);

	i = str.begin();
	while (i != str.end()) {
		cout << *i << endl;
		i++;
	}

	deque<int> j;

	list<int> l;
	l.insert(l.begin(), 5);

	list<int>::iterator it_list;
	it_list = l.begin();

	cout << *it_list << endl;

	set<int> s;
	s.insert(5);
	cout << s.size() << endl;

	s.erase(s.begin());
	cout << s.size() << endl;

	map<string, int> m;
	m["one"] = 1;
	m["two"] = 2;
	m["three"] = 3;
	m["four"] = 4;

	vector<int> fibs(32);
	fibs[0] = fibs[1]=1;
	for (int i = 2; i < 32; i++) {
		fibs[i] = fibs[i - 1] + fibs[i - 2];
	}

	ostream_iterator<int> stdOutData(cout, "\n");
	copy(fibs.begin(),fibs.end(), stdOutData);
}
 
=======
#include"Complex.h"
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

example.regress();

example.printRegression();

int a = 1, b = 2;
int c;
Complex c1;

// It may conflict when the convert constructor and conversion constructor are defined
c = a + b;
c1 = a + b;*/
>>>>>>> e4dc7ee93f5f352324dd57ee7bbdcdf785e80acb

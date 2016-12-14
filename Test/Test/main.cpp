#include"Matrix.h"
#include"Regression.h"
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
 
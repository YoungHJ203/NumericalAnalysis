#include<iostream>
#include"example.h"
#include"NR.h"

int main() {
	
	// ���׽� �Լ� �����
	float* coefficients = new float[4];

	coefficients[0] = 0.5;
	coefficients[1] = -4;
	coefficients[2] = 6;
	coefficients[3] = -2;
	
	Polynominal p(coefficients);

	// Newton Raphson Method ���
	// Polynominal, �ʱⰪ 4.2, ��ȿ���� 3�ڸ�, �ִ� iteration Ƚ�� 30ȸ 
	cout << NR::method(p, 4.2, 3, 30) << endl;	
	// Polynominal, �ʱⰪ 4.43, ��ȿ���� 3�ڸ�, �ִ� iteration Ƚ�� 30ȸ 
	cout << NR::method(p, 4.43, 3, 30) << endl;	

	// Graphical Method ���
	// Polynominal, x ������ ���Ѱ� 0, x������ ���Ѱ� 7, x���� 0.1
	NR::showGraph(p, 0, 7 , 0.001);	
}


//example a;

//// Delta T�� 0.5s �ϋ�, �ʱ� �ð� 0, ���� �ð� 20, �ʱ� �ӵ� 0, ��ȿ���� 3�ڸ�
//// approximate velocity ���
//a.printVelocity(0,20,0,0.5,3);
//
//cout << endl;
//cout << endl;
//cout << endl;

//// Delta T�� 1.0s �ϋ�, �ʱ� �ð� 0, ���� �ð� 20, �ʱ� �ӵ� 0, ��ȿ���� 3�ڸ�
//// approximate velocity ���
//a.printVelocity(0, 20,0,1,3);

//cout << endl;
//cout << endl;
//cout << endl;

//// Delta T�� 2.0s �ϋ�, �ʱ� �ð� 0, ���� �ð� 20, �ʱ� �ӵ� 0, ��ȿ���� 3�ڸ�
//// approximate velocity ���
//a.printVelocity(0,20, 0, 2, 3);

//cout << endl;
//cout << endl;
//cout << endl;

//// �ʱ� �ð� 0, ���� �ð� 20, �ʱ� �ӵ� 0, �ð����� 0.5s, ��ȿ���� 3�ڸ�
//// Exact velocity ���
//a.printExactVelocity(0, 20, 0, 0.5);



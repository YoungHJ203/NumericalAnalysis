#ifndef EXAMPLE
#define EXAMPLE
using namespace std;
#include<iostream>
#include<fstream>

// example class
class example {

public:

	example() {};
	~example() {};

	// �ð��� ���� �ӵ��� ����ϴ� �Լ� (�ٻ��)
	void printVelocity(float, float ,float, float, int);

	// �ð��� ���� �ӵ��� ����ϴ� �Լ� (��Ȯ�� ��)
	void printExactVelocity(float,float,float,float);

	// �����Լ�
	float exponential(float, int);
}; 
#endif

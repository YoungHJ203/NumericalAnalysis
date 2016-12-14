#pragma once
#include<iostream>
#define FMAX 3.402823466e+38	// float �ڷ����� ���� �� �ִ� �ִ�
using namespace std;

class Polynomial {
public:
	// n�� ���׽� ������
	Polynomial(int);

	// ����� ��� ������ n�� ���׽� ������
	Polynomial(float[]);

	// copy ������
	Polynomial(Polynomial&);

	// �Ҹ���
	~Polynomial();

	// ���׽� ����� �Լ� (���׽��� ������� �Է��ؼ� ����)
	void makePoly();

	// ���� ���׽��� �̺�
	void diffPoly();

	// ���׽� ���� �� ��� �缳���ϴ� �Լ�
	void setPoly(int);

	// �Լ����� ��ȯ�ϴ� �Լ�
	float operator()(float);

	// ���׽��� ������ ��ȯ
	inline int getOrder();

	// n������ ����� ��ȯ
	float& getCoef(int n);

	// �Լ��� ���
	void printValue(float, float, float);

private:
	int order;		// ���׽� ����
	float* poly;	// ���׽� ����� ������ �迭

	// �ŵ����� ���� (�� �ŵ����� n�� 0�� ������ ���� ����)
	float expo(float a, int n);

};

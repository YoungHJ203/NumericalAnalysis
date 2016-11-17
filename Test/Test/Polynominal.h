#pragma once
#include<iostream>
#define FMAX 3.402823466e+38	// float �ڷ����� ���� �� �ִ� �ִ�
using namespace std;

class Polynominal {
public:
	// n�� ���׽� ������
	Polynominal(int);

	// ����� ��� ������ n�� ���׽� ������
	Polynominal(float[]);

	// copy ������
	Polynominal(Polynominal&);

	// �Ҹ���
	~Polynominal();

	// ���׽� ����� �Լ� (���׽��� ������� �Է��ؼ� ����)
	void makePoly();

	// ���� ���׽��� �̺�
	void diffPoly();

	// ���׽� ���� �� ��� �� �����ϴ� �Լ�
	void setPoly(int);

	// �Լ����� ��ȯ�ϴ� �Լ�
	float value(float);

	// ���׽��� ������ ��ȯ
	inline int getOrder();

	// n������ ����� ��ȯ
	float getCoef(int n);

private:
	// private default ������ 
	Polynominal() {};

	int order;		// ���׽� ����
	float* poly;	// ���׽� ����� ������ �迭

	// �ŵ����� ���� (�� �ŵ����� n�� 0�� ������ ���� ����)
	float expo(float a, int n);

};

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
	int getOrder() {
		return this->order;
	}

	// ���׽� ����� ��ȯ
	float getCoef(int n) {
		float coef = 0;

		try {
			coef=this->poly[this->order-n];
		}
		catch (out_of_range e) {
			cout << "The order enterd exceeds the maximun of range" << endl;

			// error�� ��� float�� ���� �� �ִ� �ִ��� retrun 
			return FMAX;
		}
		
		return coef;
	}

private:
	// private default ������ 
	Polynominal() {};

	int order;		// ���׽� ����
	float* poly;	// ���׽� ����� ������ �迭

	// �ŵ����� ���� (�� �ŵ����� n�� 0�� ������ ���� ����)
	float expo(float a, int n) {
		if (n >= 0) {
			float result = 1;
			for (int i = 0; i < n; i++)
				result = result*a;

			return result;
		}
		

		cout << "The order enterd is smaller than zero" << endl;
		return FMAX;
	}

};

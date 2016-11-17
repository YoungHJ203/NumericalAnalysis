#include"Polynominal.h"
#include<memory>

// n�� ���׽� ������
Polynominal::Polynominal(int n) {
	// ���׽��� ��� ����
	this->order = n;	// n����

	// n�� ���׽��� ����� ������ �迭 ����
	this->poly = new float[n+1];
}

// ����� ��� ������ n�� ���׽� ������
Polynominal::Polynominal(float poly[]) {
	int n= _msize(poly)/sizeof(float)-1;	// �Ѿ�� ������� ���׽� ���� ���

	// ���׽� ���� ����
	this->order = n;

	// ���׽� ������� ������ �迭 ����
	this->poly = new float[n + 1];

	// �ռ� �Ѿ�� ������� ���� ���׽� ����� ������ ����
	for (int i = 0; i <= n; i++) {
		this->poly[i] = poly[i];
	}
}

// copy ������
Polynominal::Polynominal(Polynominal& poly) {
	
	// �ٸ� ���׽��� ���� ���׽����� ����
	int n = poly.getOrder();			// �Ѿ�� ���׽��� ���� ���

	// ���� ���� 
	this->order = n;

	// ������� ������ �޸� �Ҵ�
	this->poly = new float[n + 1];

	// ����� ����
	for (int i = 0; i <= n; i++) {
		this->poly[i] = poly.getCoef(n-i);		// n�� ������� ������� ����
	}
}

// �Ҹ���
Polynominal::~Polynominal() {
	// ������� ������ �迭�� �Ҵ�� �޸� ����
	delete[] this->poly;
}

// ���׽� ����� �Լ� (���׽��� ������� �Է��ؼ� ����)
void Polynominal::makePoly() {
	int n = this->order;	// ���� ���׽��� ����

	cout << "Enter the coefficients of the Polynominal" << endl;
	for (int i = 0; i <= n; i++) {
		cout << "The coefficient of "<<this->order - i << "'s order : " ;
		cin >> this->poly[i];
	}
}

// ���� ���׽��� �̺�
void Polynominal::diffPoly() {
	// �̺��� ���׽� ������� �ӽ÷� ������ �迭
	float* temp = new float[this->order];

	// �̺��� ���׽� ������� ���
	for (int i = 0; i < this->order; i++) {
		temp[i] = (this->order-i)*this->poly[i];
	}

	// ������ ���׽� ������� ������ �迭 �޸� ����
	delete[] this->poly;

	this->poly = temp;				// �̺��� ���׽��� ����� ����
	this->order = this->order - 1;	// ���� ���׽��� ���� ����
}

// ���׽� ���� �� ��� �� �����ϴ� �Լ�
void Polynominal::setPoly(int n) {
	this->order = n;		// ���� �缳��
	delete[] this->poly;	// ������ ������� ������ �迭 �޸� ����

	// ������� ������ �޸� ���Ҵ�
	this->poly = new float[n+1];

	this->makePoly();		// ������� �缳��
}

// �Լ����� ��ȯ�ϴ� �Լ�
float Polynominal::value(float x) {
	float value = 0;

	// �Լ����� ���
	for (int i = 0; i <= this->order; i++) {
		value = value + this->poly[i]*this->expo(x,this->order-i);
	}

	// �Լ��� ��ȯ
	return value;
}

// ���׽��� ������ ��ȯ
int Polynominal::getOrder() {
	return this->order;
}

// n������ ����� ��ȯ
float Polynominal::getCoef(int n) {
	float coef = 0;

	try {
		coef = this->poly[this->order - n];
	}
	catch (out_of_range e) {
		cout << "The order enterd exceeds the maximun of range" << endl;

		// error�� ��� float�� ���� �� �ִ� �ִ��� retrun 
		return FMAX;
	}

	return coef;
}

// �ŵ����� ���� (�� �ŵ����� n�� 0�� ������ ���� ����)
float Polynominal::expo(float a, int n) {
	if (n >= 0) {
		float result = 1;
		for (int i = 0; i < n; i++)
			result = result*a;

		return result;
	}


	cout << "The order enterd is smaller than zero" << endl;
	return FMAX;
}
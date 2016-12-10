#include"Polynomial.h"
#include<memory>
#include<fstream>

// n�� ���׽� ������
Polynomial::Polynomial(int n) {
	// ���׽��� ��� ����
	this->order = n;	// n����

	// n�� ���׽��� ����� ������ �迭 ����
	this->poly = new float[n+1];
}

// ����� ��� ������ n�� ���׽� ������
Polynomial::Polynomial(float poly[]) {
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
Polynomial::Polynomial(Polynomial& poly) {
	
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
Polynomial::~Polynomial() {
	// ������� ������ �迭�� �Ҵ�� �޸� ����
	delete[] this->poly;
}

// ���׽� ����� �Լ� (���׽��� ������� �Է��ؼ� ����)
void Polynomial::makePoly() {
	int n = this->order;	// ���� ���׽��� ����

	cout << "Enter the coefficients of the Polynominal" << endl;
	for (int i = 0; i <= n; i++) {
		cout << "The coefficient of "<<this->order - i << "'s order : " ;
		cin >> this->poly[i];
	}
}

// ���� ���׽��� �̺�
void Polynomial::diffPoly() {
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
void Polynomial::setPoly(int n) {
	this->order = n;		// ���� �缳��
	delete[] this->poly;	// ������ ������� ������ �迭 �޸� ����

	// ������� ������ �޸� ���Ҵ�
	this->poly = new float[n+1];
}

// �Լ����� ��ȯ�ϴ� �Լ�
float Polynomial::operator()(float x) {
	float value = 0;

	// �Լ����� ���
	for (int i = 0; i <= this->order; i++) {
		value = value + this->poly[i] * this->expo(x, this->order - i);
	}

	// �Լ��� ��ȯ
	return value;
}

// ���׽��� ������ ��ȯ
int Polynomial::getOrder() {
	return this->order;
}

// n������ ����� ��ȯ
float& Polynomial::getCoef(int n) {
	try {
		return this->poly[this->order - n];
	}
	catch (out_of_range e) {
		cout << "The order enterd exceeds the maximun of range" << endl;

		// halt the program
		exit(0);
	}
 }

// �ŵ����� ���� (�� �ŵ����� n�� 0�� ������ ���� ����)
float Polynomial::expo(float a, int n) {
	if (n >= 0) {
		float result = 1;
		for (int i = 0; i < n; i++)
			result = result*a;

		return result;
	}


	cout << "The order enterd is smaller than zero" << endl;
	return FMAX;
}

// �Լ��� ���
void Polynomial::printValue(float ti, float tf, float h) {
	if (ti < tf) {
		float t = ti;		// current time
		float fvalue = (*this)(t);
		ofstream ofs;

		// ������� ���� ����
		ofs.open("functionData.csv", ios::out);

		if (!ofs) {
			cout << "Unable to open the file" << endl;
			exit(0);
		}

		cout << "Independent variable \t\tDependant variable" << endl;
		ofs << "Independant variable,Dependant variable" << endl;
		cout << ti << " \t\t\t\t\t" << fvalue << endl;
		ofs << ti << "," << fvalue << endl;

		while (t < tf) {
			// increase the current time 
			if (t + h <= tf) {
				t = t + h;
			}
			else {
				h = tf - t;
				t = tf;
			}

			// get the function value
			fvalue = (*this)(t);
			cout << t << " \t\t\t\t\t" << fvalue << endl;
			ofs << t << "," << fvalue << endl;
		}
	}
	else {
		cout << "Initial time is lager than the final time" << endl;
	}
}
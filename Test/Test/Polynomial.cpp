#include"Polynomial.h"
#include<memory>
#include<fstream>

// n차 다항식 생성자
Polynomial::Polynomial(int n) {
	// 다항식의 계수 설정
	this->order = n;	// n차식

	// n차 다항식의 계수를 저장할 배열 생성
	this->poly = new float[n+1];
}

// 계수가 모두 지정된 n차 다항식 생성자
Polynomial::Polynomial(float poly[]) {
	int n= _msize(poly)/sizeof(float)-1;	// 넘어온 계수들의 다항식 차수 계산

	// 다항식 차수 설정
	this->order = n;

	// 다항식 계수들을 저장할 배열 생성
	this->poly = new float[n + 1];

	// 앞서 넘어온 계수들을 현재 다항식 계수들 값으로 복사
	for (int i = 0; i <= n; i++) {
		this->poly[i] = poly[i];
	}
}

// copy 생성자
Polynomial::Polynomial(Polynomial& poly) {
	
	// 다른 다항식을 현재 다항식으로 복사
	int n = poly.getOrder();			// 넘어온 다항식의 차수 계산

	// 차수 복사 
	this->order = n;

	// 계수들을 저장할 메모리 할당
	this->poly = new float[n + 1];

	// 계수들 복사
	for (int i = 0; i <= n; i++) {
		this->poly[i] = poly.getCoef(n-i);		// n차 계수부터 상수까지 복사
	}
}

// 소멸자
Polynomial::~Polynomial() {
	// 계수들을 저장할 배열에 할당된 메모리 해제
	delete[] this->poly;
}

// 다항식 만드는 함수 (다항식의 계수들을 입력해서 지정)
void Polynomial::makePoly() {
	int n = this->order;	// 현재 다항식의 차수

	cout << "Enter the coefficients of the Polynominal" << endl;
	for (int i = 0; i <= n; i++) {
		cout << "The coefficient of "<<this->order - i << "'s order : " ;
		cin >> this->poly[i];
	}
}

// 현재 다항식을 미분
void Polynomial::diffPoly() {
	// 미분한 다항식 계수들을 임시로 저장할 배열
	float* temp = new float[this->order];

	// 미분한 다항식 계수들을 계산
	for (int i = 0; i < this->order; i++) {
		temp[i] = (this->order-i)*this->poly[i];
	}

	// 기존에 다항식 계수들을 저장할 배열 메모리 해제
	delete[] this->poly;

	this->poly = temp;				// 미분한 다항식의 계수를 저장
	this->order = this->order - 1;	// 현재 다항식의 차수 감소
}

// 다항식 차수 및 계수 재 설정하는 함수
void Polynomial::setPoly(int n) {
	this->order = n;		// 차수 재설정
	delete[] this->poly;	// 기존에 계수들을 저장한 배열 메모리 해제

	// 계수들을 저장할 메모리 재할당
	this->poly = new float[n+1];
}

// 함수값을 반환하는 함수
float Polynomial::operator()(float x) {
	float value = 0;

	// 함수값을 계산
	for (int i = 0; i <= this->order; i++) {
		value = value + this->poly[i] * this->expo(x, this->order - i);
	}

	// 함수값 반환
	return value;
}

// 다항식의 차수를 반환
int Polynomial::getOrder() {
	return this->order;
}

// n차항의 계수를 반환
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

// 거듭제곱 계산식 (단 거듭제곱 n은 0을 포함한 양의 정수)
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

// 함수값 출력
void Polynomial::printValue(float ti, float tf, float h) {
	if (ti < tf) {
		float t = ti;		// current time
		float fvalue = (*this)(t);
		ofstream ofs;

		// 쓰기모드로 파일 열기
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
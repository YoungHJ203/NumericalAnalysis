#pragma once
#include<iostream>
#define FMAX 3.402823466e+38	// float 자료형이 가질 수 있는 최댓값
using namespace std;

class Polynominal {
public:
	// n차 다항식 생성자
	Polynominal(int);

	// 계수가 모두 지정된 n차 다항식 생성자
	Polynominal(float[]);

	// copy 생성자
	Polynominal(Polynominal&);

	// 소멸자
	~Polynominal();

	// 다항식 만드는 함수 (다항식의 계수들을 입력해서 지정)
	void makePoly();

	// 현재 다항식을 미분
	void diffPoly();

	// 다항식 차수 및 계수 재 설정하는 함수
	void setPoly(int);

	// 함수값을 반환하는 함수
	float value(float);

	// 다항식의 차수를 반환
	int getOrder() {
		return this->order;
	}

	// 다항식 계수를 반환
	float getCoef(int n) {
		float coef = 0;

		try {
			coef=this->poly[this->order-n];
		}
		catch (out_of_range e) {
			cout << "The order enterd exceeds the maximun of range" << endl;

			// error인 경우 float이 가질 수 있는 최댓값을 retrun 
			return FMAX;
		}
		
		return coef;
	}

private:
	// private default 생성자 
	Polynominal() {};

	int order;		// 다항식 차수
	float* poly;	// 다항식 계수를 저장한 배열

	// 거듭제곱 계산식 (단 거듭제곱 n은 0을 포함한 양의 정수)
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

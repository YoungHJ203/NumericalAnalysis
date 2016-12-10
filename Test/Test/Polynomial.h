#pragma once
#include<iostream>
#define FMAX 3.402823466e+38	// float 자료형이 가질 수 있는 최댓값
using namespace std;

class Polynomial {
public:
	// n차 다항식 생성자
	Polynomial(int);

	// 계수가 모두 지정된 n차 다항식 생성자
	Polynomial(float[]);

	// copy 생성자
	Polynomial(Polynomial&);

	// 소멸자
	~Polynomial();

	// 다항식 만드는 함수 (다항식의 계수들을 입력해서 지정)
	void makePoly();

	// 현재 다항식을 미분
	void diffPoly();

	// 다항식 차수 및 계수 재설정하는 함수
	void setPoly(int);

	// 함수값을 반환하는 함수
	float operator()(float);

	// 다항식의 차수를 반환
	inline int getOrder();

	// n차항의 계수를 반환
	float& getCoef(int n);

	// 함수값 출력
	void printValue(float, float, float);

private:
	int order;		// 다항식 차수
	float* poly;	// 다항식 계수를 저장한 배열

	// 거듭제곱 계산식 (단 거듭제곱 n은 0을 포함한 양의 정수)
	float expo(float a, int n);

};

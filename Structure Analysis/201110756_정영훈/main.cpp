#include<iostream>
#include"example.h"
#include"NR.h"

int main() {
	
	// 다항식 함수 만들기
	float* coefficients = new float[4];

	coefficients[0] = 0.5;
	coefficients[1] = -4;
	coefficients[2] = 6;
	coefficients[3] = -2;
	
	Polynominal p(coefficients);

	// Newton Raphson Method 사용
	// Polynominal, 초기값 4.2, 유효숫자 3자리, 최대 iteration 횟수 30회 
	cout << NR::method(p, 4.2, 3, 30) << endl;	
	// Polynominal, 초기값 4.43, 유효숫자 3자리, 최대 iteration 횟수 30회 
	cout << NR::method(p, 4.43, 3, 30) << endl;	

	// Graphical Method 사용
	// Polynominal, x 범위의 하한값 0, x범위의 상한값 7, x증분 0.1
	NR::showGraph(p, 0, 7 , 0.001);	
}


//example a;

//// Delta T가 0.5s 일떄, 초기 시간 0, 종단 시간 20, 초기 속도 0, 유효숫자 3자리
//// approximate velocity 계산
//a.printVelocity(0,20,0,0.5,3);
//
//cout << endl;
//cout << endl;
//cout << endl;

//// Delta T가 1.0s 일떄, 초기 시간 0, 종단 시간 20, 초기 속도 0, 유효숫자 3자리
//// approximate velocity 계산
//a.printVelocity(0, 20,0,1,3);

//cout << endl;
//cout << endl;
//cout << endl;

//// Delta T가 2.0s 일떄, 초기 시간 0, 종단 시간 20, 초기 속도 0, 유효숫자 3자리
//// approximate velocity 계산
//a.printVelocity(0,20, 0, 2, 3);

//cout << endl;
//cout << endl;
//cout << endl;

//// 초기 시간 0, 종단 시간 20, 초기 속도 0, 시간간격 0.5s, 유효숫자 3자리
//// Exact velocity 계산
//a.printExactVelocity(0, 20, 0, 0.5);



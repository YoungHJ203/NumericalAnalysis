#include<iostream>
#include"geometry.h"
using namespace std;

// 선분의 길이 계산
void line :: setLength() {
	this->length = sqrt((this->firstPoint.getX() - this->secondPoint.getX()) * (this->firstPoint.getX() - this->secondPoint.getX()) + (this->firstPoint.getY() - this->secondPoint.getY())* (this->firstPoint.getY() - this->secondPoint.getY()));
}

// 선분 기본 생성자
line :: line() {}

// 선분 양 끝점 설정 생성자
line::line(point first,point second) {
	this->firstPoint = first;		// 첫번째 점 설정
	this->secondPoint = second;		// 두번째 점 설정
		
	// 선분 길이 설정
	this->setLength();
}

// 선분 소멸자
line :: ~line() { }

// 첫번째 점 설정
void line::setFirst(point first) {
	this->firstPoint = first;

	// 선분 길이 설정
	this->setLength();
}

// 두번째 점 설정
void line::setSecond(point second) {
	this->secondPoint = second;

	// 선분 길이 설정
	this->setLength();
}

// 첫번째 점 불러오기
point line::getFirstPoint() {
	return this->firstPoint;
}

// 두번째 점 불러오기
point line::getSecondPoint() {
	return this->secondPoint;
}

// 선분 길이 불러오기
double line::getLength() {
	return this->length;
}

#include<iostream>
#include"geometry.h"
using namespace std;

// ������ ���� ���
void line :: setLength() {
	this->length = sqrt((this->firstPoint.getX() - this->secondPoint.getX()) * (this->firstPoint.getX() - this->secondPoint.getX()) + (this->firstPoint.getY() - this->secondPoint.getY())* (this->firstPoint.getY() - this->secondPoint.getY()));
}

// ���� �⺻ ������
line :: line() {}

// ���� �� ���� ���� ������
line::line(point first,point second) {
	this->firstPoint = first;		// ù��° �� ����
	this->secondPoint = second;		// �ι�° �� ����
		
	// ���� ���� ����
	this->setLength();
}

// ���� �Ҹ���
line :: ~line() { }

// ù��° �� ����
void line::setFirst(point first) {
	this->firstPoint = first;

	// ���� ���� ����
	this->setLength();
}

// �ι�° �� ����
void line::setSecond(point second) {
	this->secondPoint = second;

	// ���� ���� ����
	this->setLength();
}

// ù��° �� �ҷ�����
point line::getFirstPoint() {
	return this->firstPoint;
}

// �ι�° �� �ҷ�����
point line::getSecondPoint() {
	return this->secondPoint;
}

// ���� ���� �ҷ�����
double line::getLength() {
	return this->length;
}

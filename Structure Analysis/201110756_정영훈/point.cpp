#include"geometry.h"
using namespace std;

// point 기본 생성자
point :: point() {};

// point 좌표 설정 생성자
point::point(int x, int y, int z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}
// point 소멸자
point :: ~point() {};

// 점의 x,y,z 좌표 설정
void point::setPoint(int x, int y, int z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}

// x좌표 불러오기
double point::getX() {
	return this->X;
}

// y좌표 불러오기
double point::getY() {
	return this->Y;
}

// z좌표 불러오기
double point::getZ() {
	return this->Z;
}

// 좌표점 표시하기
void point::printPoint() {
	cout << " (" << this->X << ", " << this->Y << ", " << this->Z << ") " << endl;
}

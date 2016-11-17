#include"geometry.h"
using namespace std;

// point �⺻ ������
point :: point() {};

// point ��ǥ ���� ������
point::point(int x, int y, int z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}
// point �Ҹ���
point :: ~point() {};

// ���� x,y,z ��ǥ ����
void point::setPoint(int x, int y, int z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}

// x��ǥ �ҷ�����
double point::getX() {
	return this->X;
}

// y��ǥ �ҷ�����
double point::getY() {
	return this->Y;
}

// z��ǥ �ҷ�����
double point::getZ() {
	return this->Z;
}

// ��ǥ�� ǥ���ϱ�
void point::printPoint() {
	cout << " (" << this->X << ", " << this->Y << ", " << this->Z << ") " << endl;
}

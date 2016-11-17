#include"geometry.h"
using namespace std;

// point ±âº» »ý¼ºÀÚ
point :: point() {};

// point ÁÂÇ¥ ¼³Á¤ »ý¼ºÀÚ
point::point(int x, int y, int z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}
// point ¼Ò¸êÀÚ
point :: ~point() {};

// Á¡ÀÇ x,y,z ÁÂÇ¥ ¼³Á¤
void point::setPoint(int x, int y, int z) {
	this->X = x;
	this->Y = y;
	this->Z = z;
}

// xÁÂÇ¥ ºÒ·¯¿À±â
double point::getX() {
	return this->X;
}

// yÁÂÇ¥ ºÒ·¯¿À±â
double point::getY() {
	return this->Y;
}

// zÁÂÇ¥ ºÒ·¯¿À±â
double point::getZ() {
	return this->Z;
}

// ÁÂÇ¥Á¡ Ç¥½ÃÇÏ±â
void point::printPoint() {
	cout << " (" << this->X << ", " << this->Y << ", " << this->Z << ") " << endl;
}

#include"structure.h"
// beam 역시 frame의 일부임

// 단면 2차 모멘트 설정
void frame :: setInertia(double I) {
	this->I = I;
}

// 단면 2차 모멘트 불러오기
double frame:: getInertia() {
	return this->I;
}

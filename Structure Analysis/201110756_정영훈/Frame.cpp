#include"structure.h"
// beam ���� frame�� �Ϻ���

// �ܸ� 2�� ���Ʈ ����
void frame :: setInertia(double I) {
	this->I = I;
}

// �ܸ� 2�� ���Ʈ �ҷ�����
double frame:: getInertia() {
	return this->I;
}

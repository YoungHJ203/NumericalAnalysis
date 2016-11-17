// 2���� �󿡼� ���ϼ���
#ifndef GEOMETRY
#define GEOMETRY
#include<iostream>

// ��
class point {
private:
	double X;	// x ��ǥ 
	double Y;	// y ��ǥ
	double Z;	// z ��ǥ

public:
	point();						// point �⺻ ������
	point(int,int,int);				// point ��ǥ ���� ������
	~point();						// point �Ҹ���
	void setPoint(int, int, int);	// ���� x,y,z ��ǥ ����
	double getX();					// x��ǥ �ҷ�����
	double getY();					// y��ǥ �ҷ�����
	double getZ();					// z��ǥ �ҷ�����
	void printPoint();				// ��ǥ�� ǥ���ϱ�
};

// ����
class line {
private:
	point firstPoint;		// ���� ���� ����		(ù��° ��)
	point secondPoint;		// ���� �ٸ� ���� ����	(�ι�° ��)
	double length;			// ���� ����
	void setLength();		// ������ ���� ���

public:
	line();						// ���� �⺻ ������
	line(point,point);			// ���� �� ���� ���� ������
	~line();					// ���� �Ҹ���
	void setFirst(point);		// ù��° �� ����
	void setSecond(point);		// �ι�° �� ����
	point getFirstPoint();		// ù��° �� �ҷ�����
	point getSecondPoint();		// �ι�° �� �ҷ�����
	double getLength();			// ���� ���� �ҷ�����
};

#endif // !GEOMETRY
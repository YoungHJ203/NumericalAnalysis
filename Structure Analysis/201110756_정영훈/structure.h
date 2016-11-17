#ifndef STRUCTURE
#define STRUCTURE
#define secondDimension 2	// 2���� ��ǥ�� ��
#define thirdDimension 3	// 3���� ��ǥ�� ��

#include<iostream>
#include<string>
#include"geometry.h"

using namespace std;

// structure (2���� ������) class
class structure {
protected:
	string name;		// ������ �̸�
	int numberOfNode;	// Node�� ����
	point *Node;		// Node�� ��ǥ���� ������ �迭 (���� �迭)
	int** boundary;		// Node�� ������� (1��: ��� ��ȣ, 2��: X���� ������� , 3��: Y���� ������� �� 0: free, 1:constrained)

public:
	structure();					// structure �⺻ ������
	structure(string,int);			// �ʱⰪ ���� structure ������
	~structure();					// structure �Ҹ���
	void setName(string);			// ������ �̸� ����
	string getName();				// ������ �̸� �ҷ�����
	void printName();				// ������ �̸� ����ϱ�
	void setNumberOfNode(int);		// ��� ���� �����ϱ�
	int getNumberOfNode();			// ������ ��ü�� ��� ���� �ҷ�����
	void setNode(int,int,int);		// Node�� ��ǥ�� �����ϱ� (��� ��ȣ�� 0������ ������)
	point getNode(int);				// �ش� ����� ��ǥ ��ȯ
	void setBoundary(int,int,int);	// �������� ����
	int getBoundary(int,int);		// �������� ��ȯ
	void printAll();			// structure ���� ���	
};

// wire (����) class
class wire : public structure{
protected:
	double E;			// Elastic Modulus, ź�����
	double A;			// Area, �ܸ���

public:
	wire();								// wire �⺻ ������
	wire(string, int, double, double);	// wire �ʱⰪ ���� ������
	~wire();							// wire �Ҹ���
	void setElasticty(double);			// ź����� ����
	double getElasticity();				// ź����� �ҷ�����
	void setArea(double);				// �ܸ��� ����
	double getArea();					// �ܸ��� �ҷ�����
	void printAll();					// wire ���� ����ϱ�
};

// truss (Ʈ����) class
class truss : public wire {
protected:

public:

};

// Frame (����) class
class frame : public truss {

protected:
	double I;

public:
	void setInertia(double);	// �ܸ� 2�� ���Ʈ ����
	double getInertia();		// �ܸ� 2�� ���Ʈ �ҷ�����
		
};
#endif
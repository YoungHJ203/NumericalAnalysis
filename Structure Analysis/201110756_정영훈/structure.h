#ifndef STRUCTURE
#define STRUCTURE
#define secondDimension 2	// 2차원 좌표축 수
#define thirdDimension 3	// 3차원 좌표축 수

#include<iostream>
#include<string>
#include"geometry.h"

using namespace std;

// structure (2차원 구조물) class
class structure {
protected:
	string name;		// 구조물 이름
	int numberOfNode;	// Node의 갯수
	point *Node;		// Node의 좌표점을 저장할 배열 (동적 배열)
	int** boundary;		// Node의 경계조건 (1열: 노드 번호, 2열: X방향 경계조건 , 3열: Y방향 경계조건 → 0: free, 1:constrained)

public:
	structure();					// structure 기본 생성자
	structure(string,int);			// 초기값 설정 structure 생성자
	~structure();					// structure 소멸자
	void setName(string);			// 구조물 이름 설정
	string getName();				// 구조물 이름 불러오기
	void printName();				// 구조물 이름 출력하기
	void setNumberOfNode(int);		// 노드 갯수 설정하기
	int getNumberOfNode();			// 구조물 전체의 노드 갯수 불러오기
	void setNode(int,int,int);		// Node의 좌표점 설정하기 (노드 번호는 0번부터 시작함)
	point getNode(int);				// 해당 노드의 좌표 반환
	void setBoundary(int,int,int);	// 구속조건 설정
	int getBoundary(int,int);		// 구속조건 반환
	void printAll();			// structure 정보 출력	
};

// wire (강선) class
class wire : public structure{
protected:
	double E;			// Elastic Modulus, 탄성계수
	double A;			// Area, 단면적

public:
	wire();								// wire 기본 생성자
	wire(string, int, double, double);	// wire 초기값 설정 생성자
	~wire();							// wire 소멸자
	void setElasticty(double);			// 탄성계수 설정
	double getElasticity();				// 탄성계수 불러오기
	void setArea(double);				// 단면적 설정
	double getArea();					// 단면적 불러오기
	void printAll();					// wire 정보 출력하기
};

// truss (트러스) class
class truss : public wire {
protected:

public:

};

// Frame (골조) class
class frame : public truss {

protected:
	double I;

public:
	void setInertia(double);	// 단면 2차 모멘트 설정
	double getInertia();		// 단면 2차 모멘트 불러오기
		
};
#endif
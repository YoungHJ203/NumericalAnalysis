// 2차원 상에서 기하성분
#ifndef GEOMETRY
#define GEOMETRY
#include<iostream>

// 점
class point {
private:
	double X;	// x 좌표 
	double Y;	// y 좌표
	double Z;	// z 좌표

public:
	point();						// point 기본 생성자
	point(int,int,int);				// point 좌표 설정 생성자
	~point();						// point 소멸자
	void setPoint(int, int, int);	// 점의 x,y,z 좌표 설정
	double getX();					// x좌표 불러오기
	double getY();					// y좌표 불러오기
	double getZ();					// z좌표 불러오기
	void printPoint();				// 좌표점 표시하기
};

// 선분
class line {
private:
	point firstPoint;		// 선분 한쪽 끝점		(첫번째 점)
	point secondPoint;		// 선분 다른 한쪽 끝점	(두번째 점)
	double length;			// 선분 길이
	void setLength();		// 선분의 길이 계산

public:
	line();						// 선분 기본 생성자
	line(point,point);			// 선분 양 끝점 설정 생성자
	~line();					// 선분 소멸자
	void setFirst(point);		// 첫번째 점 설정
	void setSecond(point);		// 두번째 점 설정
	point getFirstPoint();		// 첫번째 점 불러오기
	point getSecondPoint();		// 두번째 점 불러오기
	double getLength();			// 선분 길이 불러오기
};

#endif // !GEOMETRY
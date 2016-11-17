#include"structure.h"

// wire 기본 생성자
wire :: wire() {
	this->name = "";
	this->numberOfNode = 0;
	this->E = 0;
	this->A = 0;
};

// wire 초기값 설정 생성자
wire :: wire(string name, int numberOfNode, double E, double A) {
	this->name = name;
	this->numberOfNode = numberOfNode;
	this->E = E;
	this->A = A;

	// 노드를 저장할 배열 생성
	this->Node = (point*)malloc(this->numberOfNode*sizeof(point));

	// 경계조건 저장할 배열 생성; (numberOfNode * 3) 배열
	// 행 생성
	this->boundary = (int**)malloc(this->numberOfNode*sizeof(int*));

	// 열 생성
	for (int i = 0; i < this->numberOfNode; i++) {
		this->boundary[i] = (int*)calloc(secondDimension + 1, sizeof(int*));	// 초기값 0으로 지정
		this->boundary[i][0] = i;											// 노드 번호 지정
	}

};

// wire 소멸자
wire :: ~wire() {
	if (this->numberOfNode > 0) {
		// Node배열의 메모리 해제
		free(this->Node);

		// boundary 배열의 메모리 해제
		// 각 행의 메모리 해제
		for (int i = 0; i < this->numberOfNode; i++) {
			free(this->boundary[i]);
		}

		// 전체 메모리 해제
		free(this->boundary);
	}
};
	
// 탄성계수 설정
void wire :: setElasticty(double E) {
	this->E = E;
}

// 탄성계수 불러오기
double wire :: getElasticity() {
	return this->E;
}

// 단면적 설정
void wire :: setArea(double A) {
	this->A = A;
}

// 단면적 불러오기
double wire :: getArea() {
	return this->A;
}

//// 하중 적용하기
//void applyForce(double force) {
//	
//	this->axialForce = force;

//	// 변위 계산하기
//	this->displacement = this->axialForce * ;
//}

//// 

// wire 정보 출력하기
void wire :: printAll() {
		cout << "\t\t\t" << "  Wire In 2D" << "\t\t\t" << endl;
		cout << "Wire Type : Not yet specified" << endl;
		cout << "Wire Name : " << this->name << endl;
		cout << "Wire Elastic Modulus : "<< this->E << endl;
		cout << "Wire Area : "<< this->A << endl;
		cout << endl;
		cout << "────────────────────────────────────" << endl;
		cout << endl;

		// wire의 노드 정보 출력
		cout << "Node Number\tXcoord\t\tYcoord" << endl;
		for (int i = 0; i < this->numberOfNode; i++) {
			cout << "    " << i << "\t\t  " << this->Node[i].getX() << "\t\t  " << this->Node[i].getY() << endl;
		}

		cout << endl;
		cout << "────────────────────────────────────" << endl;
		cout << endl;

		// wire의 boundary condtion 출력하기
		cout << "Node Number\tXcoord\t\tYcoord" << endl;
		for (int i = 0; i < this->numberOfNode; i++) {
			cout << "    " << i << "\t\t";

			// X 방향 구속조건 출력
			if (this->boundary[i][1] == 0) {
				cout << "free\t\t";
			}
			else {
				cout << "constrained\t";
			}

			// Y 방향 구속조건 출력
			if (this->boundary[i][2] == 0) {
				cout << "free\t\t";
			}
			else {
				cout << "constrained\t";
			}
		}
		
}

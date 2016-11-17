#include"structure.h"

// structure 기본 생성자
structure :: structure() {
	this->name = "";
	this->numberOfNode = 0;
	this->Node = NULL;
	this->boundary = NULL;
};
	
// 초기값 설정 structure 생성자
structure :: structure(string name, int NumberOfNode) {
	// 초기값 지정
	this->name = name;
	this->numberOfNode = NumberOfNode;

	// 노드를 저장할 배열 생성
	this->Node = (point*)malloc(this->numberOfNode*sizeof(point));

	// 경계조건 저장할 배열 생성; (numberOfNode * 3) 배열
	// 행 생성
	this->boundary = (int**)malloc(this->numberOfNode*sizeof(int*));

	// 열 생성
	for (int i = 0; i < this->numberOfNode; i++) {
		this->boundary[i] = (int*)calloc(secondDimension+1,sizeof(int*));	// 초기값 0으로 지정
		this->boundary[i][0] = i;											// 노드 번호 지정
	}
};

// structure 소멸자
structure :: ~structure() {
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

// 구조물 이름 설정
void structure :: setName(string name) {
	this->name = name;
}

// 구조물 이름 불러오기
string structure :: getName() {
	return this->name;
}

// 구조물 이름 출력하기
void structure :: printName() {
	cout << "The Structure is " << this->name << endl;
}

// 노드 갯수 설정하기
void structure :: setNumberOfNode(int number) {
		
	// 기존에 노드가 있는 경우
	if (this->numberOfNode>0) {
			// 노드 배열 크기 변경
			this->Node = (point*)realloc(this->Node,number*sizeof(point));

			
			// 경계 조건 배열 크기 변경
			// 노드의 크기를 증가시키는 경우
			if (number > this->numberOfNode) {
				// 행 생성
				this->boundary = (int**)realloc(this->boundary, number*sizeof(int*));

				// 열 생성		
				for (int i = this->numberOfNode; i < number; i++) {
					this->boundary[i] = (int*)calloc(secondDimension + 1, sizeof(int*));
					this->boundary[i][0] = 0;
				}		
			}
			// 노드의 크기를 감소시키는 경우
			else {
				// number보다 큰 행번호를 가진 행의 메모리 해제
				for (int i = this->numberOfNode - 1; i >= number; i--) {
					free(this->boundary[i]);
				}

				// 메모리 재할당
				this->boundary = (int**)realloc(this->boundary, number*sizeof(int*));
			}
	}
	// 기존에 노드가 없는 경우
	else {
		// 새로운 노드 배열 생성
		this->Node = (point*)malloc(number*sizeof(point));

		// 새로운 boundary 배열 생성(numberOfNode * 3) 배열
		// 행 생성
		this->boundary = (int**)malloc(this->numberOfNode*sizeof(int*));

		// 열 생성
		for (int i = 0; i < this->numberOfNode; i++) {
			this->boundary[i] = (int*)calloc(secondDimension + 1, sizeof(int*));	// 초기값 0으로 지정
			this->boundary[i][0] = i;											// 노드 번호 지정
		}
	}

	// 노드 갯수 설정
	this->numberOfNode = number;
}
	
// 구조물 전체의 노드 갯수 불러오기
int structure :: getNumberOfNode() {
	return this->numberOfNode;
}

// Node의 좌표점 설정하기 (노드 번호는 0번부터 시작함)
void structure :: setNode(int nodeNumber, int x, int y) {
	// 노드 번호가 전체 노드의 갯수보다 크거나 같은 경우 error 메시지 띄우기
	if (this->numberOfNode <= nodeNumber) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
	}
	// 노드 번호가 전체 노드의 갯수보다 작은 경우에만, 노드의 좌표점 설정
	else {
		// 해당 노드의 좌표점 설정, 2차원이므로, z좌표는 0으로 설정
		this->Node[nodeNumber].setPoint(x, y, 0);
	}
	
}

// 해당 노드의 좌표 반환
point structure :: getNode(int nodenumber) {
	point temp;
	temp.setPoint(0, 0, 0);

	// 잘못된 노드번호이므로, error 메시지 반환
	if (this->numberOfNode <= nodenumber) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
		return temp;
	}
	// 노드 번호가 전체 노드의 갯수보다 작은 경우
	else {
		// 해당 노드의 좌표점 반환
		return this->Node[nodenumber];
	}
}

// 구속조건 설정
void structure :: setBoundary(int nodeNumber, int coord, int boundary) {
	// coord = ( 1 : x축, 2 : y축) boundary = ( 0 : free, 1 : constrained)
	// 노드 번호가 전체 노드 갯수보다 크거나 같은 경우 error 메시지 띄우기
	if (nodeNumber >= this->numberOfNode) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
	}
	// 노드 번호가 전체 노드의 갯수보다 작은 경우에만, 노드의 좌표점 설정
	else {
		// 정상적인 좌표축 방향이 입력된 경우
		if (coord == 1 || coord == 2) {
			// 구속조건이 정상적으로 입력된 경우
			if (boundary == 0 || boundary ==1) {
				this->boundary[nodeNumber][coord] = boundary;
			}
			// 구속조건이 잘못 입력된 경우
			else {
				cout << "The boundary condtion entered is not proper" << endl;
			}
		}
		// 좌표축 입력이 잘못된 경우
		else {
			cout << "The coordinate entered is not proper" << endl;
		}
	}
}

// 구속조건 반환
int structure :: getBoundary(int nodeNumber, int coord) {
	// 노드 번호가 전체 노드 갯수보다 크거나 같은 경우 error 메시지 띄우기
	if (nodeNumber >= this->numberOfNode) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
	}
	// 노드 번호가 전체 노드의 갯수보다 작은 경우에만, 노드의 좌표점 설정
	else {
		// 정상적인 좌표축 방향이 입력된 경우
		if (coord == 1 || coord == 2) {
			// 구속 조건 반환
			return this->boundary[nodeNumber][coord];
		}
		// 좌표축 입력이 잘못된 경우
		else {
			cout << "The coordinate entered is not proper" << endl;
		}
	}

	// 매개변수가 잘못입력된 경우 -1을 반환
	return -1;
}

// structure 정보 출력
void structure :: printAll() {
	cout << "\t\t\t" << "Structure In 2D" << "\t\t\t" << endl;
	cout << "Structure Type : Not yet specified" << endl;			 
	cout << "Structure Name : "<< this->name << endl;				
	cout << endl;
	cout << "────────────────────────────────────"<< endl;
	cout << endl;
		
	// structure의 노드 정보 출력
	cout << "Node Number\tXcoord\t\tYcoord" << endl;
	for (int i = 0; i < this->numberOfNode; i++) {
		cout << "    " << i << "\t\t  " <<  this->Node[i].getX() << "\t\t  "<< this->Node[i].getY() <<endl;
	}
		
	cout << endl;
	cout << "────────────────────────────────────" << endl;
	cout << endl;
		
	// structure의 boundary condtion 출력하기
	cout << "Node Number\tXcoord\t\tYcoord" << endl;
	for (int i = 0; i < this->numberOfNode; i++) {
		cout << "    " << i << "\t\t";

		// X 방향 구속조건 출력
		if (this->boundary[i][1]==0) {
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

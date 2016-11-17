#include"structure.h"

// structure �⺻ ������
structure :: structure() {
	this->name = "";
	this->numberOfNode = 0;
	this->Node = NULL;
	this->boundary = NULL;
};
	
// �ʱⰪ ���� structure ������
structure :: structure(string name, int NumberOfNode) {
	// �ʱⰪ ����
	this->name = name;
	this->numberOfNode = NumberOfNode;

	// ��带 ������ �迭 ����
	this->Node = (point*)malloc(this->numberOfNode*sizeof(point));

	// ������� ������ �迭 ����; (numberOfNode * 3) �迭
	// �� ����
	this->boundary = (int**)malloc(this->numberOfNode*sizeof(int*));

	// �� ����
	for (int i = 0; i < this->numberOfNode; i++) {
		this->boundary[i] = (int*)calloc(secondDimension+1,sizeof(int*));	// �ʱⰪ 0���� ����
		this->boundary[i][0] = i;											// ��� ��ȣ ����
	}
};

// structure �Ҹ���
structure :: ~structure() {
	if (this->numberOfNode > 0) {
		// Node�迭�� �޸� ����
		free(this->Node);

		// boundary �迭�� �޸� ����
		// �� ���� �޸� ����
		for (int i = 0; i < this->numberOfNode; i++) {
			free(this->boundary[i]);
		}

		// ��ü �޸� ����
		free(this->boundary);
	}
			
};	

// ������ �̸� ����
void structure :: setName(string name) {
	this->name = name;
}

// ������ �̸� �ҷ�����
string structure :: getName() {
	return this->name;
}

// ������ �̸� ����ϱ�
void structure :: printName() {
	cout << "The Structure is " << this->name << endl;
}

// ��� ���� �����ϱ�
void structure :: setNumberOfNode(int number) {
		
	// ������ ��尡 �ִ� ���
	if (this->numberOfNode>0) {
			// ��� �迭 ũ�� ����
			this->Node = (point*)realloc(this->Node,number*sizeof(point));

			
			// ��� ���� �迭 ũ�� ����
			// ����� ũ�⸦ ������Ű�� ���
			if (number > this->numberOfNode) {
				// �� ����
				this->boundary = (int**)realloc(this->boundary, number*sizeof(int*));

				// �� ����		
				for (int i = this->numberOfNode; i < number; i++) {
					this->boundary[i] = (int*)calloc(secondDimension + 1, sizeof(int*));
					this->boundary[i][0] = 0;
				}		
			}
			// ����� ũ�⸦ ���ҽ�Ű�� ���
			else {
				// number���� ū ���ȣ�� ���� ���� �޸� ����
				for (int i = this->numberOfNode - 1; i >= number; i--) {
					free(this->boundary[i]);
				}

				// �޸� ���Ҵ�
				this->boundary = (int**)realloc(this->boundary, number*sizeof(int*));
			}
	}
	// ������ ��尡 ���� ���
	else {
		// ���ο� ��� �迭 ����
		this->Node = (point*)malloc(number*sizeof(point));

		// ���ο� boundary �迭 ����(numberOfNode * 3) �迭
		// �� ����
		this->boundary = (int**)malloc(this->numberOfNode*sizeof(int*));

		// �� ����
		for (int i = 0; i < this->numberOfNode; i++) {
			this->boundary[i] = (int*)calloc(secondDimension + 1, sizeof(int*));	// �ʱⰪ 0���� ����
			this->boundary[i][0] = i;											// ��� ��ȣ ����
		}
	}

	// ��� ���� ����
	this->numberOfNode = number;
}
	
// ������ ��ü�� ��� ���� �ҷ�����
int structure :: getNumberOfNode() {
	return this->numberOfNode;
}

// Node�� ��ǥ�� �����ϱ� (��� ��ȣ�� 0������ ������)
void structure :: setNode(int nodeNumber, int x, int y) {
	// ��� ��ȣ�� ��ü ����� �������� ũ�ų� ���� ��� error �޽��� ����
	if (this->numberOfNode <= nodeNumber) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
	}
	// ��� ��ȣ�� ��ü ����� �������� ���� ��쿡��, ����� ��ǥ�� ����
	else {
		// �ش� ����� ��ǥ�� ����, 2�����̹Ƿ�, z��ǥ�� 0���� ����
		this->Node[nodeNumber].setPoint(x, y, 0);
	}
	
}

// �ش� ����� ��ǥ ��ȯ
point structure :: getNode(int nodenumber) {
	point temp;
	temp.setPoint(0, 0, 0);

	// �߸��� ����ȣ�̹Ƿ�, error �޽��� ��ȯ
	if (this->numberOfNode <= nodenumber) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
		return temp;
	}
	// ��� ��ȣ�� ��ü ����� �������� ���� ���
	else {
		// �ش� ����� ��ǥ�� ��ȯ
		return this->Node[nodenumber];
	}
}

// �������� ����
void structure :: setBoundary(int nodeNumber, int coord, int boundary) {
	// coord = ( 1 : x��, 2 : y��) boundary = ( 0 : free, 1 : constrained)
	// ��� ��ȣ�� ��ü ��� �������� ũ�ų� ���� ��� error �޽��� ����
	if (nodeNumber >= this->numberOfNode) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
	}
	// ��� ��ȣ�� ��ü ����� �������� ���� ��쿡��, ����� ��ǥ�� ����
	else {
		// �������� ��ǥ�� ������ �Էµ� ���
		if (coord == 1 || coord == 2) {
			// ���������� ���������� �Էµ� ���
			if (boundary == 0 || boundary ==1) {
				this->boundary[nodeNumber][coord] = boundary;
			}
			// ���������� �߸� �Էµ� ���
			else {
				cout << "The boundary condtion entered is not proper" << endl;
			}
		}
		// ��ǥ�� �Է��� �߸��� ���
		else {
			cout << "The coordinate entered is not proper" << endl;
		}
	}
}

// �������� ��ȯ
int structure :: getBoundary(int nodeNumber, int coord) {
	// ��� ��ȣ�� ��ü ��� �������� ũ�ų� ���� ��� error �޽��� ����
	if (nodeNumber >= this->numberOfNode) {
		cout << "The Node number exceeds the total number of Node" << endl;
		cout << "Please check the Node number" << endl;
	}
	// ��� ��ȣ�� ��ü ����� �������� ���� ��쿡��, ����� ��ǥ�� ����
	else {
		// �������� ��ǥ�� ������ �Էµ� ���
		if (coord == 1 || coord == 2) {
			// ���� ���� ��ȯ
			return this->boundary[nodeNumber][coord];
		}
		// ��ǥ�� �Է��� �߸��� ���
		else {
			cout << "The coordinate entered is not proper" << endl;
		}
	}

	// �Ű������� �߸��Էµ� ��� -1�� ��ȯ
	return -1;
}

// structure ���� ���
void structure :: printAll() {
	cout << "\t\t\t" << "Structure In 2D" << "\t\t\t" << endl;
	cout << "Structure Type : Not yet specified" << endl;			 
	cout << "Structure Name : "<< this->name << endl;				
	cout << endl;
	cout << "������������������������������������������������������������������������"<< endl;
	cout << endl;
		
	// structure�� ��� ���� ���
	cout << "Node Number\tXcoord\t\tYcoord" << endl;
	for (int i = 0; i < this->numberOfNode; i++) {
		cout << "    " << i << "\t\t  " <<  this->Node[i].getX() << "\t\t  "<< this->Node[i].getY() <<endl;
	}
		
	cout << endl;
	cout << "������������������������������������������������������������������������" << endl;
	cout << endl;
		
	// structure�� boundary condtion ����ϱ�
	cout << "Node Number\tXcoord\t\tYcoord" << endl;
	for (int i = 0; i < this->numberOfNode; i++) {
		cout << "    " << i << "\t\t";

		// X ���� �������� ���
		if (this->boundary[i][1]==0) {
			cout << "free\t\t";
		}
		else {
			cout << "constrained\t";
		}

		// Y ���� �������� ���
		if (this->boundary[i][2] == 0) {
			cout << "free\t\t";
		}
		else {
			cout << "constrained\t";
		}
	}
}

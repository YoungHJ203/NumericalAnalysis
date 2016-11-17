#include"structure.h"

// wire �⺻ ������
wire :: wire() {
	this->name = "";
	this->numberOfNode = 0;
	this->E = 0;
	this->A = 0;
};

// wire �ʱⰪ ���� ������
wire :: wire(string name, int numberOfNode, double E, double A) {
	this->name = name;
	this->numberOfNode = numberOfNode;
	this->E = E;
	this->A = A;

	// ��带 ������ �迭 ����
	this->Node = (point*)malloc(this->numberOfNode*sizeof(point));

	// ������� ������ �迭 ����; (numberOfNode * 3) �迭
	// �� ����
	this->boundary = (int**)malloc(this->numberOfNode*sizeof(int*));

	// �� ����
	for (int i = 0; i < this->numberOfNode; i++) {
		this->boundary[i] = (int*)calloc(secondDimension + 1, sizeof(int*));	// �ʱⰪ 0���� ����
		this->boundary[i][0] = i;											// ��� ��ȣ ����
	}

};

// wire �Ҹ���
wire :: ~wire() {
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
	
// ź����� ����
void wire :: setElasticty(double E) {
	this->E = E;
}

// ź����� �ҷ�����
double wire :: getElasticity() {
	return this->E;
}

// �ܸ��� ����
void wire :: setArea(double A) {
	this->A = A;
}

// �ܸ��� �ҷ�����
double wire :: getArea() {
	return this->A;
}

//// ���� �����ϱ�
//void applyForce(double force) {
//	
//	this->axialForce = force;

//	// ���� ����ϱ�
//	this->displacement = this->axialForce * ;
//}

//// 

// wire ���� ����ϱ�
void wire :: printAll() {
		cout << "\t\t\t" << "  Wire In 2D" << "\t\t\t" << endl;
		cout << "Wire Type : Not yet specified" << endl;
		cout << "Wire Name : " << this->name << endl;
		cout << "Wire Elastic Modulus : "<< this->E << endl;
		cout << "Wire Area : "<< this->A << endl;
		cout << endl;
		cout << "������������������������������������������������������������������������" << endl;
		cout << endl;

		// wire�� ��� ���� ���
		cout << "Node Number\tXcoord\t\tYcoord" << endl;
		for (int i = 0; i < this->numberOfNode; i++) {
			cout << "    " << i << "\t\t  " << this->Node[i].getX() << "\t\t  " << this->Node[i].getY() << endl;
		}

		cout << endl;
		cout << "������������������������������������������������������������������������" << endl;
		cout << endl;

		// wire�� boundary condtion ����ϱ�
		cout << "Node Number\tXcoord\t\tYcoord" << endl;
		for (int i = 0; i < this->numberOfNode; i++) {
			cout << "    " << i << "\t\t";

			// X ���� �������� ���
			if (this->boundary[i][1] == 0) {
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

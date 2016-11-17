#include"NR.h"
#include"example.h"

// Newton-Raphson Method
float NR::method(Polynominal poly, float x, int ns ,int iterMax) {
	float value = 0;

	try {
		// NR Method�� �ظ� ����
		value = NR::subMethod(poly,x,ns,iterMax);
	}
	// iteration Ƚ���� �ʹ� ���� ��� exception ó��
	catch (int n) {
		// iteration Ƚ���� �����鼭, �ٻ� ��� ������ ũ�� �پ���� ���� ���
		if (n >= iterMax) {	
cout << "The initial Value may be needed to be changed or the graph shape shall be checked first"<< endl;
			return FMAX;
		}
	}
	// �̺� ���� 0�� ���, exception ó��
	catch (char c) {
cout << "The value of first order derivative is zero, so the iteration can't be processed anymore."<< endl;
	}

	return value;
}

// Newton-Raphson Method �۵���
float NR::subMethod(Polynominal poly, float x, int ns ,int iterMax) {
	int iteration = 1;							// iteration Ƚ��

	float root=x;								// polynominal�� ��			

	// exponential ���� ( a^b ) �� ����ϱ� ���� �ӽ÷� ���� ��ü
	example ex;									
	float Es = 0.5*ex.exponential(10,2-ns);		// ��� ��� ����
	float Ea = 100;								// �ٻ� ��� ����

	// ���� �� (Newton-Raphson Method�� ���� ���� ���� ������ Ȯ���ϱ� ���� �� ���� ����)
	Polynominal original(poly);					
	Polynominal diff(poly);						// ���� ���� �̺н�
	diff.diffPoly();
	
	ofstream ofs;								// ���Ϸ� ������ ���
	string fileName = "NR";						// ���� �̸�
	static int call = 0;						// �Լ� ȣ��Ƚ��

	fileName = fileName + to_string(call) + ".csv";

	// ���� ���� ���� open
	ofs.open(fileName.c_str(), ios::out);

	// ������ ������ ���� ��� ���α׷� ����
	if (!ofs) {
		cout << "The file is not able to open" << endl;
		exit(0);
	}

	// �Լ� ȣ��Ƚ�� ������Ű��
	call++;

	// �Ӽ� (iteration, root)�� ���� ù�ٿ� ����
	ofs << "iteration,root"<<endl;

	// ȭ�鿡 �Ӽ� ����� ����ϱ�
	cout << "itertaion\troot\t\tEa" << endl;

	// iteration until Er<=Ea and iteration<iterMax (�ٻ� ��� ������ ��� ��� ���� ���� ���� ������)
	while (Ea>Es && iteration < iterMax) {

		// �� iteration ���� iteration Ƚ���� root�� ���Ͽ� �����ϱ�
		ofs << iteration << "," << root <<",";

		// ȭ�鿡 ���� ����ϱ�
		cout << right<<"   "  << iteration <<"\t\t"<< setprecision(3)<< root << "\t\t";

		// �ٻ� ��� ������ ���Ͽ� �����ϰ� ȭ�鿡 ����ϱ�
		if (iteration > 1) {
			ofs << Ea;
			cout << Ea;
		}

		// ���Ͽ� ����Ǵ� ���ڿ��� ���� �ٲ�
		ofs << endl;

		// ȭ�鿡�� �� �ٲ�
		cout << endl;

		// ���Ŀ� �����Ͽ� 0���� Ȯ��
		if (original.value(root) == 0) {

			// �� iteration ���� iteration Ƚ���� root�� ���Ϸ� ����ϱ�
			ofs << iteration << "," << root << endl;

			// ȭ�鿡 ���� ����ϱ�
			cout << "   " << iteration << "\t\t" << setw(3) << root << "\t\t" <<  Ea << endl;

			return root;
		}

		// ���� ���� ������ �ӽ� ����
		float old = root;
		
		// ���� ��ġ������ �Լ� �̺� ���� 0�̸�, Newton-Raphson Method ���� 
		if (diff.value(root) == 0) {
			char c='e';
			throw c;
		}
		// ���� ��ġ������ �Լ� �̺� ���� ���� ������ ������ ��� �޽��� ����
		else if (diff.value(root)<LIMIT){	
			cout << "The value of first order derivative is too small for continue the iteration." << endl;
		}

		// next try value for the equation
		root = root - poly.value(root)/diff.value(root) ;

		// Error ���
		Ea = abs((root - old) / root * 100);

		// iteration Ƚ�� counting
		iteration++;
	}

	// �� iteration ���� iteration Ƚ���� root�� ���Ϸ� ����ϱ�
	ofs << iteration << "," << root << ","<< Ea<<endl;

	// ȭ�鿡 ���� ����ϱ�
	cout << "   " << iteration << "\t\t" << setw(4) << setprecision(1) << root << "\t\t" <<  Ea << endl;

	// ������ �پ���� ���� ���¿��� iteration Ƚ���� �� ������, exception ó��
	if (iteration >= iterMax && Ea>Es) {
		throw iteration;
	}

	// ���� �ݱ�
	ofs.close();

	return root;

}

// Graphical Method
void NR::showGraph(Polynominal poly, float xmin, float xmax, float delX) {

	ofstream ofs;		// ���� ����

	// x ������ ���Ѱ��� x ������ ���Ѱ����� ���� ��쿡�� ����
	if (xmin < xmax) {

		// ���� ����
		ofs.open("graph.csv",ios::out);

		// ������ ������ ���� ��� ���α׷� ����
		if (!ofs) {
			cout << "The file is not able to open" << endl;
			exit(0);
		}

		// x���� ���� ��� �Լ����� ���Ͽ� ����
		while (xmin < xmax) {
		
			ofs << xmin << "," << poly.value(xmin) << endl;

			// x�� ����
			xmin = xmin + delX;
		}
	
		// ���� �ݱ�
		ofs.close();

	}	
}
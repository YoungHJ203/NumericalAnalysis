#include<math.h>
#include<string>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)
#include"example.h"

// �ð��� ���� �ӵ��� ����ϴ� �Լ� (�ٻ��)
// ti : �ʱ�ð�, vi : �ʱ�ӵ�, dt : �ð�����, ns : ��ȿ����
void example :: printVelocity(float ti, float tf,float vi, float dt,int ns) {

	// �ʱⰪ
	float v = vi;					// ���ϼӵ� (m/s)
	float v0 = vi;					// ���� �ӵ��� �ӽ÷� ������ ���� (m/s)
	float t = ti;					// �ð� (s)
	
	// �⺻ parameters

	// �߷°��ӵ�(m/s^2)		
	// (���� ����� �� : 9.81000042 -> ��ȿ���� 3�ڸ��� �ϸ�, �ſ� ��Ȯ�� ����) 
	float g = 9.81;					

	// ���� (kg)				
	// (���� ����� �� : 68.0999985 -> ��ȿ���� 3�ڸ��� �ϸ�, �ſ� ��Ȯ�� ����)
	float m = 68.1;					

	// ������� (kg/s)
	// (���� ����� �� : 12.5000000 -> �ſ� ��Ȯ�� ����)
	float c = 12.5;					
	
	// ����

	// ��� ��� ���� (��ȿ���ڰ� n�ڸ��̱� ���� ������)
	float es = 0.5*exponential(10, 2 - ns);	

	// �ٻ� ��� ���� (�ʱⰪ 100%�� �����ν�, �Ʒ������� �ݵ�� �ѹ� ������)
	float ea = 100;					
	
	// data�� ������ ���Ͽ� ���õ� ����
	ofstream ofs;					// ���� ��� stream
	string fileName = "Velocity";	// ���ϸ�
	static int call = 0;			// �Լ� ȣ�� Ƚ�� (int type)
	string num;						// �Լ� ȣ�� Ƚ�� (string type)
	string fileExtension = ".csv";	// ���� Ȯ���ڸ�

	// �Լ� ȣ��Ƚ�� �� ��ȯ (int���� char������ ��ȯ)
	num= to_string(call);

	// ���� �̸� ����
	fileName = fileName + num + fileExtension;

	// ���� ���� ���� ����
	ofs.open(fileName.c_str(),ios::out);
	
	// ���� ���⿡ ������ ���
	if (!ofs) {
		cout << "The file can't be open" << endl;

		// ���α׷� ����
		exit(0);
	}

	// ���� ù �κп� �� column �Ӽ����� 
	ofs << "t,velocity,ea" << endl;

	cout << "��� ���� : " << es << "(%)"<< endl;
	cout << "�ð� (s)\t" << "�ӵ� (m/s)\t"<< "  �ٻ� ��� ���� (%)"<<endl;
	// �ٻ� ��� ������ ���������� �۾��� ������ �ݺ� 
	// (��, �־��� ���ܽð� tf���� ���� �ð� t�� �۰ų� ���� ���, ���ܽð����� �ݺ�)
	while (ea>es || t<=tf) {
		// �ð��� ���� �ӵ��� ȭ�鿡 ���
		printf("  %4.1f s\t  %4.1f m/s  \t\t",t,v);

		// �ð��� ���� �ӵ��� csv���Ͽ� ����
		ofs << t << "," << v <<",";

		// �ð� t������ �ӵ��� �ӽ÷� ����
		v0 = v;

		// �ð� t�κ��� �ð� dt ������ �ٻ� �ӵ� ���
		v = v + (g - c*v / m)*dt;						

		// �ٻ� ������
		ea = (v - v0) / v * 100;

		// �ι�° iteration���� �ٻ� ������ ǥ��
		if (t != ti) {
			printf("%6.3f (%%)", ea);
			ofs << ea;
		}

		// �� �� ������
		printf("\n");
		ofs << endl;

		// dt �ð��� �帧
		t = t + dt;
	}

	// �Լ� ȣ�� Ƚ��
	call++;

	// ���� �ݱ�
	ofs.close();
}

// �ð��� ���� �ӵ��� ����ϴ� �Լ� (��Ȯ�� ��)
void example :: printExactVelocity(float ti, float tf,float vi, float dt) {
	
	// �ʱⰪ
	float v = vi;					// ���� ���ϼӵ� (m/s)
	float v0 = vi;					// ���� �ӵ��� �ӽ÷� ������ ���� (m/s)
	float t = ti;					// �ð� (s)

	// �⺻ parameters
	
	// �߷°��ӵ�(m/s^2)		
	// (���� ����� �� : 9.81000042 -> ��ȿ���� 3�ڸ��� �ϸ�, �ſ� ��Ȯ�� ����) 
	float g = 9.81;					
	
	// ���� (kg)				
	// (���� ����� �� : 68.0999985 -> ��ȿ���� 3�ڸ��� �ϸ�, �ſ� ��Ȯ�� ����)
	float m = 68.1;					
	
	// ������� (kg/s)			
	// (���� ����� �� : 12.5000000 -> �ſ� ��Ȯ�� ����)
	float c = 12.5;					
	
	
	// ����

	// ���ſ��� �Ǻ� ���� 
	// (���簪�� �������� ���� ����: 0.5%�����̸�, final value�� �����ߴٰ� ��) 
	float isConvergent = 0.5*exponential(10, -1);		

	// ���簪�� �������� ������� ����
	float difference = 100;								

	// data�� ������ ���Ͽ� ���õ� ����
	ofstream ofs;							// ���� ��� stream
	string fileName = "exactSol.csv";		// �����̸�

	// ������� ���� ����
	ofs.open(fileName.c_str(), ios::out);

	// ���� ù �κп� �� column �Ӽ����� 
	ofs << "t,velocity,ea" << endl;

	cout << "�ð� (s)\t" << "�ӵ� (m/s)\t" << "  �ٻ� ��� ���� (%)" << endl;
	// �ٻ� ��� ������ ���������� �۾��� ������ �ݺ� 
	// (��, �־��� ���ܽð� tf���� ���� �ð� t�� �۰ų� ���� ���, ���ܽð����� �ݺ�)
	while (difference>isConvergent || t<=tf) {
		// �ð��� ���� �ӵ��� ȭ�鿡 ���
		printf("  %4.1f s\t  %4.1f m/s  \t\t", t, v);

		// �ð��� ���� �ӵ��� ���Ͽ� ����
		ofs << t <<","<< v<<",";

		// �ð� t������ �ӵ��� �ӽ÷� ����
		v0 = v;

		// dt �ð��� �帧
		t = t + dt;
		
		// �ð� t�κ��� �ð� dt ������ �ٻ� �ӵ� ���
		v = g*m / c*(1 - exp(-c*t / m));

		// �ι�° iteration���� ���簪�� �������� ������� ���� ��� �� ǥ��
		if (t != ti) {
			// ���� �ӵ��� ���� �ӵ��� ������� ����
			difference = (v - v0) / v * 100;

			// ���� �ӵ��� ���� �ӵ��� ������� ���̸� ȭ�鿡 ���
			printf("%6.3f (%%)",difference);

			// ���� �ӵ��� ���� �ӵ��� ������� ���̸� ���Ͽ� ����
			ofs << difference;
		}

		// �� �� ������
		printf("\n");
		ofs << endl;

	}

	// ���� �ݱ�
	ofs.close();
}

// �����Լ�
float example::exponential(float b, int e) {
	float result=1;

	// ������ ���� ������ ���
	if (e >= 0) {
		for (int i = 0; i < e; i++) {
			result *= result;
		}
	}
	// ������ ���� ������ ���
	else {
		e = abs(e);
		for (int i = 0; i < e; i++) {
			result /= result;
		}
	}

	return result;
}
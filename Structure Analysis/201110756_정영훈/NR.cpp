#include"NR.h"
#include"example.h"

// Newton-Raphson Method
float NR::method(Polynominal poly, float x, int ns ,int iterMax) {
	float value = 0;

	try {
		// NR Method로 해를 구함
		value = NR::subMethod(poly,x,ns,iterMax);
	}
	// iteration 횟수가 너무 많은 경우 exception 처리
	catch (int n) {
		// iteration 횟수가 많으면서, 근사 상대 오차가 크게 줄어들지 않은 경우
		if (n >= iterMax) {	
cout << "The initial Value may be needed to be changed or the graph shape shall be checked first"<< endl;
			return FMAX;
		}
	}
	// 미분 값이 0인 경우, exception 처리
	catch (char c) {
cout << "The value of first order derivative is zero, so the iteration can't be processed anymore."<< endl;
	}

	return value;
}

// Newton-Raphson Method 작동부
float NR::subMethod(Polynominal poly, float x, int ns ,int iterMax) {
	int iteration = 1;							// iteration 횟수

	float root=x;								// polynominal의 해			

	// exponential 연산 ( a^b ) 을 사용하기 위해 임시로 만든 객체
	example ex;									
	float Es = 0.5*ex.exponential(10,2-ns);		// 허용 상대 오차
	float Ea = 100;								// 근사 상대 오차

	// 원래 식 (Newton-Raphson Method를 통해 구한 값이 해인지 확인하기 위해 원 식을 유지)
	Polynominal original(poly);					
	Polynominal diff(poly);						// 원래 식의 미분식
	diff.diffPoly();
	
	ofstream ofs;								// 파일로 데이터 출력
	string fileName = "NR";						// 파일 이름
	static int call = 0;						// 함수 호출횟수

	fileName = fileName + to_string(call) + ".csv";

	// 쓰기 모드로 파일 open
	ofs.open(fileName.c_str(), ios::out);

	// 파일이 열리지 않은 경우 프로그램 종료
	if (!ofs) {
		cout << "The file is not able to open" << endl;
		exit(0);
	}

	// 함수 호출횟수 증가시키기
	call++;

	// 속성 (iteration, root)을 파일 첫줄에 쓰기
	ofs << "iteration,root"<<endl;

	// 화면에 속성 목록을 출력하기
	cout << "itertaion\troot\t\tEa" << endl;

	// iteration until Er<=Ea and iteration<iterMax (근사 상대 오차가 허용 상대 오차 보다 작을 때까지)
	while (Ea>Es && iteration < iterMax) {

		// 각 iteration 별로 iteration 횟수와 root를 파일에 저장하기
		ofs << iteration << "," << root <<",";

		// 화면에 값을 출력하기
		cout << right<<"   "  << iteration <<"\t\t"<< setprecision(3)<< root << "\t\t";

		// 근사 상대 오차를 파일에 저장하고 화면에 출력하기
		if (iteration > 1) {
			ofs << Ea;
			cout << Ea;
		}

		// 파일에 저장되는 문자열의 줄을 바꿈
		ofs << endl;

		// 화면에서 줄 바꿈
		cout << endl;

		// 원식에 대입하여 0인지 확인
		if (original.value(root) == 0) {

			// 각 iteration 별로 iteration 횟수와 root를 파일로 출력하기
			ofs << iteration << "," << root << endl;

			// 화면에 값을 출력하기
			cout << "   " << iteration << "\t\t" << setw(3) << root << "\t\t" <<  Ea << endl;

			return root;
		}

		// 이전 값을 저장할 임시 변수
		float old = root;
		
		// 현재 위치에서의 함수 미분 값이 0이면, Newton-Raphson Method 종료 
		if (diff.value(root) == 0) {
			char c='e';
			throw c;
		}
		// 현재 위치에서의 함수 미분 값이 하한 값보다 작으면 경고 메시지 띄우기
		else if (diff.value(root)<LIMIT){	
			cout << "The value of first order derivative is too small for continue the iteration." << endl;
		}

		// next try value for the equation
		root = root - poly.value(root)/diff.value(root) ;

		// Error 계산
		Ea = abs((root - old) / root * 100);

		// iteration 횟수 counting
		iteration++;
	}

	// 각 iteration 별로 iteration 횟수와 root를 파일로 출력하기
	ofs << iteration << "," << root << ","<< Ea<<endl;

	// 화면에 값을 출력하기
	cout << "   " << iteration << "\t\t" << setw(4) << setprecision(1) << root << "\t\t" <<  Ea << endl;

	// 오차가 줄어들지 않은 상태에서 iteration 횟수가 더 많으면, exception 처리
	if (iteration >= iterMax && Ea>Es) {
		throw iteration;
	}

	// 파일 닫기
	ofs.close();

	return root;

}

// Graphical Method
void NR::showGraph(Polynominal poly, float xmin, float xmax, float delX) {

	ofstream ofs;		// 파일 열기

	// x 범위의 하한값이 x 범위의 상한값보다 작은 경우에만 실행
	if (xmin < xmax) {

		// 파일 열기
		ofs.open("graph.csv",ios::out);

		// 파일이 열리지 않은 경우 프로그램 종료
		if (!ofs) {
			cout << "The file is not able to open" << endl;
			exit(0);
		}

		// x범위 내의 모든 함수값을 파일에 저장
		while (xmin < xmax) {
		
			ofs << xmin << "," << poly.value(xmin) << endl;

			// x값 증가
			xmin = xmin + delX;
		}
	
		// 파일 닫기
		ofs.close();

	}	
}
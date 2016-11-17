#include<math.h>
#include<string>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)
#include"example.h"

// 시간에 따른 속도를 출력하는 함수 (근사식)
// ti : 초기시간, vi : 초기속도, dt : 시간간격, ns : 유효숫자
void example :: printVelocity(float ti, float tf,float vi, float dt,int ns) {

	// 초기값
	float v = vi;					// 낙하속도 (m/s)
	float v0 = vi;					// 이전 속도를 임시로 저장할 변수 (m/s)
	float t = ti;					// 시간 (s)
	
	// 기본 parameters

	// 중력가속도(m/s^2)		
	// (실제 저장된 값 : 9.81000042 -> 유효숫자 3자리라 하면, 매우 정확한 값임) 
	float g = 9.81;					

	// 질량 (kg)				
	// (실제 저장된 값 : 68.0999985 -> 유효숫자 3자리라 하면, 매우 정확한 값임)
	float m = 68.1;					

	// 마찰계수 (kg/s)
	// (실제 저장된 값 : 12.5000000 -> 매우 정확한 값임)
	float c = 12.5;					
	
	// 오차

	// 허용 상대 오차 (유효숫자가 n자리이기 위한 허용오차)
	float es = 0.5*exponential(10, 2 - ns);	

	// 근사 상대 오차 (초기값 100%로 함으로써, 아래과정을 반드시 한번 실행함)
	float ea = 100;					
	
	// data를 저장할 파일에 관련된 변수
	ofstream ofs;					// 파일 출력 stream
	string fileName = "Velocity";	// 파일명
	static int call = 0;			// 함수 호출 횟수 (int type)
	string num;						// 함수 호출 횟수 (string type)
	string fileExtension = ".csv";	// 파일 확장자명

	// 함수 호출횟수 형 변환 (int형을 char형으로 변환)
	num= to_string(call);

	// 파일 이름 생성
	fileName = fileName + num + fileExtension;

	// 쓰기 모드로 파일 열기
	ofs.open(fileName.c_str(),ios::out);
	
	// 파일 열기에 실패한 경우
	if (!ofs) {
		cout << "The file can't be open" << endl;

		// 프로그램 종료
		exit(0);
	}

	// 파일 첫 부분에 각 column 속성쓰기 
	ofs << "t,velocity,ea" << endl;

	cout << "허용 오차 : " << es << "(%)"<< endl;
	cout << "시간 (s)\t" << "속도 (m/s)\t"<< "  근사 상대 오차 (%)"<<endl;
	// 근사 상대 오차가 허용오차보다 작아질 때까지 반복 
	// (단, 주어진 종단시간 tf보다 현재 시간 t가 작거나 같은 경우, 종단시간까지 반복)
	while (ea>es || t<=tf) {
		// 시간에 따른 속도를 화면에 출력
		printf("  %4.1f s\t  %4.1f m/s  \t\t",t,v);

		// 시간에 따른 속도를 csv파일에 쓰기
		ofs << t << "," << v <<",";

		// 시간 t에서의 속도를 임시로 저장
		v0 = v;

		// 시간 t로부터 시간 dt 이후의 근사 속도 계산
		v = v + (g - c*v / m)*dt;						

		// 근사 상대오차
		ea = (v - v0) / v * 100;

		// 두번째 iteration부터 근사 상대오차 표시
		if (t != ti) {
			printf("%6.3f (%%)", ea);
			ofs << ea;
		}

		// 한 줄 내리기
		printf("\n");
		ofs << endl;

		// dt 시간이 흐름
		t = t + dt;
	}

	// 함수 호출 횟수
	call++;

	// 파일 닫기
	ofs.close();
}

// 시간에 따른 속도를 출력하는 함수 (정확한 식)
void example :: printExactVelocity(float ti, float tf,float vi, float dt) {
	
	// 초기값
	float v = vi;					// 실제 낙하속도 (m/s)
	float v0 = vi;					// 이전 속도를 임시로 저장할 변수 (m/s)
	float t = ti;					// 시간 (s)

	// 기본 parameters
	
	// 중력가속도(m/s^2)		
	// (실제 저장된 값 : 9.81000042 -> 유효숫자 3자리라 하면, 매우 정확한 값임) 
	float g = 9.81;					
	
	// 질량 (kg)				
	// (실제 저장된 값 : 68.0999985 -> 유효숫자 3자리라 하면, 매우 정확한 값임)
	float m = 68.1;					
	
	// 마찰계수 (kg/s)			
	// (실제 저장된 값 : 12.5000000 -> 매우 정확한 값임)
	float c = 12.5;					
	
	
	// 오차

	// 수렴여부 판별 기준 
	// (현재값과 이전값의 차이 비율: 0.5%이하이면, final value에 도달했다고 봄) 
	float isConvergent = 0.5*exponential(10, -1);		

	// 현재값과 이전값의 상대적인 차이
	float difference = 100;								

	// data를 저장할 파일에 관련된 변수
	ofstream ofs;							// 파일 출력 stream
	string fileName = "exactSol.csv";		// 파일이름

	// 쓰기모드로 파일 열기
	ofs.open(fileName.c_str(), ios::out);

	// 파일 첫 부분에 각 column 속성쓰기 
	ofs << "t,velocity,ea" << endl;

	cout << "시간 (s)\t" << "속도 (m/s)\t" << "  근사 상대 오차 (%)" << endl;
	// 근사 상대 오차가 허용오차보다 작아질 때까지 반복 
	// (단, 주어진 종단시간 tf보다 현재 시간 t가 작거나 같은 경우, 종단시간까지 반복)
	while (difference>isConvergent || t<=tf) {
		// 시간에 따른 속도를 화면에 출력
		printf("  %4.1f s\t  %4.1f m/s  \t\t", t, v);

		// 시간에 따른 속도를 파일에 쓰기
		ofs << t <<","<< v<<",";

		// 시간 t에서의 속도를 임시로 저장
		v0 = v;

		// dt 시간이 흐름
		t = t + dt;
		
		// 시간 t로부터 시간 dt 이후의 근사 속도 계산
		v = g*m / c*(1 - exp(-c*t / m));

		// 두번째 iteration부터 현재값과 이전값의 상대적인 차이 계산 및 표시
		if (t != ti) {
			// 현재 속도와 이전 속도의 상대적인 차이
			difference = (v - v0) / v * 100;

			// 현재 속도와 이전 속도의 상대적인 차이를 화면에 출력
			printf("%6.3f (%%)",difference);

			// 현재 속도와 이전 속도의 상대적인 차이를 파일에 쓰기
			ofs << difference;
		}

		// 한 줄 내리기
		printf("\n");
		ofs << endl;

	}

	// 파일 닫기
	ofs.close();
}

// 제곱함수
float example::exponential(float b, int e) {
	float result=1;

	// 지수가 양의 정수인 경우
	if (e >= 0) {
		for (int i = 0; i < e; i++) {
			result *= result;
		}
	}
	// 지수가 음의 정수인 경우
	else {
		e = abs(e);
		for (int i = 0; i < e; i++) {
			result /= result;
		}
	}

	return result;
}
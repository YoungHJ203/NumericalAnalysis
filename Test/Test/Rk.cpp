#include"RK.h"
#include<string>
// RK method
void RK::method(Polynomial& p, float ti, float yi, float tf, float del, Mode m) {
	float t = ti;								// current time
	float (*phi)(Polynomial&,float,float);		// slope of the interval 
	float fvalue = yi;							// initial function value
	string filename = "data";					// file name 
	string extension = ".csv";					// file extension
	static int num = 0;							// The number of function call

	// out file stream
	ofstream ofs;

	filename = filename + to_string(num) + extension;
	num++;	// increase the number of function call
	// file open in write mode
	ofs.open(filename.c_str(), ios::out);

	// when opening the file fail, halt the program and give the warning
	if (!ofs) {
		cout << "The file \' data.csv \' can't open" << endl;
		exit(0);
	}

	// method's mode case
	switch (m) {
		// heun method
		case 0: {
			phi = RK::heun; break;
		}
		// ralston method
		case 1: {
			phi = RK::ralston; break;
		}
		// else other method
		default: { return; } 
	}

	cout << "Time \t\t\t" << "function"<<endl;
	ofs << "Time,function" << endl;
	// print the initial time and function value
	cout << t << " \t\t\t" << fvalue << endl;
	ofs << t << "," << fvalue << endl;

	// iterate until the current time reaches the final time
	while (t < tf) {
		// increase the current time 
		if (t + del <= tf) {
			t = t + del;
		}
		else {
			del = tf - t;
			t = tf;			
		}

		// get the function value
		fvalue = fvalue + phi(p, t - del, t)*del;

		// print the value
		cout << t << " \t\t\t" << fvalue << endl;
		ofs << t << "," << fvalue << endl;
	}
}

// get the average slope of the interval using heun method
float RK::heun(Polynomial& p, float t1, float t2) {
	return 0.5*p(t1) + 0.5*p(t2);
}

// get the average slope of the interval using ralston method
float RK::ralston(Polynomial& p, float t1, float t2){
	float h = t2 - t1;
	return (p(t1) + 2 * p(t1 + 3 * h / 4)) / 3;
}
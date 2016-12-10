#pragma once
#include"Polynomial.h"
#include<fstream>
#define Mode int

// Runge-Kutta method
class RK {
public:	
	// Rugge-Kutta method (Parameter : ODE, initial time, final time, step size, Mode)
	static void method(Polynomial&, float, float, float, float, Mode);

	// get the average slope of the interval using heun method
	static float heun(Polynomial&, float, float);

	// get the average slope of the interval using ralston method
	static float ralston(Polynomial&, float, float);
};
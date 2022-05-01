#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

struct Complex {
	Complex() {

	}
	Complex(double a, double b) {
		im = a;
		re = b;
	}
	~Complex() {

	}
	double im = 0;
	double re = 0;

	Complex sum(Complex n1, Complex n2);
	Complex ex(Complex n1, Complex n2);
	Complex mul(Complex n1, Complex n2);
	Complex div(Complex n1, Complex n2);
	void out();
	double module();

};
void inpt(Complex n1, Complex n2);
void partB();

#endif

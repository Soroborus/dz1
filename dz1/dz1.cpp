#include <iostream>
#include <string>
#include "complex.h"
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "какое задание, 1 или 2? ";
	int z;
	cin >> z;
	if (z == 1) {


		Complex a, b;
		inpt(a, b);			//вызов управляющей функции для а или для б
		a.~Complex();
		b.~Complex();
	}
	else if (z == 2) {
		partB();
	}
	else {
		cout << "такого задания тут нет";
	}

	return 0;
}
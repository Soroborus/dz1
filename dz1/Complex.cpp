//сделаны оба варианта заданий


#include "complex.h"
//действия
Complex sum(Complex n1, Complex n2)
{
	Complex res;
	res.im = n1.im + n2.im;
	res.re = n1.re + n2.re;
	return res;
}
Complex ex(Complex n1, Complex n2)
{
	Complex res;
	res.im = (n1.im - n2.im);
	res.re = (n1.re - n2.re);
	return res;
}
Complex mul(Complex n1, Complex n2) {
	Complex res;
	double a = 0; double b = 0; //переменные-буферы чтобы не потерять число
	a = n1.im * n2.re + n2.im * n1.re;
	b = n1.re * n2.re - n1.im * n2.im;
	res.im = a;
	res.re = b;
	return res;
}
Complex div(Complex n1, Complex n2) {
	Complex n3, nres, res, res1;
	n3 = n2;
	n3.im *= -1;
	nres = mul(n3, n2);
	res1 = mul(n3, n1);
	res.im = res1.im / nres.re;
	res.re = res1.re / nres.re;
	return res;
}
//ввод-вывод
void inpt(Complex n1, Complex n2)
{
	Complex result;
	bool iffail = 0;
	char w;
	cout << "Введите два комплексных числа и арифметическое действие" << endl;
	cout << "     i*";
	cin >> n1.im;

	char n;

	cin >> n;

	switch (n)
	{
	case '+': {
		cin >> n1.re;
		break;
	}
	case '-': {
		cin >> n1.re;
		n1.re *= -1;
		break;
	}

	default:
		cout << "Ошибка ввода";
		iffail = 1;
		break;
	}
	if (!iffail) {
		cout << endl;
		cin >> w;
		if ((w != '+') && (w != '-') && (w != '*') && (w != '/')) {
			cout << "ОШИБКА ВВОДА ЗНАКА" << endl;
			iffail = 1;
			exit;
		}
		cout << endl;
		if (!iffail) {
			cout << "     i*";
			cin >> n2.im;

			cin >> n;

			switch (n)
			{
			case '+': {
				cin >> n2.re;
				break;
			}
			case '-': {
				cin >> n2.re;
				n2.re *= -1;

				break;
			}
			default:
				cout << "Ошибка ввода 1";
				iffail = 1;
				break;
			}
		}
	}
	if (!iffail) {

		switch (w) {
		case '+': {
			result = sum(n1, n2);
			break;
		}
		case '-': {
			result = ex(n1, n2);
			break;
		}
		case '*': {
			result = mul(n1, n2);
			break;
		}
		case '/': {
			if (!((n2.im == 0) && (n2.re == 0))) {
				result = div(n1, n2);
			}
			else {
				cout << "Ошибка, на 0 делить нельзя" << endl;
				iffail = 1;
			}
			break;
		}
		default: {
			cout << "ошибка ввода 2" << endl;
			iffail = 1;
			break;
		}
		}
	}
	if (!iffail) {
		cout << endl;
		cout << "ответ: ";
		result.out();
	}
}
void Complex::out() {
	if (((im != -1) && (im != 1)) && (im != 0)) {
		cout << im << "i";
	}
	else if (im == -1) {
		cout << "-i";
	}
	else if (im == 1) {
		cout << "i";
	}
	if (re > 0) {
		if (im != 0) {
			cout << "+" << re;
		}
		else {
			cout << re;
		}
	}
	else if (re < 0) {
		cout << re;
	}
	if ((im == 0) && (re == 0)) {
		cout << 0;
	}

}
//функция для части б
void partB() {
	ifstream l;	//часть Б
	l.open("C://texts/complex.txt");
	int n = 0;
	string s;							//поснение: строка s используется для считывания чисел a+b*i и просто "дочитывает" *i в конце
	l >> n;
	double max = 0;
	int index = 0;
	Complex* p = new Complex[n]; //динамический массив
	for (int i = 0; i < n; i++) {
		l >> p[i].re >> p[i].im >> s;				//считываем в массив и считаем модули

		if (p[i].module() > max) {
			index = i;
			max = p[i].module();
		}
	}
	l.close();
	cout << "Максимальный модуль у " << index + 1 << " элемента (";
	p[index].out();
	cout << ") равный " << p[index].module();
	delete[] p;
}
//поиск модуля
double Complex::module() {

	return sqrt(im * im + re * re);
}

#include <iostream>
void tens_10_19(int dh);
void tens(int a);
void dozens(int b,int& h);
void hundreds(int c);
int counter(int& a);
void thousand(int a,int& val);
void print_name(int& val, int ind,int sum);
// P.S. Разряды не зависят от размера 
int main() {
	setlocale(LC_ALL, "rus");
	int value;
	std::cout << "Введите число: ";
	std::cin >> value;
	if (counter(value) > 7) std::cout << "\nВаше число больше допустимого (9 999 999)\n";
	else {
		std::cout << std::endl;
		std::cout << "Его название: ";
		short ind = counter(value);
		short temp = ind;
		for (int i = 1; i <= temp; ++i) {
			print_name(value, ind, counter(value));
			if (ind == 4) {
				short a = (value / 1000 % 10);
				thousand(a,value);
			}
			ind--;
		}
	}
	std::cout << '\n';
	system("PAUSE");
	return 0;
}
// Искючения для названия 4 разряда числа.
void exception(int a) {
	switch (a) {
	case 1: {
		std::cout << "одна ";
		break;
	}
	case 2: {
		std::cout << "две ";
		break;
	}
	}
}
// Тысячи (выводит после вывода 4 разряда числа)
void thousand(int a,int& val) {
	switch (a) {
	case 0: {
		std::cout << "";
		break;
	}
	case 1: {
		if (val / 10000 % 10 == 1) {
			std::cout << "тысяч ";
		}
		else {
			std::cout << "тысяча ";
		}
		break;
	}
	case 2: {
		if (val / 10000 % 10 == 1) {
			std::cout << "тысяч ";
		}
		else {
			std::cout << "тысячи ";
		}
		break;
	}
	case 3: {
		std::cout << "тысячи ";
		break;
	}
	case 4: {
		std::cout << "тысячи ";
		break;
	}
	default: {
		std::cout << "тысяч ";
		break;
	}
	}
}
// Выводит название ОДНОГО разряда от числа (в зависимости от его положения и возможных исключений)
void print_name(int& val,int ind,int sum) {
	switch (ind) {
	case 7: {
		short a;
		a = (val / 1000000);
		tens(a);
		if (a == 1) {
			std::cout << "миллион ";
		}
		else if (a > 1 && a < 5) {
			std::cout << "миллиона ";
		}
		else if (a > 4 && a < 10) {
			std::cout << "миллионов ";
		}
		break;
	}
	case 6: {
		short c;
		c = ((val / 100000) % 10);
		hundreds(c);
		break;
	}
	case 5: {
		short b;
		b = ((val / 10000) % 10);
		if (b == 1) {
			short h = (val / 1000 % 10);
			tens_10_19(h);
		}
		else dozens(b, val);
		break;
	}
	case 4: {
		short a;
		a = ((val / 1000) % 10);
		if (val / 10000 % 10 == 1) {
			break;
		}
		else if ((a == 0) && (sum != 1)) break;
		else if ((a == 1) || (a == 2)) exception(a);
		else tens(a);
		break;
	}
	case 3: {
		short c;
		c = ((val / 100) % 10);
		hundreds(c);
		break;
	}
	case 2: {
		short b;
		b = ((val / 10) % 10);
		if (b == 1) {
			short h = (val%10);
			tens_10_19(h);
		}
		else dozens(b,val);
		break;
	}
	case 1: {
		short a;
		a = (val % 10);
		if (val / 10 % 10 == 1) {
			break;
		}
		if ((a == 0) && (sum != 1)) break;
		// ПасхалОчка))
		else if ((a == 0) && (sum == 1)) {
			std::cout << " IT'S ZEEERRROOOO MAAAAAAAAAAN!!!!\n";
		}
		else tens(a);
	}
	}
	
}
// Числа-исключения (10-19)
void tens_10_19(int dh) {
	switch (dh) {
	case 0: {
		std::cout << "десять ";
		break;
	}
	case 1: {
		std::cout << "одиннадцать ";
		break;
	}
	case 2: {
		std::cout << "двенадцать ";
		break;
	}
	case 3: {
		std::cout << "тринадцать ";
		break;
	}
	case 4: {
		std::cout << "четырнадцать ";
		break;
	}
	case 5: {
		std::cout << "пятнадцать ";
		break;
	}
	case 6: {
		std::cout << "шестнадцать ";
		break;
	}
	case 7: {
		std::cout << "семнадцать ";
		break;
	}
	case 8: {
		std::cout << "восемнадцать ";
		break;
	}
	case 9: {
		std::cout << "девятнадцать ";
		break;
	}
	}
}
// Цифры (0-9)
void tens(int a) {
	switch (a) {
	case 0: {
		std::cout << "ноль ";
		break;
	}
	case 1: {
		std::cout << "один "; // В 4 разряде не учитывается
		break;
	}
	case 2: {
		std::cout << "два "; // В 4 разряде не учитывается
		break;
	}
	case 3: {
		std::cout << "три ";
		break;
	}
	case 4: {
		std::cout << "четыре ";
		break;
	}
	case 5: {
		std::cout << "пять ";
		break;
	}
	case 6:{
		std::cout << "шесть ";
		break;
	}
	case 7:{
		std::cout << "семь ";
		break;
	}
	case 8:{
		std::cout << "восемь ";
		break;
	}
	case 9: {
		std::cout << "девять ";
		break;
	}
	}
}
// Десятки
void dozens(int b,int &h) {
	switch (b) {
	case 0: {
		std::cout << "";
		break;
	}
	case 1: {
		short dh;
		dh = (h / 1000) % 1000;
		tens_10_19(dh);
		break;
	}
	case 2: {
		std::cout << "двадцать ";
		break;
	}
	case 3: {
		std::cout << "тридцать ";
		break;
	}
	case 4: {
		std::cout << "сорок ";
		break;
	}
	case 5: {
		std::cout << "пятьдесят ";
		break;
	}
	case 6: {
		std::cout << "шестьдесят ";
		break;
	}
	case 7: {
		std::cout << "семьдесят ";
		break;
	}
	case 8: {
		std::cout << "восемьдесят ";
		break;
	}
	case 9: {
		std::cout << "девяносто ";
		break;
	}
	}
}
// Сотни
void hundreds(int c) {
	switch (c) {
	case 0: {
		std::cout << "";
		break;
	}
	case 1: {
		std::cout << "сто ";
		break;
	}
	case 2: {
		std::cout << "двести ";
		break;
	}
	case 3: {
		std::cout << "триста ";
		break;
	}
	case 4: {
		std::cout << "четыреста ";
		break;
	}
	case 5: {
		std::cout << "пятьсот ";
		break;
	}
	case 6: {
		std::cout << "шестьсот ";
		break;
	}
	case 7: {
		std::cout << "семьсот ";
		break;
	}
	case 8: {
		std::cout << "восемьсот ";
		break;
	}
	case 9: {
		std::cout << "девятьсот ";
		break;
	}
	}
}
// Считает количество символов.
int counter(int& a) {
	int counter = 1;
	int del = 10;
	for (int i = 1; i < 100; ++i) {
		if (a / del == 0) break;
		else {
			counter++;
			del *= 10;
		};
	}
	return counter;
}

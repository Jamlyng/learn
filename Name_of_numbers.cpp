#include <iostream>
void tens_10_19(int dh);
void tens(int a);
void dozens(int b,int& h);
void hundreds(int c);
int counter(int& a);
void thousand(int a);
void print_name(int& val, int ind,int sum);
// P.S. ������� �� ������� �� ������� (��� � ��� �������, ������� �� ������ � xdd)
int main() {
	setlocale(LC_ALL, "rus");
	int value;
	std::cout << "������� �����: ";
	std::cin >> value;
	if (counter(value) > 7) std::cout << "\n���� ����� ������ ����������� (9 999 999)\n";
	else {
		std::cout << std::endl;
		std::cout << "��� ��������: ";
		short ind = counter(value);
		short temp = ind;
		for (int i = 1; i <= temp; ++i) {
			print_name(value, ind, counter(value));
			if (ind == 4) {
				short a = (value / 1000 % 10);
				thousand(a);
			}
			ind--;
		}
	}
	std::cout << '\n';
	system("PAUSE");
	return 0;
}
// ��������� ��� �������� 4 ������� �����.
void exception(int a) {
	switch (a) {
	case 1: {
		std::cout << "���� ";
		break;
	}
	case 2: {
		std::cout << "��� ";
		break;
	}
	}
}
// ������ (������� ����� ������ 4 ������� �����)
void thousand(int a) {
	switch (a) {
	case 0: {
		std::cout << "";
		break;
	}
	case 1: {
		std::cout << "������ ";
		break;
	}
	case 2: {
		std::cout << "������ ";
		break;
	}
	case 3: {
		std::cout << "������ ";
		break;
	}
	case 4: {
		std::cout << "������ ";
		break;
	}
	default: {
		std::cout << "����� ";
		break;
	}
	}
}
// ������� �������� ������ ������� �� ����� (� ����������� �� ��� ��������� � ��������� ����������)
void print_name(int& val,int ind,int sum) {
	switch (ind) {
	case 7: {
		short a;
		a = (val / 1000000);
		tens(a);
		if (a == 1) {
			std::cout << "������� ";
		}
		else if (a > 1 && a < 5) {
			std::cout << "�������� ";
		}
		else if (a > 4 && a < 10) {
			std::cout << "��������� ";
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
		// ����������))
		else if ((a == 0) && (sum == 1)) {
			std::cout << " IT'S ZEEERRROOOO MAAAAAAAAAAN!!!!\n";
			std::cout << "WW\nww\nhh\nhh";
			for (int i = 0; i < 30; ++i) {
				std::cout << "\nOOOOO";
			}
			std::cout << "\naa\naa\naa!!!!!!!";
		}
		else tens(a);
	}
	}
	
}
// �����-���������� (10-19)
void tens_10_19(int dh) {
	switch (dh) {
	case 0: {
		std::cout << "������ ";
		break;
	}
	case 1: {
		std::cout << "����������� ";
		break;
	}
	case 2: {
		std::cout << "���������� ";
		break;
	}
	case 3: {
		std::cout << "���������� ";
		break;
	}
	case 4: {
		std::cout << "������������ ";
		break;
	}
	case 5: {
		std::cout << "���������� ";
		break;
	}
	case 6: {
		std::cout << "����������� ";
		break;
	}
	case 7: {
		std::cout << "���������� ";
		break;
	}
	case 8: {
		std::cout << "������������ ";
		break;
	}
	case 9: {
		std::cout << "������������ ";
		break;
	}
	}
}
// ����� (0-9)
void tens(int a) {
	switch (a) {
	case 0: {
		std::cout << "���� ";
		break;
	}
	case 1: {
		std::cout << "���� "; // � 4 ������� �� �����������
		break;
	}
	case 2: {
		std::cout << "��� "; // � 4 ������� �� �����������
		break;
	}
	case 3: {
		std::cout << "��� ";
		break;
	}
	case 4: {
		std::cout << "������ ";
		break;
	}
	case 5: {
		std::cout << "���� ";
		break;
	}
	case 6:{
		std::cout << "����� ";
		break;
	}
	case 7:{
		std::cout << "���� ";
		break;
	}
	case 8:{
		std::cout << "������ ";
		break;
	}
	case 9: {
		std::cout << "������ ";
		break;
	}
	}
}
// �������
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
		std::cout << "�������� ";
		break;
	}
	case 3: {
		std::cout << "�������� ";
		break;
	}
	case 4: {
		std::cout << "����� ";
		break;
	}
	case 5: {
		std::cout << "��������� ";
		break;
	}
	case 6: {
		std::cout << "���������� ";
		break;
	}
	case 7: {
		std::cout << "��������� ";
		break;
	}
	case 8: {
		std::cout << "����������� ";
		break;
	}
	case 9: {
		std::cout << "��������� ";
		break;
	}
	}
}
// �����
void hundreds(int c) {
	switch (c) {
	case 0: {
		std::cout << "";
		break;
	}
	case 1: {
		std::cout << "��� ";
		break;
	}
	case 2: {
		std::cout << "������ ";
		break;
	}
	case 3: {
		std::cout << "������ ";
		break;
	}
	case 4: {
		std::cout << "��������� ";
		break;
	}
	case 5: {
		std::cout << "������� ";
		break;
	}
	case 6: {
		std::cout << "�������� ";
		break;
	}
	case 7: {
		std::cout << "������� ";
		break;
	}
	case 8: {
		std::cout << "��������� ";
		break;
	}
	case 9: {
		std::cout << "��������� ";
		break;
	}
	}
}
// ������� ���������� ��������.
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
#include "Name_of_numbers(int).h"
int main() {
	setlocale(LC_ALL, "rus");
	int value = 1;
	while (value != 0) {
		std::cout << "¬ведите число(дл€ выхода 0): ";
		std::cin >> value;
		print_full_name(value);
		std::cout << std::endl;
	}
	system("PAUSE");
	return 0;
}
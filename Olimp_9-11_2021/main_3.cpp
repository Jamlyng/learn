#include <iostream>
#include <cstring>
int main() {
	char Comand[250];
	int x, y;
	int temp_integer = 0;
	x = y = 0;
	char Direction = 'E';
	std::cin >> Comand;
	for (int i = 0; i < strlen(Comand); ++i) {
		switch (Comand[i]) {
		case 'L': {
			switch (Direction) {
			case 'E': {
				Direction = 'N';
				break;
			}
			case 'N': {
				Direction = 'W';
				break;
			}
			case 'W': {
				Direction = 'S';
				break;
			}
			case 'S': {
				Direction = 'E';
				break;
			}
			}
			break;
		}
		case 'R': {
			switch (Direction) {
			case 'E': {
				Direction = 'S';
				break;
			}
			case 'N': {
				Direction = 'E';
				break;
			}
			case 'W': {
				Direction = 'N';
				break;
			}
			case 'S': {
				Direction = 'W';
				break;
			}
			}
			break;
		}
		case 'B': {
			switch (Direction) {
			case 'E': {
				Direction = 'W';
				break;
			}
			case 'N': {
				Direction = 'S';
				break;
			}
			case 'W': {
				Direction = 'E';
				break;
			}
			case 'S': {
				Direction = 'N';
				break;
			}
			}
			break;
		}
		case 'F': {
			int p;
			int q=0;
			if (249 - i >= 3) {
				p = 3;
			}
			else {
				p = 249 - i;
			}
			for (int j = 1; j <= p;++j) {
				if ((Comand[i + j] >= '0') && (Comand[i + j] <= '9')) {
					q++;
				}
				else {
					break;
				}
			}
			char* temp = new char[q];
			for (int j = 1; j <= p; ++j) {
				if ((Comand[i + j] >= '0') && (Comand[i + j] <= '9')) {
					temp[j-1] = Comand[i + j];
				}
				else {
					break;
				}
			}
			temp_integer = atoi(temp);
			switch (Direction) {
			case 'E': {
				x+=temp_integer;
				break;
			}
			case 'N': {
				y+=temp_integer;
				break;
			}
			case 'W': {
				x-=temp_integer;
				break;
			}
			case 'S': {
				y-=temp_integer;
				break;
			}
			}
			break;
		}
		}
	}
	std::cout << x << '\n' << y << '\n' << Direction;
	return 0;
}
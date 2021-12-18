#include <iostream>
int main() {
	int N, i, j;
	std::cin >> N >> i >> j;
	int i_t,j_t;
	if ((N - (N - i)-1)>(N - i)) {
		i_t = (N - (N - i)-1);
	}
	else {
		i_t = N - i;
	}
	if ((N - (N - j)-1) > (N - j)) {
		j_t = (N - (N - j)-1);
	}
	else {
		j_t = N - j;
	}
	if (i_t > j_t) {
		std::cout << i_t;
	}
	else {
		std::cout << j_t;
	}
	return 0;
}
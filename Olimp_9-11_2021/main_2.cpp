#include <iostream>
int main() {
	int N, M, D, T;
	int q_k;
	std::cin >> N >> M >> D >> T;
	q_k = N / M;
	if (N % M == 0) {

	}
	else {
		q_k++;
	}
	std::cout << (T * (q_k - 1) + D);
	return 0;
}
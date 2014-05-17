/*
 * primNumberCount.cpp
 *
 *  Created on: 17-Apr-2014
 *      Author: gyani
 */

#include<iostream>
using namespace std;
int primeCount(int n) {
	int count = 0;

	for (int i = 2; i <= n; i++) {
		int j = 2;
		while (j < i) {
			if (i % j == 0) {
				break;
			}
			j++;
		}
		if (i == j) {
			count++;
		}

	}
	return count;
}
int main() {
	int a = 100;
	int b = primeCount(a);
	cout << "no of prime:" << b;
	return 0;
}

//if all number are +ve then sum of all will be max sum

#include<iostream>
using namespace std;

int main() {

	int aa[] = { -2, 11, -4, 13, -5, 2 };
	int size = 6;
	int maxSum = 0;

//using brute force method
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			int currentSum = 0;
			for (int k = i; k < j; k++) {
				currentSum += aa[k];
			}

			if (maxSum < currentSum)
				maxSum = currentSum;
		}
	}

	cout << "max Sum using brute force is :" << maxSum;
//using dp
	//array which hold the intermediate result
	int m[6];
	int maxSum1 = 0;
	if (aa[0] > 0)
		m[0] = aa[0];
	else
		m[0] = 0;

	for (int i = 1; i < size; i++) {
		if (m[i - 1] + aa[i] > 0)
			m[i] = m[i - 1] + aa[i];
		else
			m[i] = 0;
	}

	for (int j = 0; j < size; j++) {
		if (maxSum1 < m[j])
			maxSum1 = m[j];
	}

	cout<<"max sum using DP: "<<maxSum1;

	return 0;
}

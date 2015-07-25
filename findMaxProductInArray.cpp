#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int main() {

	int arr[10] = {1, 3, 5, -1, 6, 9, 9, -10};

	int maxEle = INT_MIN;
	int secondMaxEle = INT_MIN;

	int minEle = INT_MAX;
	int secondMinEle = INT_MAX;

	for (int i = 0; i < 8; i++) {
		if (maxEle < arr[i]) {
			secondMaxEle = maxEle;
			maxEle = arr[i];
		}

		if (minEle > arr[i]) {
			secondMinEle = minEle;
			minEle = arr[i];

		}
	}

	int maxProd1 = maxEle * secondMaxEle;
	int maxProd2 = minEle * secondMinEle;
	int maxProd;
	if (maxProd1 > maxProd2) {
		maxProd = maxProd1;
	}
	else {
		maxProd = maxProd2;
	}

	cout << " max product: " << maxProd << " ";
	cout << "max element: " << maxEle << " ";
	cout << "second max element: " << secondMaxEle << " ";
	cout << "min element: " << minEle << " ";
	cout << "second min element: " << secondMinEle << " ";

	return 0;
}

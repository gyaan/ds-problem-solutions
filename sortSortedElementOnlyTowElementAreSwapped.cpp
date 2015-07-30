#include<iostream>
using namespace std;
int main() {

	int arr[6] = {12, 22, 16, 18, 20, 14};
	int size = 6;
	int swapEle1, swapEle2, temp, i, k;
	// find the  element form right side
	for (i = size - 1; i >= 0; i--) {

		if (arr[i] < arr[i - 1]) {
			swapEle1 = i;
			break;
		}
	}

	// cout<<i;

	for (k = 0; k < i - 1; k++) {
		if (arr[k] > arr[k + 1]) {
			swapEle2 = k;
			break;
		}
	}

	temp = arr[swapEle2];
	arr[swapEle2] = arr[swapEle1];
	arr[swapEle1] = temp;

	for (int j = 0; j <= size - 1; j++) {
		cout << arr[j] << "-->";
	}
	return 0;
}

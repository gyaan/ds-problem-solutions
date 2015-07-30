#include<iostream>
#include<stack>
using namespace std;

void printLeftMostSmallerElement(int arr[], int n) {

	stack<int>s;
	for (int i = 0; i < n; i++) {

		while (!s.empty() && s.top() >= arr[i])
			s.pop();

		if (s.empty())
			cout << "_, ";
		else
			cout << s.top() << ", ";
		s.push(arr[i]);


	}


}
int main() {

	int arr [5] = {1, 3, 0, 2, 5};

    printLeftMostSmallerElement(arr,5);
	return 0;
}


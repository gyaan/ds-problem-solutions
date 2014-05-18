#include<iostream>
#include<stack>
using namespace std;

int * getPeaks(int a[], int size);
int * getPeaksUsingStack(int a[], int size);

int main() {

	int size = 5;
	int arr[] = { 6, 3, 4, 5, 2 };
	int *p;
	int i;

	//using simple brute force method
    //p = getPeaks(arr, size);

	//using stack
	p = getPeaksUsingStack(arr, size);

	//print the output
	for (i = 0; i < 5; i++) {
		cout << arr[i] << " peaks of :" << *(p + i) << " days" << endl;
	}
	return 0;
}

int * getPeaks(int a[], int size) {
	static int s[5];
	int i, j;

	for (i = 0; i < size; i++) {
		j = 1;

		while (j <= i && a[i] >= a[i - j])
			j++;

		s[i] = j;

	}
	return s;
}

int * getPeaksUsingStack(int a[], int size) {
	//variable to store peaks value
	static int s[5];

	//a stack to store precedence highest value
	stack <int> st;

	int p,i;

	//let calculate the peaks
	for (i = 0; i < size; i++) {
		while (!st.empty() && a[i] > st.top())
				st.pop();

		if (st.empty())
			s[i]=i+1;
		else
			s[i] = i-st.top();

		st.push(i);
	}
	return s;
}

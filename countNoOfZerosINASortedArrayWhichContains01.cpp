/* Problem : count no Of zeros in a given sorted array which have only 1 and 0
 * removeDuplicateFromString.cpp
 * Created on: 12-May-2014
 * Author: Gyaneshwar Pardhi
 */

#include<iostream>
using namespace std;

int countNoOfZeros(int a[], int start, int end);
int main() {

	int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 1, 1, 1, 1,1, 1, 1,1,1, 1, 1, 1, 1, 1, 1, 1 };
	int arrayLenght = 34;
	int count = 0;
	count = countNoOfZeros(a, 0, arrayLenght-1);
	cout << count;
	return 0;
}

int countNoOfZeros(int a[], int start, int end) {

	int mid = (end + start) / 2;

	if (a[mid] == 0 && a[mid + 1] == 0)
		return (countNoOfZeros(a, mid + 1, end));
	else if (a[mid] == 1 && a[mid - 1] == 1)
		return countNoOfZeros(a, start, mid - 1);
	else if (a[mid] == 0 && a[mid + 1] == 1)
		return mid + 1;
	else
		return mid;

}


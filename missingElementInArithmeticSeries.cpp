#include <iostream>
#include<cmath>
using namespace std;
int main() {

	int noOfElements;
	int a[100];

	cout<<"enter how many number in arithmetic series"<<endl;
	cin >> noOfElements;
	cout<<endl;
	cout<<"enter elements of of arithmetic series"<<endl;

	for (int j = 0; j < noOfElements; j++) {
		cin >> a[j];
	}

	int commondiff = a[1] - a[0];
	int firstElement = a[0];
	bool flag = 0;

	for (int k = 2; k <= noOfElements; k++) {
		int nextElement = firstElement + (k - 1) * commondiff;
		if (a[k - 1] != nextElement) {
			flag=1;
			cout <<"Missing Element is :"<<nextElement<<endl;
			break;
		}
	}

	if(flag==0){
		cout<<"There is no missing Element"<<endl;
	}
	return 0;
}

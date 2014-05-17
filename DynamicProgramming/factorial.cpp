#include<iostream>
using namespace std;

int fact(int n);
//declare temp array to store intermediate result set
int temp[100];

int main() {

	int factorial;
	factorial = fact(5);
	cout << "fact of is: " << factorial << endl;
	return 0;
}

int fact(int aa) {

	if (aa == 0 || aa == 1) {
		return 1;
	} else {
		if (temp[aa] != 0)
			return temp[aa];
		else
			return temp[aa] = (aa * fact(aa - 1));
	}

}


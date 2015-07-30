#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {

	int n = 5;
	int in[5] = {1, 2, 10, 5, 5};
	int out[5] = {4, 5, 12, 9, 12};

	int ins[5] = {1, 2, 5, 5, 10};
	int outs[5] = {4, 5, 9, 12, 12};

	int i = 1, j = 0;

	int previousGuestCount = 1;

    int maxCount=1;
    int maxI=0;
    int maxJ=1;

	while (i <= n &&	 j <= n) {

		if (ins[i] <= outs[j]) {
			++previousGuestCount ;
			i++;
		}
		else {
			--previousGuestCount;
			j++;
		}

		if(previousGuestCount>maxCount){
			maxCount=previousGuestCount;
			maxI=ins[i-1];
			maxJ=outs[j-1];
		}
	}
    
    cout<<maxCount<<": "<<maxI<<": "<<maxJ<<endl;

	return 0;
}
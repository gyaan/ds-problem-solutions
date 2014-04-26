#include<iostream>
using namespace std;


int main(){

	int number = 7;
	int i =2;
	while(i<number){
		if(number%i==0){
			break;
		}
		i++;
	}

	if(i==number){

		cout << "number is prime";
	}
	return 0;
}

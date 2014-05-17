#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> buyAndSellDate(int[], int);
int main() {

	//array which holds the stock price
	int stockPrice[100];

	//add values in the stock price array
	stockPrice[0] = 23;
	stockPrice[1] = 3;
	stockPrice[2] = 30;
	stockPrice[3] = 30;
	stockPrice[4] = 20;
	stockPrice[5] = 21;
	stockPrice[6] = 24;
	stockPrice[7] = 78;
	stockPrice[8] = 6;
	stockPrice[9] = 10;
	stockPrice[10] = 29;

	map<string, int> result;
	result = buyAndSellDate(stockPrice, 11);

	cout<<"BuyDate: "<<result["buyDate"]<<endl;
	cout<<"SellDate: "<<result["sellDate"]<<endl;



	return 0;
}

map<string, int> buyAndSellDate(int arr[], int size) {

	map<string, int> res;
	int maxProfite = 0, tempProfite, buyDate, sellDate;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			tempProfite = arr[j]-arr[i];
			if (tempProfite > maxProfite) {
				maxProfite = tempProfite;
				buyDate = i;
				sellDate = j;
			}

		}
	}

	res["buyDate"] = buyDate;
	res["sellDate"] = sellDate;
	return res;

}

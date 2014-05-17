/*
 *      multiplication.cpp
 *      Created on: 22-Apr-2014
 *      Author: Gyaneshwar Pardhi
 */

#include<iostream>
using namespace std;

float multiplication(float x, float y) {

	//base condition of recursion
	if (y == 0)
		return 0;

	//call function recursively
	if (y > 0)
		return x + multiplication(x, y - 1);

	//if y is negative number
	if (y < 0)
		return -multiplication(x, -y);
}

int main() {
	float x, y, result;

	//get the inputs from users
	cout << "enter two numbers for multiplication";
	cin >> x >> y;

	result = multiplication(x, y);

	//and here is result
	cout << result;
	return 0;
}

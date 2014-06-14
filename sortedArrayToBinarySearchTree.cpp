#include<iostream>
using namespace std;

//tree node
class treeNode {
public:
	int val;
	treeNode *leftChild;
	treeNode *rightChild;
	treeNode(int value) {
		val = value;
		leftChild = NULL;
		rightChild = NULL;
	}
};

//function protoTypes
treeNode* sortedArrayToBinrySearchTree(int a[], int left, int right);

void inOrderTraversal(treeNode * treeNode);

int main() {

	//sorted array
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	//BST
	treeNode * T2 = sortedArrayToBinrySearchTree(arr, 0, 10);

	//print In Order of tree :: will be same as given array
	inOrderTraversal(T2);

	return 0;
}

//function to construct sorted array to BST
treeNode* sortedArrayToBinrySearchTree(int a[], int left, int right) {

	int mid;
	if (left > right)
		return NULL;

	mid = (left + right) / 2;
	treeNode *temp = new treeNode(a[mid]);
	temp->leftChild = sortedArrayToBinrySearchTree(a, left, mid - 1);
	temp->rightChild = sortedArrayToBinrySearchTree(a, mid + 1, right);

	return temp;
}

//function to print BST in InOrder
void inOrderTraversal(treeNode * Elem) {
	if (Elem) {
		inOrderTraversal(Elem->leftChild);
		cout << Elem->val << endl;
		inOrderTraversal(Elem->rightChild);
	}
}

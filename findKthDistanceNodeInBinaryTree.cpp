#include<iostream>
using namespace std;

class Node
{
public:

	Node *leftChild;
	Node *rightChild;
	Node *parent;
	int value;
	int visited;

	Node(int val) {
		this->value = val;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
		this->visited=0;
	}
	~Node();

};

class bTree
{
public:
	Node *root;
	bTree(Node * root) {
		this->root = root;
	}
	~bTree();
};

void printKthDistanceNode(Node *root, int k) {

    //lets mark root at visited
    root->visited=1;

	if (root == NULL && k > 0) {  //for leaf node
		// return 0;
	}
	else if (root != NULL && k == 0) {  //got the element
		cout << root->value <<"-->";
		// return 1;
	} 

	else { //intermediat node still need to find the elements
		if (root->leftChild && root->leftChild->visited==0){
			printKthDistanceNode(root->leftChild, k - 1);
		}

		if (root->rightChild && root->rightChild->visited==0){
			printKthDistanceNode(root->rightChild, k - 1);
		}

		if (root->parent && root->parent->visited==0){
			printKthDistanceNode(root->parent, k - 1);
		}
	}
}


int main() {

	Node *newNode = new Node(4);

	newNode->leftChild = new Node(5);
	newNode->leftChild->parent = newNode;

	newNode->rightChild = new Node(6);
	newNode->rightChild->parent = newNode;

	newNode->leftChild->leftChild = new Node(8);
	newNode->leftChild->leftChild->parent = newNode->leftChild;

	newNode->leftChild->rightChild = new Node(9);
	newNode->leftChild->rightChild->parent = newNode->leftChild;

	newNode->rightChild->leftChild = new Node(18);
	newNode->rightChild->leftChild->parent = newNode->rightChild;

	newNode->rightChild->rightChild = new Node(19);
	newNode->rightChild->rightChild->parent = newNode->rightChild;

	// cout<<newNode->rightChild->parent->value;

	printKthDistanceNode(newNode->rightChild->rightChild, 2);

	// bTree * b = new bTree(newNode);

	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//	tao ra 1 node
Node* createNode(int data){
//	cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//	chen 1 nut vao cai cay
Node* insertNode(Node* node, int data){
	if(node == NULL){
		 return createNode(data);
	}
	if(data < node->data ){
		node->left = insertNode(node->left, data);
	} else if(data > node->data){
		node->right = insertNode(node->right,data);
	}
	return node;
}

// Dem so luong nut la (leaf nodes) trong cay
int countLeaves(Node* node) {
    if (node == NULL) {
        return 0;                           // Neu cay rong, so nut la la 0
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;                           // Neu la nut la, tra ve 1
    }
    // Tong so nut la cua cay con trai va cay con phai
    return countLeaves(node->left) + countLeaves(node->right);
}

int main(){
	Node* tree = NULL;
	tree = insertNode(tree,4);
	tree = insertNode(tree,3);
	tree = insertNode(tree,6);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	printf("So nut la trong cay: %d\n", countLeaves(tree));

	return 0;	
}


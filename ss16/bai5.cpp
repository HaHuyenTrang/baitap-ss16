#include<stdio.h>
#include<stdlib.h>

// Cau truc cua mot node trong cay
typedef struct Node{
	int data;                // Gia tri cua node
	struct Node* left;       // Con tro tro den node con trai
	struct Node* right;      // Con tro tro den node con phai
}Node;

// Tao ra mot node moi
Node* createNode(int data){
	// Cap phat bo nho cho node moi
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;     // Gan gia tri data cho node
	newNode->left = NULL;     // Node moi chua co con trai
	newNode->right = NULL;    // Node moi chua co con phai
	return newNode;           // Tra ve node moi tao
}

// Chen mot node vao cay
Node* insertNode(Node* node, int data){
	// Neu cay rong, tao node moi
	if(node == NULL){
		 return createNode(data);
	}
	// Neu data nho hon, chen vao cay con trai
	if(data < node->data ){
		node->left = insertNode(node->left, data);
	} 
	// Neu data lon hon, chen vao cay con phai
	else if(data > node->data){
		node->right = insertNode(node->right,data);
	}
	return node; // Tra ve node hien tai sau khi chen
}

// Ham tim gia tri lon nhat trong cay
int findMax(Node* node) {
    if (node == NULL) {
        printf("Cay rong, khong co gia tri lon nhat\n");
        return -1; // Gia tri mac dinh neu cay rong
    }
    // Neu cay con phai la NULL, gia tri hien tai la lon nhat
    if (node->right == NULL) {
        return node->data;
    }
    // Goi de quy de tim gia tri lon nhat o cay con phai
    return findMax(node->right);
}

int main(){
	Node* tree = NULL;                      // Khoi tao cay rong
	tree = insertNode(tree,4);              // Chen gia tri 4 vao cay
	tree = insertNode(tree,3);              // Chen gia tri 3 vao cay
	tree = insertNode(tree,6);              // Chen gia tri 6 vao cay
	tree = insertNode(tree,9);              // Chen gia tri 9 vao cay
	tree = insertNode(tree,5);              // Chen gia tri 5 vao cay

	// Tim gia tri lon nhat trong cay
	int max = findMax(tree);
	printf("Gia tri lon nhat trong cay la: %d\n", max);

	return 0;	
}


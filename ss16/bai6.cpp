#include<stdio.h>
#include<stdlib.h>

// Cau truc cua mot node trong cay
typedef struct Node{
	int data;                // Gia tri cua node
	struct Node* left;       // Con tro tro den node con trai
	struct Node* right;      // Con tro tro den node con phai
}Node;

// Ham tao mot node moi
Node* createNode(int data){
	// Cap phat bo nho cho node moi
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;     // Gan gia tri cho node
	newNode->left = NULL;     // Node moi chua co con trai
	newNode->right = NULL;    // Node moi chua co con phai
	return newNode;           // Tra ve node moi tao
}

// Ham chen mot node vao cay nhi phan
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
		node->right = insertNode(node->right, data);
	}
	return node; // Tra ve node hien tai sau khi chen
}

// Ham dem so nut co gia tri lon hon X
int countNodesGreaterThanX(Node* node, int X) {
	if (node == NULL) {
		return 0; // Neu cay rong, tra ve 0
	}
	// Dem so nut lon hon X trong cay con trai, cay con phai
	int countLeft = countNodesGreaterThanX(node->left, X);
	int countRight = countNodesGreaterThanX(node->right, X);
	
	// Neu gia tri cua node lon hon X, cong 1 vao ket qua
	if (node->data > X) {
		return countLeft + countRight + 1;
	} else {
		return countLeft + countRight;
	}
}

int main(){
	Node* tree = NULL;                      // Khoi tao cay rong
	tree = insertNode(tree,4);              // Chen gia tri 4 vao cay
	tree = insertNode(tree,3);              // Chen gia tri 3 vao cay
	tree = insertNode(tree,6);              // Chen gia tri 6 vao cay
	tree = insertNode(tree,2);              // Chen gia tri 2 vao cay
	tree = insertNode(tree,5);              // Chen gia tri 5 vao cay

	int X;                                  // Bien de luu gia tri nguoi dung nhap
	printf("Nhap gia tri X: ");
	scanf("%d", &X);                        // Nhan gia tri X tu nguoi dung

	// Tinh so nut co gia tri lon hon X
	int count = countNodesGreaterThanX(tree, X);
	printf("So nut co gia tri lon hon %d la: %d\n", X, count);

	return 0;	
}


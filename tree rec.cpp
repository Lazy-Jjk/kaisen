#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *create(int val ) {
	struct Node *n=(struct Node *)malloc(sizeof(struct Node));
	n->data=val;
	n->left=NULL;
	n->right=NULL;
	return n;
}
struct Node *insert(struct Node *root,int data) {
	if(root==NULL) {
		return create(data);
	}
	if(data<root->data ){
		root->left=insert(root->left,data);
	}
	else if(data>root->data ){
		root->right=insert(root->right,data);
	}
	return root;
}
struct Node*search(struct Node *root,int key) {
	if(root==NULL || root->data==key ) {
		return root;
	}
	if(key<root->data) {
		return search(root->left,key);
		if(key==root->data) {
			printf("found : ");
		}
	}
	else{
		return search(root->right,key);
		if(key==root->data) {
			printf("found : ");
		}
	}	
}
void preorder(struct Node *root) {
	if(root!=NULL){
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);	
	}	
}
void inorder(struct Node *root) {
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}	
}
void postorder(struct Node *root) {
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}	
}
int main () {
	int choice ,value;
	struct Node *root=NULL;
	while(1) {
		printf("1.insert\n");
		printf("2.preorder\n");
		printf("3.inorder\n");
		printf("4.postorder\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("Enter value : ");
				scanf("%d",&value);
				root=insert(root,value);
				break;
			case 2:
				preorder(root);
				printf("\n");
				break;
			case 3:
				inorder(root);
				printf("\n");
				break;
			case 4:
				postorder(root);
				printf("\n");
				break;
		}
	}
}

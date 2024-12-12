#include<stdio.h>
#include<stdlib.h>
struct Node *f=NULL;
struct Node *r;
struct Node {
	int data;
	struct Node*next;
};
void traversal(struct Node *ptr) {
	while(ptr!=NULL) {
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int enqueue(int data) {
	struct Node *n=(struct Node *)malloc(sizeof(struct Node));
	//struct Node *ptr=head;
	if(n==NULL) {
		printf("Queue is full : ");
	}
	else{
		n->data=data;
		n->next=NULL;
		if(f==NULL) {
			f=r=n;
		}
		else{
			r->next=n;
			r=n;
			return n->data;
		}
	}
}
int dequeue(){
	if(f==NULL) {
		printf("queue is empty: ");
	}
	else{
		struct Node *q=f;
		f=f->next;
		free(q);
		return f->data;
	}
}
int peek() {
	printf("%d",f->data);
	printf("\n");
	
}

int main() {
	struct Node *head=NULL;
	int val,choice;
	while(1){
		printf("1.enqueue: \n");
		printf("2. dequeue\n ");
		printf("3.traversal\n");
		printf("4. peek \n");
		printf("5.exit \n");
		
		
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				printf("Enter value : ");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				val=dequeue();
				if(val!=1) {
					printf("%d",val);
				}
				break;
			case 3:
				traversal(f);
				break;
			case 4:
				peek();
				break;
			case 5:
				exit(0);
				break;
				
		}
	}
}

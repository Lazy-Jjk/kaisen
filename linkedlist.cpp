#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
void traversal(struct Node *ptr) {
	while(ptr!=NULL) {
		printf(" %d\t",ptr->data);
		ptr=ptr->next;
		
	}
	printf("\n");
}
struct Node *insertatbegining(struct Node *head,int data) {
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node ));
	ptr->data=data;
	ptr->next=head;
	head=ptr;
	return head;
}
struct Node *insertatend(struct Node *head,int data) {
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node ));
	struct Node *q=head;
	ptr->data=data;
	while(q->next!=NULL) {
		q=q->next;
	}
	q->next=ptr;
	ptr->next=NULL;
	return head;
	

}
struct Node * insertatindex(struct Node *head,int data,int index ) {
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i=0;
    while (i!=index-1) {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node *deleteatbeg(struct Node *head) {
	struct Node *p=head;
	head=head->next;
	free(p);
	return head;

}
struct Node *deleteatend(struct Node *head) {
	struct Node *ptr=head;
	struct Node *q=head->next;
	while(q->next!=NULL) {
		q=q->next;
		ptr=ptr->next;
		
		
	}
	ptr->next=NULL;
	free(q);
	return head;
}
struct Node *deleteatindex(struct Node *head,int index) {
	int i;
	struct Node*p=head;
	struct Node*q=head->next;
	for(i=0;i<index-1;i++) {
		q=q->next;
		p=p->next;
	}
	p->next=q->next;
	free(q);
	return head;
	
}

int main() {
	struct Node*head=NULL;
	
	int i,value,choice;
	while(1) {
		printf("1.insertAtBegining\n");
		printf("2.insertAtEnd\n");
		printf("3.deleteAtBegin\n");
		printf("4.deleteAtIndex\n");
		printf("5.deleteAtEnd\n");
		printf("6.Traversal\n");
		printf("7.Exit\n");
		printf("8.insertatindex\n");
		
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("Enter value to insert : ");
				scanf("%d",&value);
				head=insertatbegining(head,value);
				break;
			case 2:
				printf("Enter value to insert : ");
				scanf("%d",&value);
				head=insertatend(head,value);
				break;
			case 3:
				head=deleteatbeg(head);
				break;
			case 4:
				printf("Enter position to delete : ");
				scanf("%d",&value);
				
				head=deleteatindex(head,value);
				break;
			case 5:
				head=deleteatend(head);
				break;
			case 6:
				traversal(head);
				break;
			case 7:
				exit(0);
				break;
			case 8:
				int pos;
				printf("Enter value to insert : ");
				scanf("%d",&value);
				printf("Enter position to insert : ");
				scanf("%d",&pos);
				head=insertatindex(head,value,pos);
				break;
				
		}
		
	}
}
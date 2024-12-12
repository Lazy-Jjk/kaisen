#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	
}
void heapify(int a[],int n,int i) {	
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]>a[largest]) {
		largest=left;
	}
	if(right<n && a[right]>a[largest]) {
		largest=right;
	}
	if(largest!=i) {
		swap(&a[i],&a[largest]);
		heapify(a,n,largest);
	}
}
void heapsort(int a[],int n) {
	int i;
	for(i=n/2-1;i>=0;i--) {
		heapify(a,n,i);
	}
	
	for(i=n-1;i>=0;i--) {
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
	
}

void traversal(int a[],int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d\t",a[i]);
	}
	printf("\n");
}


int main() {
	int n,i;
	printf("number of elements : ");
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int));
	printf("Enter elements : \n");
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	traversal(a,n);
	printf("After sorting : \n");
	heapsort(a,n);
	traversal(a,n);
}

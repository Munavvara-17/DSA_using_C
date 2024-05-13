#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node* front=NULL,*rear=NULL;
void enqueue(int x){
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=front;
	if(front==NULL && rear==NULL){
		front=t;
		rear=t;
		rear->next=front;
	}
	else
	{
		rear->next=t;
		rear=t;
		rear->next=front;
	}
	printf("%d inserted\n",x);
}

void dequeue(){
	struct node *t;
	int n;
	if(front==NULL)
		printf("linked list is empty");
	else{
		t=front;
		n=t->data;
		front=front->next;
		rear->next=front;
		free(t);
		printf("%d element removed\n",n);
	}
}

void traverse(){
	struct node *t;
	t=front;
	if(t==NULL)
		printf("linked list is empty\n");
	else{
		do
		{
			printf("%d ",t->data);
			t=t->next;
		}
		while(t!=front);
	}
}

int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	traverse();
	dequeue();
	dequeue();
	traverse();
}
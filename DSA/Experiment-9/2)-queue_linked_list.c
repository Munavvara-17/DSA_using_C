#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node* front=NULL,*rear=NULL;
void enqueue(int x)
{
	struct node *t, *temp;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(front==NULL){
		front=t;
		rear=t;
		front->next=NULL;
		rear->next=NULL;
	}
	else
	{
		rear->next=t;
		rear=t;
		rear->next=NULL;
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
		free(t);
		printf("%d element removed\n",n);
	}
}

void traverse()
{
	struct node *t;
	t=front;
	if(t==NULL)
		printf("linked list is empty\n");
	else{
		while(t!=NULL){
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");
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

//output

//10 inserted
//20 inserted
//30 inserted
//40 inserted
//10 20 30 40 
//10 element removed
//20 element removed
//30 40
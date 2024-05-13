#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node* top=NULL;
void push(int x)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(top==NULL)
		top=t;
	else{
		t->next=top;
		top=t;
	}
	printf("%d inserted\n",x);
}
void pop(){
	struct node *t;
	int n;
	if(top==NULL)
		printf("linked list is empty");
	else{
		n=top->data;
		t=top->next;
		free(top);
		top=t;
		printf("%d popped from stack\n",n);

	}
}
void traverse()
{
	struct node *t;
	t=top;
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
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	traverse();
	pop();
	pop();
	traverse();
	push(90);
	traverse();
}


//output

//10 inserted
//20 inserted
//30 inserted
//40 inserted
//40 30 20 10 
//40 popped from stack
//30 popped from stack
//20 10 
//90 inserted
//90 20 10
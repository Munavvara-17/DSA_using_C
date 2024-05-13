#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node* next;
};
struct node *start=NULL;
void insert_at_beg(int x){
	struct node *t,*temp;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(start==NULL){
		start=t;
		t->next=start;
	}
	else{
		t->next=start;
		temp=start;
		while(temp->next!=start)
			temp=temp->next;
		temp->next=t;
		start=t;
	}
}
void insert_at_end(int x){
	struct node *t, *temp;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=start;
	if(start==NULL)
		start=t;
	else{
		temp=start;
		while(temp->next!=start)
			temp=temp->next;
		temp->next=t;
	}
}
void traverse(){
	struct node *t;
	t=start;
	if(t==NULL)
		printf("linked list is empty\n");
	else{
		while(t->next!=start){
			printf("%d ",t->data);
			t=t->next;
		}
		printf("%d\n",t->data);
	}
}
void del_beg(){
	struct node *t,*temp;
	int n;
	if(start==NULL)
		printf("linked list is empty\n");
	else{
		n=start->data;
		t=start->next;
		temp=start;
		while(temp->next!=start){
			temp=temp->next;
		}
		temp->next=t;
		free(start);
		start=t;
		printf("%d deleted from beginning sucessfully\n",n);
	}
}
void del_end(){
	struct node *t,*u;
	int n;
	if(start==NULL){
		printf("linked list is empty\n");
		return;
	}
	else{
		if(start->next==start){
			n=start->data;
			free(start);
			start=NULL;
			printf("%d deleted from end successfully\n",n);
			return;
		}
		t=start;
		while(t->next!=start){
			u=t;
			t=t->next;
		}
		n=t->data;
		u->next=start;
		free(t);
		printf("%d deleted from end successfully \n",n);
	}
}
void search(int x){
	int c=1;
	int flag=0;
	struct node *t=start;
	if(t==NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	do{
		if(t->data==x){
			flag=1;
			break;
		}
		c++;
		t=t->next;
		
	}
	while(t!=start);
	if(flag==0)
		printf("element does not exist\n");
	else
		printf("element found at position %d\n",c);
}
int main(){
	int n,x;
	printf("Enter\n1:Insert at beginning \n2:Insert at End\n3:Traverse \n4:Deletion at beginning\n5:Deletion at end\n6:Searching\n7:Exit\n");
	do{
		printf("Enter option:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				insert_at_beg(x);
				break;
			case 2:
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				insert_at_end(x);
				break;
			case 3:
				traverse();
				break;
			case 4:
				del_beg();
				break;
			case 5:
				del_end();
				break;
			case 6:
				printf("Enter element to be searched: ");
				scanf("%d",&x);
				search(x);
				break;
			case 7:
				break;
			default:
				printf("invalid option\n");
				break;	
		}
	}
	while(n!=7);
	return 0;
}
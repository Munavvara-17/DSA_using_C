#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node *start=NULL;
void insert_beg(int x)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	t->prev=NULL;
	if(start==NULL)
		start=t;
	else{
		t->next=start;
		start->prev=t;
		start=t;
	}
}
void insert_end(int x)
{
	struct node *t, *temp;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	t->prev=NULL;
	if(start==NULL)
		start=t;
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		t->prev=temp;
		temp->next=t;
		
	}
}
void insert_after(int x,int p)
{
	struct node *t,*temp;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=p;
	t->next=NULL;
	t->prev=NULL;
	temp=start;
	if(start==NULL)
		printf("No Insertion performed\n");
	else{
		while(temp->data!=x)
		{
			temp=temp->next;
		}
		t->next=temp->next;
		t->prev=temp;
		temp->next=t;
	}
}
void insert_before(int x,int p)
{
	struct node *t, *temp,*u;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	t->prev=NULL;
	int flag=0;
	if(start==NULL)
		printf("No Insertion performed\n");
	else
	{
		temp=start;
		while(temp->data!=p){
			u=temp;
			temp=temp->next;
		}
		t->next=temp;
		temp->prev=t;
		if(temp==start){
			start=t;
		}
		else{
			t->prev=u;
			u->next=t;
		}
	}
}
void insert_at_node(int x,int p)
{
	struct node *t, *temp,*u;
	t=(struct node*)malloc(sizeof(struct node));
	int counter=1;
	t->data=x;
	t->next=NULL;
	t->prev=NULL;
	if(start==NULL)
		start=t;
	else
	{
		temp=start;
		while(temp!=NULL){
			if(counter==p)
			{
				t->next=temp;
				temp->prev=t;
				break;
			}
			u=temp;
			temp=temp->next;
			counter++;
		}	
		if(temp==start){
			start=t;
		}
		else if(p<=counter+1)
		{
			t->prev=u;
			u->next=t;
		}
		else
			printf("Insertion not performed\n");
	}
}
void traverse()
{
	struct node *t;
	t=start;
	if(t==NULL)
		printf("linked list is empty\n");
	else
	{
		while(t->next!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("%d ",t->data);
		printf("\n");
	}
}
void del_beg()
{
	struct node *t;
	int n;
	if(start==NULL)
		printf("linked list is empty");
	else{
		n=start->data;
		t=start->next;
		if(t!=NULL)
			t->prev=NULL;
		free(start);
		start=t;
		
		printf("%d deleted from beginning sucessfully\n",n);
	}
}
void del_end()
{
	struct node *t,*u;
	int n;
	if(start==NULL){
		printf("linked list is empty");
		return;
	}
	else
	{
		if(start->next==NULL)
		{
			n=start->data;
			free(start);
			start=NULL;
			printf("%d deleted from end successfully\n",n);
		}
		t=start;
		while(t->next!=NULL){
			u=t;
			t=t->next;
		}
		n=t->data;
		u->next=NULL;
		free(t);
		printf("%d deleted from end successfully \n",n);
	}
}
//void del_node(int x)
//{
//	struct node *t,*temp;
//	int n;
//	temp=start;
//	if(start==NULL)
//		printf("linked list is empty");
//	else{
//		while(temp->data!=x){
//			t=temp;
//			temp=temp->next;
//		}
//		n=temp->data;
//		if(temp==start)
//		{
//			start=temp->next;
//			start->prev=NULL;
//		}
//		else
//		{
//			t->next=temp->next;
//			temp->next->prev=t;
//		}
//		free(temp);
//		printf("%d deleted sucessfully\n",n);
//	}
//}
//void del_after(int x)
//{
//	struct node *t,*temp;
//	int n,flag=0;
//	temp=start;
//	if(start==NULL)
//		printf("linked list is empty");
//	else{
//		while(temp->next!=NULL){
//			if(temp->data==x)
//			{
//				t=temp->next;
//				temp->next=t->next;
//				t->next->prev=temp;
//				n=t->data;
//				free(t);
//				flag=1;
//			}
//			temp=temp->next;
//		}
//		if(flag==1)
//			printf("%d deleted sucessfully\n",n);
//		else 
//			printf("element doesn't exist after specific node\n");
//
//	}
//}
//void del_before(int p)
//{
//	struct node *temp,*u;
//	int n;
//	temp=start;
//	if(start==NULL)
//		printf("linked list is empty\n");
//	else if(temp->data==p)
//	{
//		printf("Element doesn't exist before it\n");
//	}
//	else{
//		while(temp->next->data!=p){
//			u=temp;
//			temp=temp->next;
//		}
//		if(temp==start) 
//		{
//			start=temp->next;
//			start->prev=NULL;
//		}
//		else
//		{
//			u->next=temp->next;
//			temp->next->prev=u;
//		}
//		n=temp->data;
//		free(temp);
//		printf("%d deleted sucessfully\n",n);
//	}
//}
void search(int x)
{
	int counter=1;
	int flag=0;
	struct node *t=start;
	if(t==NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	while(t!=NULL)
	{
		if(t->data==x)
		{
			flag=1;
			break;
		}
		counter++;
		t=t->next;
		
	}
	if(flag==0)
		printf("element does not exist\n");
	else
		printf("element found at position %d\n",counter);
}
int main()
{
	int n,x,p;
	printf("1:Insert at beginning \n2:Insert at End\n3:Insert after node \n4:Insert before node \n5:Insert at node \n6:Traverse \n7:Deletion from beginning \n8:Deletion at end \n9:Delete specific node \n10:Delete after node \n11:Delete before node \n12:Search \n13:Exit\n");
	do
	{
		printf("Enter option:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				insert_beg(x);
				break;
			case 2:
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				insert_end(x);
				break;
			case 3:
				printf("After which element is to be inserted: ");
				scanf("%d",&x);
				printf("Enter element to be inserted: ");
				scanf("%d",&p);
				insert_after(x,p);
				break;
			case 4:
				printf("Before which element is to be inserted: ");
				scanf("%d",&p);
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				insert_before(x,p);
				break;
			case 5:
				printf("At which position element is to be inserted: ");
				scanf("%d",&p);
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				insert_at_node(x,p);
				break;
			case 6:
				traverse();
				break;
			case 7:
				del_beg();
				break;
			case 8:
				del_end();
				break;
//			case 9:
//				printf("which element is to be deleted: ");
//				scanf("%d",&p);
//				del_node(p);
//				break;
//			case 10:
//				printf("after which element the node is to be deleted: ");
//				scanf("%d",&p);
//				del_after(p);
//				break;
//			case 11:
//				printf("before which element the node is to be deleted: ");
//				scanf("%d",&p);
//				del_before(p);
//				break;
			case 9:
				printf("Enter element to be searched: ");
				scanf("%d",&x);
				search(x);
				break;
			case 10:
				break;
			default:
				printf("invalid option\n");
				break;	
		}
	}
	while(n!=10);
	return 0;
}
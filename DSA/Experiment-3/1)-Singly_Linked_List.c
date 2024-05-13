#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
int count=0;
struct node *start=NULL;
void insert_at_beg(int x)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	count++;
	t->data=x;
	t->next=NULL;
	if(start==NULL)
		start=t;
	else{
		t->next=start;
		start=t;
	}
}
void insert_at_end(int x)
{
	struct node *t, *temp;
	t=(struct node*)malloc(sizeof(struct node));
	count++;
	t->data=x;
	t->next=NULL;
	if(start==NULL)
		start=t;
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=t;
	}
}
void insert_after(int x,int s)
{
	struct node *t,*temp,*p;
	t=(struct node*)malloc(sizeof(struct node));
	count++;
	t->data=s;
	t->next=NULL;
	temp=start;
	p=start;
	if(start==NULL)
		start=t;
	else{
		while(temp->data!=x)
		{
			p=temp;
			temp=temp->next;
		}
		t->next=temp->next;
		p->next=t;
	}
}
void insert_before(int x,int p)
{
	struct node *t, *temp,*u;
	t=(struct node*)malloc(sizeof(struct node));
	count++;
	t->data=p;
	t->next=NULL;
	if(start==NULL)
		start=t;
	else
	{
		temp=start;
		while(temp->data!=x){
			u=temp;
			temp=temp->next;
		}	
		t->next=temp;
		if(temp==start){
			start=t;
		}
		else{
			u->next=t;
		}
	}
}
void insert_at_node(int x,int p)
{
	struct node *t, *temp,*u;
	t=(struct node*)malloc(sizeof(struct node));
	count++;
	t->data=x;
	int counter=1;
	t->next=NULL;
	if(start==NULL)
		start=t;
	else
	{
		temp=start;
		while(counter!=p){
			u=temp;
			temp=temp->next;
			counter++;
		}	
		t->next=temp;
		if(temp==start){
			start=t;
		}
		else{
			u->next=t;
		}
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
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");
	}
	
}
void delete_from_beg()
{
	struct node *t;
	int n;
	if(start==NULL)
		printf("linked list is empty");
	else{
		n=start->data;
		t=start->next;
		free(start);
		start=t;
		count--;
		printf("%d deleted from beginning sucessfully\n",n);

	}
}
void delete_from_end()
{
	struct node *t,*u;
	int n;
	if(start==NULL){
		printf("linked list is empty");
	}
	else
	{
		count--;
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
void delete_node(int p)
{
	struct node *t,*temp;
	int n;
	temp=start;
	t=start;
	if(start==NULL)
		printf("linked list is empty");
	else{
		while(temp->data!=p){
			t=temp;
			temp=temp->next;
		}
		t->next=temp->next;
		n=temp->data;
		if(temp==start)
		{
			start=temp->next;
		}
		free(temp);
		count--;
		printf("%d deleted sucessfully\n",n);

	}
}
void delete_after(int p)
{
	struct node *t,*temp;
	int n;
	temp=start;
	t=temp->next;
	if(start==NULL)
		printf("linked list is empty");
	else{
		while(temp->data!=p){
			temp=temp->next;
			t=temp->next;
		}
		temp->next=t->next;
		n=t->data;
		free(t);
		count--;
		printf("%d deleted sucessfully\n",n);

	}
}
void delete_before(int p)
{
	struct node *temp,*u;
	int n;
	temp=start;
	if(start==NULL)
		printf("linked list is empty\n");
	else if(temp->data==p)
	{
		printf("Element doesn't exist before it\n");
	}
	else{
		while(temp->next->data!=p){
			u=temp;
			temp=temp->next;
		}
		if(temp==start) 
			start=temp->next;
		else
			u->next=temp->next;
		n=temp->data;
		free(temp);
		count--;
		printf("%d deleted suc1cessfully\n",n);

	}
}
int main()
{
	int p,n,x;
	printf("1:Insert at beginning \n2:Insert at End\n3:Insert After \n4:Insert Before\n5:Insert at specific node \n6:Traverse \n7:Deletion at beginning\n8:Deletion at end\n9:Searching\n10:Deletion at specific node\n11:Deletion after node\n12:Deletion before node\n13:Exit\n");
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
				printf("After which element is to be inserted: ");
				scanf("%d",&x);
				printf("Enter element to be inserted: ");
				scanf("%d",&p);
				insert_after(x,p);
				break;
			case 4:
				printf("before which element is to be inserted: ");
				scanf("%d",&x);
				printf("Enter element to be inserted: ");
				scanf("%d",&p);
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
				delete_from_beg();
				break;
			case 8:
				delete_from_end();
				break;
			case 9:
				printf("Enter element to be searched: ");
				scanf("%d",&x);
				search(x);
				break;
			case 10:
				printf("which element is to be deleted: ");
				scanf("%d",&p);
				delete_node(p);
				break;
			case 11:
				printf("after which element the node is to be deleted: ");
				scanf("%d",&p);
				delete_after(p);
				break;
			case 12:
				printf("before which element the node is to be deleted: ");
				scanf("%d",&p);
				delete_before(p);
				break;
			case 13:
				break;
			default:
				printf("invalid option\n");
				break;
		}
	}
	while(n!=13);
	return 0;
}
#include<stdio.h>

int rear = -1,front = -1,max_size = 5,Q[5],data;

void enqueue_circular(int data){
	if((rear+1)%max_size == front)
		printf("Queue is overflow\n");
		else{
			if(front == -1 && rear == -1){
				front = 0;rear =0;
			}
			else{
				rear = ((rear+1)%max_size);
			}
			Q[rear] = data;
			printf("Insert the elements in the Circular Queue  =  %d at index  =  %d\n",data,rear);
		}
		
}

int dequeue_circular(){
	int item;
	if(front == -1 && rear == -1){
		printf("Queue is underflow\n");
	}
	else{
		if(front == rear){
			item = Q[front];
			front = -1;rear = -1;
		}
		else{
			item = Q[front];
			front = ((front+1)%max_size);
//			return item;
		}
		printf("Deleted elements from the Circular Queue  =  %d \n",item);
	}
}

int traverse_circular(){
	int i;
	if(front == -1 && rear == -1){
		printf("Queue is underflow\n");
	}
	else{
		if(front > rear){
			for(int i=front;i<=max_size;i++){
				printf("%d",Q[i]);
				for(int i=0;i<rear;i++){
					printf("%d",Q[i]);
				}
			}
		}
		else{
			printf("Traverse elements in the circular Queue  =  ");
			for(int i=front;i<=rear;i++){
				printf("%d ",Q[i]);
			}
			printf("\n");
		}
	}
//	return Q[i];
}

int main(){
	enqueue_circular(10);
	enqueue_circular(20);
	enqueue_circular(30);
	enqueue_circular(40);
	enqueue_circular(50);
	enqueue_circular(60);
	traverse_circular();
	dequeue_circular();
	dequeue_circular();
	dequeue_circular();
	traverse_circular();
	dequeue_circular();
	dequeue_circular();
	traverse_circular();
	enqueue_circular(70);
	enqueue_circular(80);
	traverse_circular();
}
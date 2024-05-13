#include<stdio.h>
#include<stdbool.h>

bool overflow(int rear,int max_size){
	if(rear == max_size - 1){
		return true;
	}
	else{
		return false;
	}
}

bool underflow(int front,int rear){
	if((front == -1) && (rear == -1)){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(int front,int rear,int q[],int data,int max_size){
	if (overflow(rear,max_size)){
		printf("Queue is Empty\n");
	}
	else{
		if(front == rear ==-1){
			front = 0;
			rear = 0;
		}
		else{
			rear = rear+1;
		}
	}
	q[rear] = data;
}

int dequeue(int front,int rear,int q[],int max_size){
	int data;
	if(underflow(rear,front)){
		printf("Queue is underflow\n");
	}
	else{
		if(front == rear){
			data = q[front];
			front = -1;
			rear = -1;
		}
		else{
			data = q[front];
			front = front + 1;
		}
		return data;
	}
}


int main(){
	int front=-1,rear=-1,data,q[4],max_size = 4;
	int x;
	while(true){
		printf("press 1 To enqueue\n");
		printf("press 2 To dequeue\n");
		printf("press 3 To EXIT");
		scanf("%d",&x);
		if(x == 1){
			printf("Enter the DATA :");
			scanf("%d",&data);
			enqueue(front,rear,q,data,max_size);
			rear = rear + 1;
		}
		else if(x == 2){
			int a = dequeue(front,rear,q,max_size);
			printf("Element deleted is: %d \n",a);
			front = front + 1;
		}
		else if(x == 3){
			printf("Nothing is there");
			break;
		}
	}
	for(int i=0;i<=max_size;i++){
		printf("element presented is in an linear queue :",data);
	}
}
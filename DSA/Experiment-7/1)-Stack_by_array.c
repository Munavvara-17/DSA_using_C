#include<stdio.h>
#include<stdbool.h>
int max_size=5,s[5],item,top=-1,data;
//stack is in underflow condition nothing is in the stack
bool underflow(){
	if(top<=-1)
		return true;
	else
		return false;
}

//stack is in overflow condition means that satck is full
bool overflow(){
	if (top >= max_size-1)
		return true;
	else
		return false;
}

//insert a elements onto the stack by using push function
void push(int data){
	if(overflow()){
		printf("Stack is overflow\n");
	}
	else{
		top = top+1;
		s[top] = data;
	}
	printf("element inserted  =  %d \n",data);
}

//delete a elements from the stack by using pop function
int pop(){
	if(underflow()){
		printf("Stack is underflow\n");
	}
	else{
		int data = s[top];
		top = top-1;
		printf("deleted element  =  %d \n",data);		
	}
}

//to access the last element in the stack by using traverse function7
void traverse(){
	if(underflow()){
		printf("stack is underflow\n");
	}
	else{
		for(int i=top;i>=0;i--){
			printf("Traverse the element is on the stack  =  %d  ",s[i]);
		}
//	printf("\n");
	}
}

//search a elements in the stack by using a search function
void search(int item){
	if(underflow()){
		printf("Stack is underflow\n");
	}
	else{
		for(int i=top;i>=0;i--){
			if(s[i] == item){
				printf("Elements tend at location  =  %d \n",i);
				printf("Elements is  =  %d \n",s[i]);
				return;
//				break;
			}
		}
	}
	printf("Given data is not found in the stack  =  %d\n",item);
}
	
//to display a current element on the top of the stack by using peek function
void peek(){
	printf("display the top most elements on the stack  =  %d\n", s[top]);
}

//for count the total no. of elements in the stack by using count function
void count(){
	printf("Number of total elements in stack  =  %d\n", top+1);
}

int main(){
//	int max_size=5,s[5],item,top=-1,data;
	push(10);
 	push(20);
 	push(30);
 	search(20);
 	search(40);
 	pop();
 	traverse();
 	pop();
 	peek();
 	count();
	
	return 0;
//	""item"" is used for searching a element
//data is used for inserting or deleting elements in stack
}
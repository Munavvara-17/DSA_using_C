#include<stdio.h>
//Insertion sort
void Insertion_Sort(int n,int *arr)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		while((j>=0) && (arr[j]>key)){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}
int main(){
	int n=7,i,j,arr[7],key;
	printf("Enter the elements in Array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	Insertion_Sort(n,arr);
	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#include<stdio.h>
//bubble
void Bubble_Sort(int n,int *arr)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(){
	int n=7,i,j,arr[7],temp;
	printf("Enter the elements in Array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	Bubble_Sort(n,arr);
	printf("Sorted Array :\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n", arr[i]);
	}
	return 0;
}
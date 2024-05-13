#include<stdio.h>
//Selection Sort
void Selection_Sort(int n,int *arr)
{
	int i,j,smallest,temp;
	for(i=0;i<n-1;i++)
	{
		smallest = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j] < arr[smallest])
			{
				smallest = j; 
			}
    	}
		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
   }
}
int main(){
	int n=7,i,j,arr[7],temp,smallest;
	printf("Enter the elements in Array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	Selection_Sort(n,arr);
	printf("Sorted Array\n");
	for(i=0;i<n;i++)
	{
		printf("%d \n", arr[i]);
	}
	return 0;
}
#include<stdio.h>
//bubble
void Counting_Sort(int n,int *arr)
{
	int i,j,k;
	for(i=0;i<=k;i++)
		int c[i] = 0;
	for(j=0;j<=n-1;j++)
		int c[arr[j]] = c[arr[j]]+1;
	for(i=1;i<=k;i++)
		int c[i] = c[i] + c[i-1];
	for(j=n-1;j<=0;j--)
		int c[arr[j]] = c[arr[j]]-1;
		int b[c[arr[j]]] = arr[j];
}
int main(){
	int n=7,arr[7],i;
	printf("Enter the elements in Array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	Counting_Sort(n,arr);
	printf("Sorted array:  ");
	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
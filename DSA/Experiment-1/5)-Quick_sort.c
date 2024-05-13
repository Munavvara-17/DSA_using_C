#include<stdio.h>

void Quick_sort(int arr[],int low,int high){
	if(low<high){
		int pi = partition(arr,low,high);
		Quick_sort(arr,low,pi-1);
		Quick_sort(arr,pi+1,high);
	}
}

int partition(int *arr,int low,int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j = low;j<=(high-1);j++){
		if(arr[j] < pivot){
			i = i+1;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return(i+1);
}

int main() {
    int i, arr[7], n = 7,low=0,high=n-1;

    printf("Enter the elements in array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Quick_sort(arr,low,high);

    printf("Sorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
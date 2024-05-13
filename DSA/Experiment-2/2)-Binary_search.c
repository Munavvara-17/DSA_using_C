//#include<stdio.h>
////Binary search
//
//int main(){
//	int n = 7,arr[7],i,Item = 2,mid,lower_bound = 0,upper_bound = n-1;
//	printf("Enter the elements in sorted order :");
//	for(int i=0;i<=n;i++){
//		scanf("%d",&arr[i]);
//	}	
////	int arr[7] = {1,2,4,5,6,7,8};
////	mid = (upper_bound + lower_bound)/2;
//
//	for(i=0;i<=n;i++){
//		mid = (upper_bound + lower_bound)/2;
//		if(arr[mid] == Item){
//			break;
//		}
//		else if(mid > Item){
//			upper_bound = mid - 1;
//		}
//		else{
//			lower_bound = mid + 1;
//		}
////		mid = (lower_bound + upper_bound) / 2;
//	}
//	if(lower_bound <= upper_bound){
//			printf("Element found at %d",mid);
//		}
//		else{
//		printf("Not Found");
//    	}
//	}


#include <stdio.h>

// Binary search
int main() {
    int n, Item, mid, lower_bound, upper_bound;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements from the user (assuming the array is sorted)
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the item to be searched: ");
    scanf("%d", &Item);

    // Binary search algorithm
    lower_bound = 0;
    upper_bound = n - 1;

    while (lower_bound <= upper_bound) {
        mid = (lower_bound + upper_bound) / 2;

        if (arr[mid] == Item) {
            printf("Element found at index %d\n", mid);
            break;
        } else if (arr[mid] > Item) {
            upper_bound = mid - 1;
        } else {
            lower_bound = mid + 1;
        }
    }

    if (lower_bound > upper_bound) {
        printf("Element not found\n");
    }

    return 0;
}

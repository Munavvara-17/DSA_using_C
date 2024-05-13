//#include<stdio.h>
////searching
//int main(){
//	int n = 6,Item = 4,LOC = 0;
//	int arr[6] = {1,6,4,7,8,3};
//	for(int i = 0;i<n;i++){	
//		if(arr[i] == Item){
//			LOC = i;
//			printf("Item found at index %d and item %d ",i,arr[i]);
//		}
//		else{
//			i = i+1;
//		}
//	}
//	if(LOC == 0){
//		printf("Search is UNSUCCESSFUL");
//	}
//	else{
//		printf("Search is SUCCESSFUL");
//	}
//}
#include <stdio.h>

// Searching
int main() {
    int n, LOC = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements from the user
    printf("Enter %d elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int Item;

    printf("Enter the item to be searched: ");
    scanf("%d", &Item);

    // Loop through the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == Item) {
            LOC = i;
            printf("Item found at index %d\n", LOC);
            break;  // Exit the loop once the item is found
        }
    }

    if (LOC == 0) {
        printf("Search is UNSUCCESSFUL\n");
    } else {
        printf("Search is SUCCESSFUL\n");
    }

    return 0;
}

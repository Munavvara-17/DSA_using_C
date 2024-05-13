//#include<stdio.h>
//
//void Merge_Sort(arr,p,q){
//	int r,n1,n2,i,j;
//	if(p<r){
//		q = (p+r)/2;
//		Merge_Sort(arr,p,q);
//		Merge_Sort(arr,q+1,r);
//		Merge_Sort(arr,p,q,r);
//	}
//Merge_Sort(arr,p,q,r);
//{
//	n1 = q-p+1;
//	n2 = r-q;
//	for(i=1;i<n1;i++){
//		l[i] = arr[p+i-1];	
//	}
//	for(j=1;j<n1;j++){
//		r[j]=arr[q+j];
//	}
//	i = 1;
//	j = 1;
//	for(k=p;k<r;k++){
//		if(l[i]<=r[j]){
//			arr[k] = l[i];
//			i = i+1;
//		}
//		else{
//			a[k] = r[j];
//			j = j+1;
//		}
//	}
//}
//}
//int main(){
//	int i,j,k,l,arr[7],n1,n2,n=7,p,q,r;
//	printf("Enter the elements in array :");
//	for(i=0;i<n;i++){
//		scanf("%d",&n);
//	}
//	Merge_Sort(arr,p,q,r);
//}
//
//
//void mergeSort(int arr[], int p, int r) {
//    if (p < r) {
//        int q = (p + r) / 2;
//        mergeSort(arr, p, q);
//        mergeSort(arr, q + 1, r);
//        merge(arr, p, q, r);
//    }
//}

#include <stdio.h>

void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];  // Declare temporary arrays L[] and R[]

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//void mergeSort(int arr[], int p, int r) {
//    if (p < r) {
//        int q = (p + r) / 2;
//        mergeSort(arr, p, q);
//        mergeSort(arr, q + 1, r);
//        merge(arr, p, q, r);
//    }
//}

int main() {
    int i, arr[7], n = 7;

    printf("Enter the elements in array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
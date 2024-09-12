#include <stdio.h> 
#include <stdlib.h>
void merge(int arr[], int left, int mid, int right) { 
int n1 = mid - left + 1; 
int n2 = right - mid; 
int* L = (int*)malloc(n1 * sizeof(int)); 
int* R = (int*)malloc(n2 * sizeof(int)); 
    for (int i = 0; i < n1; i++) { 
        L[i] = arr[left + i]; 
    } 
    for (int j = 0; j < n2; j++) { 
        R[j] = arr[mid + 1 + j]; 
    } 
 
    int i = 0; 
    int j = 0; 
    int k = left;
 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k++] = L[i++]; 
        } else { 
            arr[k++] = R[j++]; 
        } 
    } 
 
    while (i < n1) { 
        arr[k++] = L[i++]; 
    } 
    while (j < n2) { 
        arr[k++] = R[j++]; 
    } 
 
    free(L); 
    free(R); 
} 
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        int mid = left + (right - left) / 2; 
 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
 
        merge(arr, left, mid, right); 
    } 
} 
 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
int main() { 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
printf("Given array:\n"); 
printArray(arr, size); 
mergeSort(arr, 0, size - 1); 
printf("Sorted array:\n"); 
printArray(arr, size); 
return 0; 
}
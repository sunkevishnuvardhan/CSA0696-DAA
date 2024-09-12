#include <stdio.h> 
#include <limits.h> 
void findMaxMin(int arr[], int left, int right, int *max, int *min) { 
    if (left == right) { 
        *max = arr[left]; 
        *min = arr[left]; 
    } else if (right == left + 1) { 
        if (arr[left] > arr[right]) { 
            *max = arr[left]; 
            *min = arr[right]; 
        } else { 
            *max = arr[right]; 
            *min = arr[left]; 
        } 
    } else { 
        int mid = left + (right - left) / 2; 
        int leftMax, leftMin, rightMax, rightMin; 
 
        findMaxMin(arr, left, mid, &leftMax, &leftMin); 
        findMaxMin(arr, mid + 1, right, &rightMax, &rightMin); 
 
        *max = (leftMax > rightMax) ? leftMax : rightMax; 
        *min = (leftMin < rightMin) ? leftMin : rightMin; 
    } 
} 
 
int main() { 
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int max, min; 
 
    findMaxMin(arr, 0, size - 1, &max, &min); 
 
    printf("Maximum value: %d\n", max); 
    printf("Minimum value: %d\n", min); 
 
    return 0; 
} 
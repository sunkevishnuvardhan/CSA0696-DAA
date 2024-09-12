#include <stdio.h> 
#include <stdlib.h> 
#define MAX_ITEMS 100 
#define MAX_BINS 100 
// Function to compare items for sorting (used in qsort) 
int compare(const void *a, const void *b) { 
return (*(int*)b - *(int*)a); // Sort in descending order 
} 
// Function to perform the First-Fit Decreasing algorithm 
void containerLoader(int items[], int n, int binCapacity) { 
int bins[MAX_BINS]; 
int binCount = 0; 
int i, j; 
// Initialize all bins to 0 
for (i = 0; i < MAX_BINS; i++) { 
bins[i] = 0; 
} 
// Sort items in decreasing order 
qsort(items, n, sizeof(int), compare); 
// Place each item into the first bin that can accommodate it 
for (i = 0; i < n; i++) { 
int item = items[i]; 
int placed = 0; 
for (j = 0; j < binCount; j++) { 
if (bins[j] + item <= binCapacity) { 
bins[j] += item; 
placed = 1; 
break; 
} 
} 
// If item was not placed in any bin, create a new bin 
if (!placed) { 
bins[binCount] = item; 
binCount++; 
} 
} 
// Print the results 
printf("Number of bins used: %d\n", binCount); 
for (i = 0; i < binCount; i++) { 
printf("Bin %d: %d\n", i + 1, bins[i]); 
} 
} 
int main() { 
int items[MAX_ITEMS]; 
int n, binCapacity; 
// Input: number of items 
printf("Enter the number of items: "); 
scanf("%d", &n); 
// Input: items 
printf("Enter the items:\n"); 
for (int i = 0; i < n; i++) { 
scanf("%d", &items[i]); 
} 
// Input: bin capacity 
printf("Enter the bin capacity: "); 
scanf("%d", &binCapacity); 
// Solve the container loader problem 
containerLoader(items, n, binCapacity); 
return 0; 
} 
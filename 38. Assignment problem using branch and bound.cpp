#include <stdio.h> 
#include <limits.h> 
#define N 4  
void assignmentProblem(int costMatrix[N][N]); 
int branchAndBound(int costMatrix[N][N], int assignment[], int row, int n, 
int bound, int currCost, int minCost, int visited[]); 
int calculateLowerBound(int costMatrix[N][N], int assignment[], int n, int 
row, int visited[]); 
int findMinCost(int costMatrix[N][N], int assignment[], int n, int 
currCost, int minCost, int visited[]); 
int main() { 
int costMatrix[N][N] = { 
{10, 2, 8, 12}, 
{9, 4, 7, 6}, 
{5, 11, 13, 10}, 
{7, 9, 16, 5} 
}; 
assignmentProblem(costMatrix); 
return 0; 
} 
void assignmentProblem(int costMatrix[N][N]) { 
int assignment[N] = {-1}; 
int visited[N] = {0};
int minCost = INT_MAX; 
minCost = branchAndBound(costMatrix, assignment, 0, N, 0, 0, minCost, 
visited); 
printf("Minimum cost is %d\n", minCost); 
} 
int branchAndBound(int costMatrix[N][N], int assignment[], int row, int n, 
int bound, int currCost, int minCost, int visited[]) { 
if (row == n) { 
if (currCost < minCost) { 
minCost = currCost; 
} 
return minCost; 
} 
for (int col = 0; col < n; col++) { 
if (!visited[col]) { 
visited[col] = 1; 
assignment[row] = col; 
            int newBound = bound + costMatrix[row][col]; 
            int lowerBound = calculateLowerBound(costMatrix, assignment, n, 
row + 1, visited); 
            if (newBound + lowerBound < minCost) { 
                minCost = branchAndBound(costMatrix, assignment, row + 1, 
n, newBound, currCost + costMatrix[row][col], minCost, visited); 
            } 
 
            visited[col] = 0; 
            assignment[row] = -1; 
        } 
    } 
 
    return minCost; 
} 
 
int calculateLowerBound(int costMatrix[N][N], int assignment[], int n, int 
row, int visited[]) { 
    int bound = 0; 
 
    // Calculate the lower bound using row reduction 
    for (int i = row; i < n; i++) { 
        int min1 = INT_MAX, min2 = INT_MAX; 
        for (int j = 0; j < n; j++) { 
            if (!visited[j] && costMatrix[i][j] < min1) { 
                min2 = min1; 
                min1 = costMatrix[i][j]; 
            } else if (!visited[j] && costMatrix[i][j] < min2) { 
                min2 = costMatrix[i][j]; 
            } 
        } 
        bound += (min1 == INT_MAX) ? 0 : min1; 
        bound += (min2 == INT_MAX) ? 0 : min2; 
    } 
 
    // Calculate the lower bound using column reduction 
    for (int j = 0; j < n; j++) { 
        int min1 = INT_MAX, min2 = INT_MAX; 
        for (int i = row; i < n; i++) { 
            if (!visited[j] && costMatrix[i][j] < min1) { 
                min2 = min1; 
                min1 = costMatrix[i][j]; 
            } else if (!visited[j] && costMatrix[i][j] < min2) { 
                min2 = costMatrix[i][j]; 
            } 
        } 
        bound += (min1 == INT_MAX) ? 0 : min1; 
        bound += (min2 == INT_MAX) ? 0 : min2; 
    } 
 
    return bound / 2; 
} 
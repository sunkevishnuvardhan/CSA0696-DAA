#include <stdio.h> 
#include <limits.h> 
#include <stdbool.h> 
#define MAX 16 
#define INF INT_MAX 
// Function to find the minimum cost of visiting all cities and returning 
to the start 
int tsp(int n, int dist[MAX][MAX]) { 
int dp[1 << MAX][MAX]; 
// Initialize DP table with infinity 
    for (int mask = 0; mask < (1 << n); mask++) { 
        for (int i = 0; i < n; i++) { 
            dp[mask][i] = INF; 
        } 
    } 
     
    // Starting from the first city 
    dp[1][0] = 0; 
 
    // Iterate over all subsets of cities 
    for (int mask = 1; mask < (1 << n); mask += 2) { 
        for (int u = 0; u < n; u++) { 
            if (!(mask & (1 << u))) continue; 
            for (int v = 0; v < n; v++) { 
                if (mask & (1 << v)) continue; 
                int newMask = mask | (1 << v); 
                dp[newMask][v] = (dp[newMask][v] < dp[mask][u] + 
dist[u][v]) ? dp[newMask][v] : dp[mask][u] + dist[u][v]; 
            } 
        } 
    } 
 
    // Calculate the minimum cost to return to the starting city 
    int answer = INF; 
    for (int i = 1; i < n; i++) { 
        answer = (answer < dp[(1 << n) - 1][i] + dist[i][0]) ? answer : 
dp[(1 << n) - 1][i] + dist[i][0]; 
    } 
 
    return answer; 
} 
 
int main() { 
    int n; 
     
    // Input: number of cities 
    printf("Enter the number of cities: "); 
    scanf("%d", &n); 
 
    int dist[MAX][MAX]; 
     
    // Input: distance matrix 
    printf("Enter the distance matrix:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &dist[i][j]); 
        } 
    } 
 
    // Compute and print the minimum cost 
    int result = tsp(n, dist); 
    printf("The minimum cost of the TSP is: %d\n", result); 
 
    return 0; 
}
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 2  
void add(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) { 
for (int i = 0; i < SIZE; i++) { 
for (int j = 0; j < SIZE; j++) { 
result[i][j] = A[i][j] + B[i][j]; 
} 
} 
} 
void subtract(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) 
{ 
for (int i = 0; i < SIZE; i++) { 
for (int j = 0; j < SIZE; j++) { 
result[i][j] = A[i][j] - B[i][j]; 
} 
} 
} 
void strassen(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) { 
if (SIZE == 1) { 
C[0][0] = A[0][0] * B[0][0]; 
return; 
}  
int A11[SIZE / 2][SIZE / 2], A12[SIZE / 2][SIZE / 2]; 
int A21[SIZE / 2][SIZE / 2], A22[SIZE / 2][SIZE / 2]; 
int B11[SIZE / 2][SIZE / 2], B12[SIZE / 2][SIZE / 2]; 
int B21[SIZE / 2][SIZE / 2], B22[SIZE / 2][SIZE / 2]; 
int M1[SIZE / 2][SIZE / 2], M2[SIZE / 2][SIZE / 2]; 
int M3[SIZE / 2][SIZE / 2], M4[SIZE / 2][SIZE / 2]; 
int M5[SIZE / 2][SIZE / 2], M6[SIZE / 2][SIZE / 2]; 
int M7[SIZE / 2][SIZE / 2]; 
int temp1[SIZE / 2][SIZE / 2], temp2[SIZE / 2][SIZE / 2]; 
for (int i = 0; i < SIZE / 2; i++) { 
for (int j = 0; j < SIZE / 2; j++) { 
A11[i][j] = A[i][j]; 
A12[i][j] = A[i][j + SIZE / 2]; 
A21[i][j] = A[i + SIZE / 2][j]; 
A22[i][j] = A[i + SIZE / 2][j + SIZE / 2]; 
            B11[i][j] = B[i][j]; 
            B12[i][j] = B[i][j + SIZE / 2]; 
            B21[i][j] = B[i + SIZE / 2][j]; 
            B22[i][j] = B[i + SIZE / 2][j + SIZE / 2]; 
        } 
    } 
 
    add(A11, A22, temp1); 
    add(B11, B22, temp2); 
    strassen(temp1, temp2, M1); 
 
    add(A21, A22, temp1); 
    strassen(temp1, B11, M2); 
 
    subtract(B12, B22, temp1); 
    strassen(A11, temp1, M3); 
 
    subtract(B21, B11, temp1); 
    strassen(A22, temp1, M4); 
 
    add(A11, A12, temp1); 
    strassen(temp1, B22, M5); 
 
    subtract(A21, A11, temp1); 
    add(B11, B12, temp2); 
    strassen(temp1, temp2, M6); 
 
    subtract(A12, A22, temp1); 
    add(B21, B22, temp2); 
    strassen(temp1, temp2, M7); 
    add(M1, M4, temp1); 
    subtract(temp1, M5, temp2); 
    add(temp2, M7, C); 
 
    add(M3, M5, temp1); 
    C[0][1] = temp1[0][0]; 
 
    add(M2, M4, C); 
    C[1][0] = C[0][0]; 
 
    add(M1, M3, temp1); 
    subtract(temp1, M6, C); 
    C[1][1] = C[0][0]; 
} 
 
int main() { 
    int A[SIZE][SIZE] = {{1, 2}, {3, 4}}; 
    int B[SIZE][SIZE] = {{5, 6}, {7, 8}}; 
    int C[SIZE][SIZE]; 
    strassen(A, B, C); 
    printf("Result matrix C:\n"); 
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            printf("%d ", C[i][j]); 
} 
printf("\n"); 
} 
return 0; 
} 
#include <stdio.h> 
// Function to calculate the nth Fibonacci number using recursion 
int fibonacci(int n) { 
if (n <= 1) 
return n; 
else 
return (fibonacci(n - 1) + fibonacci(n - 2)); 
} 
int main() { 
int n, i; 
// Input: Number of terms to be printed 
printf("Enter the number of terms: "); 
scanf("%d", &n); 
// Output: Fibonacci series 
printf("Fibonacci Series: "); 
for (i = 0; i < n; i++) { 
printf("%d ", fibonacci(i)); 
} 
return 0; 
}
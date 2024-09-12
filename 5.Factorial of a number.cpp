#include <stdio.h>
unsigned long long factorial(int n) { 
unsigned long long fact = 1; 
for (int i = 1; i <= n; ++i) { 
fact *= i; 
} 
return fact; 
} 
int main() { 
int num;
printf("Enter a number: "); 
scanf("%d", &num);
if (num < 0) { 
printf("Factorial is not defined for negative numbers.\n"); 
} else { 
printf("Factorial of %d is %llu.\n", num, factorial(num)); 
} 
return 0; 
} 
// build a recursive program to print the binomial coefficients when the user gives an input of an inateger

#include <stdio.h>

void binCoeff(int n, int i);
int fact(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    binCoeff(n,0);
    return 0;
}

// iteravtive logic
/*
int binCoeff(int n) {
    for(int i = 0; i<=n; i++) {
        printf("%d ", fact(n)/(fact(i) * fact(n-i)));
    }
}
*/

// recursive logic
void binCoeff(int n, int i) {
    if(i > n) {
        return;
    }
    printf("%d ", fact(n)/(fact(i) * fact(n-i)));
    binCoeff(n, i+1);
}


int fact(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}
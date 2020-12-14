#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int n, **x;

    printf("Please enter the size of the square:");
    scanf("%d", &n);
    
    initializeSquare(&x,n);
    printSquare(x,n);
    playGame1(x, n);
    playGame2(x, n);
    playGame3(x, n);

    return 0;
}

void initializeSquare(int ***x, int n) {
    (*x) = calloc(n, sizeof(int *));
    for(int i = 0; i < n; ++i) { 
        (*x)[i] = calloc(n, sizeof(i));
    }
    
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < n; ++i) {
       for (int j = 0; j < n; ++j)
           (*x)[i][j] = rand()%n;
    }
}

void printSquare(int **x, int n) {

    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}

void playGame1(int **x, int n) {
    int number = rand()%n;
    printf("How many times does the number %d appear? ", number);
    int actual = countNumber(x, n, number);
    int correct = 0;
    while(correct == 0) {
        int guess;
        scanf("%d", &guess);
        correct = 1;
        if (guess != actual) {
            printf("Wrong :( Try again: ");
            correct = 0;
        }
    }
    printf("You are correct!\n");
}

int countNumber(int **x, int n, int number) {
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (x[i][j] == number) {
                ++count;
            }
        }
    }
    
    return count;
}

void playGame2(int **x, int n) {
    int sum = countSum(x, n);
    printf("What is the sum of all the numbers? ");
    int correct = 0;
    while(correct == 0) {
        int guess;
        scanf("%d", &guess);
        correct = 1;
        if (guess != sum) {
            printf("Wrong :( Try again: ");
            correct = 0;
        }
    }
    printf("You are correct!\n");
}

int countSum(int **x, int n) {
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += x[i][j];
        }
    }
    
    return sum;
}


void playGame3(int **x, int n) {
    int primes = countPrimes(x, n);
    printf("How many prime numbers are there? ");
    int correct = 0;
    while(correct == 0) {
        int guess;
        scanf("%d", &guess);
        correct = 1;
        if (guess != primes) {
            printf("Wrong :( Try again: ");
            correct = 0;
        }
    }
    printf("You are correct!\n");
}

int countPrimes(int **x, int n) {
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isPrime(x[i][j]) == 1) {
                count++;
            }
        }
    }
    
    return count;
}

int isPrime(int k) {
    if (k == 0 || k == 1) return 0;
    
    for (int i = 2; i <= sqrt(k); ++i) {
        if (k % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

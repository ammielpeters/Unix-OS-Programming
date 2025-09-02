#include <stdio.h>
#include <pthread.h>

int n;
long long fact = 1;

// Thread function to calculate factorial
void* factorial(void* arg) {
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return NULL;
}

int main() {
    pthread_t tid;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Create thread
    pthread_create(&tid, NULL, factorial, NULL);

    // Wait for thread to finish
    pthread_join(tid, NULL);

    printf("Factorial of %d is %lld\n", n, fact);
    return 0;
}

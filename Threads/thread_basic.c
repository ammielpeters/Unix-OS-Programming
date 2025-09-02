#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread runner function
void* runner(void* arg) {
    printf("Thread running...\n");
    sleep(1);
    printf("Thread finished execution.\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;

    // Initialize thread attributes
    pthread_attr_init(&attr);

    // Create thread
    pthread_create(&tid, &attr, runner, NULL);

    // Wait for thread to complete (join)
    pthread_join(tid, NULL);

    printf("Parent process resumes after thread completion.\n");
    return 0;
}

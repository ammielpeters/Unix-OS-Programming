#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("Parent process started. PID: %d\n", getpid());

    pid = fork(); // create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process created. PID: %d\n", getpid());
        printf("Child executing new task...\n");
        
        char *args[] = {"/bin/ls", "-l", NULL}; // program path & args
        execvp(args[0], args);

        // If exec fails
        perror("exec failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent waiting for child to complete...\n");
        wait(NULL); // synchronize
        printf("Child finished. Parent resumes.\n");
    }
    return 0;
}

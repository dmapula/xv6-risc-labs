#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(2, "Usage: %s command [args...]\n", argv[0]);
        exit(1);
    }

    // Record the current time
    uint64 start_time = uptime();

    // Fork a child process
    int pid = fork();
    if (pid < 0) {
        fprintf(2, "Fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        // This is the child process
        // Execute the provided command with exec
        exec(argv[1], &argv[1]);
        // If exec returns, it means it failed
        fprintf(2, "Exec failed\n");
        exit(1);
    } else {
        // This is the parent process
        // Wait for the child to finish
        wait(0);

        // Record the current time again
        uint64 end_time = uptime();

        // Calculate and print the elapsed time
        printf("Time: %d ticks\n", (int)(end_time - start_time));
    }

    exit(0);
}

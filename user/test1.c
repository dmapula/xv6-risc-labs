#include "kernel/types.h"
#include "user/user.h"

int main() {
    int size = 10000; // Number of pages to allocate
    char *memory = malloc(size * 4096); // Allocate memory without touching it

    // No memory access here

    free(memory); // Free the allocated memory
    exit(0);
}

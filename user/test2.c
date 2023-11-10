#include "kernel/types.h"
#include "user/user.h"

int main() {
    int num_pages = 100; // Number of pages to allocate and touch
    char *memory = malloc(num_pages * 4096); // Allocate memory

    // Access each allocated page
    for (int i = 0; i < num_pages; i++) {
        memory[i * 4096] = 1; // Touch each page
    }

    free(memory); // Free the allocated memory
    exit(0);
}

#include "kernel/types.h"
#include "user/user.h"

int main() {
    int num_pages = 100; // Number of pages to allocate
    char *memory = malloc(num_pages * 4096); // Allocate memory

    // Randomly access some of the allocated pages
    for (int i = 0; i < num_pages / 2; i++) {
        int random_page = rand() % num_pages;
        memory[random_page * 4096] = 1; // Touch random pages
    }

    free(memory); // Free the allocated memory
    exit(0);
}

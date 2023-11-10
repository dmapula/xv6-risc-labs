#include "kernel/types.h"
#include "user/user.h"

int main() {
    int64 large_amount = (int64)2 * 1024 * 1024 * 1024; // 2GB, adjust as needed
    char *allocated = sbrk(large_amount);

    if (allocated == (char *)-1) {
        printf("sbrk failed to allocate memory\n");
    } else {
        printf("sbrk allocated %lld bytes of memory\n", large_amount);
    }

    exit(0);
}

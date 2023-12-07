#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) {
        printf(2, "Usage: fstat filename\n");
        exit();
    }

    if (stat(argv[1], &st) < 0) {
        printf(2, "fstat: cannot stat %s\n", argv[1]);
        exit();
    }

    printf(1, "name: %s\ttype: %s\n", argv[1],
           (st.type == T_FILE) ? "regular file" : "directory");
    printf(1, "size: %d bytes\n", st.size);
    printf(1, "inode number: %d\tlinks: %d\n", st.ino, st.nlink);

    exit();
}
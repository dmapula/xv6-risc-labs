#define T_DIR     1   // Directory
#define T_FILE    2   // File
#define T_DEVICE  3   // Device
#define PROT_READ (1L << 1)
#define PROT_WRITE (1L << 2)
#define MAP_SHARED 0X01 /* Share changes*/
#define MAP_PRIVATE 0X02 /*changes are private*/
#define MAP_ANONYMOUS 0X20 /* No associated file */

struct stat {
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short type;  // Type of file
  short nlink; // Number of links to file
  uint64 size; // Size of file in bytes
};

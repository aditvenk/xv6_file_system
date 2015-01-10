#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define NAME_MAX  1024
int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf(1, "Usage: filestat <pathname> \n");
    exit();
  }
  printf(1, "file name = %s \n", argv[1]);
  struct stat st; 
  int fd = open (argv[1], O_RDONLY);
  if (fd < 0) {
    printf(1, "file %s open failed \n", argv[1]);
    exit();
  }
  printf(1, "file %s opened \n", argv[1]);
  if (fstat(fd, &st) < 0) {
    printf(1, "fstat failed \n");
    exit();
  }
  printf(1, "stat output: \n");
  printf(1, "type = %d, dev = %d, inode-num = %d, nlink = %d, size = %d \n", st.type, st.dev, st.ino, st.nlink, st.size);
  printf(1, "logical_size = %d, physical_size = %d \n", st.logical_size, st.physical_size);

  exit();
}




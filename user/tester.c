// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{

  printf(1, "mirrored fs test \n");
  /*
  int fd;
  fd = open("echo", O_CREATE);
  if (fd < 0)
    exit();
  close(fd);
  */

  /*
  struct stat st;
  if (stat("echo", &st) < 0) {
    printf(1, "stat failure" );
    exit();
  }
  printf(1, "stat output: \n");
  printf(1, "type = %d, dev = %d, inode-num = %d, nlink = %d, size = %d \n", st.type, st.dev, st.ino, st.nlink, st.size);
  printf(1, "logical_size = %d, physical_size = %d \n", st.logical_size, st.physical_size);
  */

  int fd;
  char buf[128];
  fd = open ( "temp.txt", O_CREATE | O_MIRRORED | O_RDWR);
  if (fd < 0) {
    printf(1, "open failed \n");
    exit();
  }
  int j=0;
  char temp[512];
  for (j=0; j<512; j++){
    temp[j] = 'x';
  }
  for (j=0;j<7;j++) {
    if (write(fd, temp, 512) != 512) {
      printf(1, "Write failed \n");
      exit();
    }
  }
  printf(1, "write done\n");
  close(fd);
  fd = open ( "temp.txt", O_MIRRORED | O_RDONLY);
  if (fd < 0)
    exit();

  int i = read(fd, buf, 10);
  
  if (i != 10) {
    printf(1, "read failed \n");
    exit();
  }
  
  printf(1, "read text = %s ", buf);
  close(fd);
  //unlink("temp.txt");

  exit();
}

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main() {
  struct dirent * dirs;
  struct stat sb;
  int size = 0;
  DIR *d;
  char * directory = ".";
  d = opendir(directory);
  printf("Statistics for directory: %s\n\n", directory);
  dirs = readdir(d);
  while (dirs) {
    if (dirs -> d_type == DT_DIR) {
      printf("d ");
    }
    else {
      printf("  ");
    }
    printf("%s \t", dirs -> d_name);
    stat(dirs -> d_name, &sb);
    size += sb.st_size;
    printf("%d\n", sb.st_size);
    dirs = readdir(d);
  }
  printf("\nTotal directory size: %d\n", size);
  closedir(d);
  return 0;
}

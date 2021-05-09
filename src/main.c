#include <stdio.h>
#include "dynarray.h"

int main(int argc, char *argv[])
{
  dynarray(int) d = dynarray_init(int);
  d[0] = 1;
  d[1] = 2;
  printf("%d\n", dyn_info(d).size);
}

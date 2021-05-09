#include <stdio.h>
#include "dynarray.h"

int main(int argc, char *argv[])
{
  dynarray(int) d = dyn_init(int);
  dynarray_info *info = dyn_info(d);

  for (int i = 0; i < 15; i++)
  {
    dyn_add(d, i);

    for (int j = 0; j < info->len; j++)
      printf("%d, ", d[j]);

    printf("\n");
    printf("Information: len: %d, size: %d, el_size: %d\n", info->len, info->size, info->el_size);
  }
  printf("%d\n", d[14]);
  printf("%d\n", info->len);
  printf("%d\n", info->size);
    printf("(dyn_info(d))rmation: len: %d, size: %d, el_size: %d\n", (dyn_info(d))->len, (dyn_info(d))->size, (dyn_info(d))->el_size);
}

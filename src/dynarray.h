#ifndef _DYNARRAY_H
#define _DYNARRAY_H

#include <math.h>
#include <stdlib.h>

#define dynarray(T) T*

#define dynarray_init(T) ({ \
  dynarray_info *ptr = (dynarray_info *) malloc(sizeof(dynarray_info) + sizeof(T) * 10); \
  ptr[0] = (dynarray_info) { .size = 10, .len = 0, .el_size = sizeof(T) }; \
  (T *) &ptr[1]; })

typedef struct 
{
  int size;
  int len;
  int el_size;
} dynarray_info;

dynarray_info dyn_info(dynarray(void) d);

#endif /* ifndef DYNARRAY.H */

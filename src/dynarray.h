#ifndef _DYNARRAY_H
#define _DYNARRAY_H

#include <math.h>
#include <stdlib.h>

#define dynarray(T) T*

#define dyn_init(T) ({ \
  dynarray_info *ptr = (dynarray_info *) malloc(sizeof(dynarray_info) + sizeof(T) * 10); \
  ptr[0] = (dynarray_info) { .size = 10, .len = 0, .el_size = sizeof(T), .ptr = ptr }; \
  (T *) &ptr[1]; })

#define dyn_info(d)  &((dynarray_info *) d)[-1]

#define dyn_add(d, arg) { \
  dynarray_info *info = dyn_info(d); \
  d[info->len] = arg; \
  info->len += 1; \
  if (info->len == info->size) { \
    info->size = info->size * 2; \
    dynarray_info *info_ptr = (dynarray_info *) realloc(info->ptr, sizeof(dynarray_info) + info->el_size * info->size); \
    d = info_ptr[1]; \
  }}

typedef struct 
{
  int size;
  int len;
  int el_size;
  void *ptr;
} dynarray_info;

#endif /* ifndef DYNARRAY.H */

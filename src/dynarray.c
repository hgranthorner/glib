#include <stdlib.h>
#include "dynarray.h"

dynarray_info *dyn_info(dynarray(void) d)
{
  dynarray_info *ptr = (dynarray_info *) d;
  return &ptr[-1];
}

void dyn_add(dynarray(void) d, void arg)
{
  dynarray_info *info = dyn_info(d);
  d[info->len] = arg;
  info->len = info->len += 1;

  if (info->len == info->size)
  {
    resize(d, info);
  }
}

void resize(dynarray(void) d, dynarray_info *info)
{
  info->size = info->size * 2;
  d = (dynarray(void)) realloc(d, info->size);
}

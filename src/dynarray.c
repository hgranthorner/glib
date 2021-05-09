#include "dynarray.h"


dynarray_info dyn_info(dynarray(void) d)
{
  dynarray_info *ptr = (dynarray_info *) d;
  return ptr[-1];
}


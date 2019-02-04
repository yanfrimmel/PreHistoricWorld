#include <stdlib.h>
#include "HsFFI.h"
// This works for GHC 8.0.2
HsBool mylib_init(void) __attribute__((constructor));
HsBool mylib_init(void){
  int argc = 2;
  char *argv[] = { "+RTS", "-A32m", NULL };
  char **pargv = argv;

  // Initialize Haskell runtime
  hs_init(&argc, &pargv);

  // do any other initialization here and
  // return false if there was a problem
  return HS_BOOL_TRUE;
}

void mylib_end(void) __attribute__((destructor));
void mylib_end(void){
  hs_exit();
}
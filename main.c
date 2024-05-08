#define CTESTS_IMPLEMENTATION
#define CTVERBOSE
#include <stdio.h>

#include "ctests.h"

int some_f(int a, int b) { return a + b; }

int main() {

  CT_ASSERT_INT(some_f(1, 2), 3);
  CT_ASSERT_INT(some_f(2, 2), 3);
  CT_ASSERT_INT(some_f(3, 2), 5);
  CT_ASSERT_INT(some_f(2, 3), 5);
  CT_ASSERT_INT(some_f(3, 3), 6);

  CT_STAT();

  printf("Hello, %d\n", some_f(1, 2));

  return 0;
}

#define CTESTS_IMPLEMENTATION
#define CTVERBOSE
#include <stdio.h>

#include "ctests.h"

int some_f(int a, int b) { return a + b; }

typedef struct {
  int x, y;
} Point;

int compare_point(void *p1, void *p2) {
  Point *tp1 = (Point *)p1;
  Point *tp2 = (Point *)p2;

  if ((tp1->x == tp2->x) && (tp1->y == tp2->y)) {
    return 1;
  } else {
    return 0;
  }
}

Point p1 = {.x = 2, .y = 1};
Point p2 = {.x = 1, .y = 2};
Point p3 = {.x = 2, .y = 1};

int main() {

  int verbose = 1;

  CT_ASSERT_INT(some_f(1, 2), 3);
  CT_ASSERT_INT(some_f(2, 2), 3);
  CT_ASSERT_INT(some_f(3, 2), 5);
  CT_ASSERT_INT(some_f(2, 3), 5);
  CT_ASSERT_INT(some_f(3, 3), 6);
  CT_ASSERT_CMP(&p2, &p3, compare_point);
  CT_ASSERT_CMP(&p1, &p3, compare_point);

  CT_STAT();

  printf("Hello, %s\n", compare_point(&p1, &p3) ? "true" : "false");

  return 0;
}

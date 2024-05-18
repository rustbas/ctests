#define CTESTS_IMPLEMENTATION

#include <stdio.h>

#include "ctests.c"
// #include <math.h>

int sum(int a, int b) { return a + b; }

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

  ct_verbose = 1;

  ct_assert_int(sum(1, 2), 3);
  ct_assert_int(sum(1, 2), 3);
  ct_assert_int(sum(2, 2), 3);
  ct_assert_int(sum(3, 2), 5);
  ct_assert_int(sum(2, 3), 5);
  ct_assert_int(sum(3, 3), 6);
  ct_assert_cmp(&p2, &p3, compare_point);
  ct_assert_cmp(&p1, &p3, compare_point);
  ct_assert_float(1.0, 1.0, 0.1);
  ct_assert_float(3.0, 1.0, 0.1);

  ct_stat();

  printf("hello, %s\n", compare_point(&p1, &p3) ? "true" : "false");

  return 0;
}

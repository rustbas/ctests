#ifndef _CTESTS
#define _CTESTS

// Dirty hack to make LSP in nvim work
#ifndef CTESTS_IMPLEMENTATION
#define CTESTS_IMPLEMENTATION
#define _CTESTS_IMPLEMENTATION
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#include <stddef.h>

#define CT_BLACK "\033[0;30m"
#define CT_RED "\033[0;31m"
#define CT_GREEN "\033[0;32m"
#define CT_YELLOW "\033[0;33m"
#define CT_BLUE "\033[0;34m"
#define CT_MAGENTA "\033[0;35m"
#define CT_CYAN "\033[0;36m"
#define CT_NOCOLOR "\033[0m"

#define CTLOG "[" CT_CYAN "LOG" CT_NOCOLOR "]: "
#define CTMSG "[MSG]: "
#define CTERR "[" CT_RED "ERR" CT_NOCOLOR "]: "

#define CTFAIL "[" CT_RED "FAIL" CT_NOCOLOR "]: "
#define CTPASS "[" CT_GREEN "PASS" CT_NOCOLOR "]: "

/////////////
// HEADERS //
/////////////

// 0 - no verbose
// 1 - only FAIL
// 2 - all verbose
int ct_verbose = 0;

int ct_assert_int(int a, int b);
int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *));
int ct_assert_float(float a, float b, float eps);
int ct_assert_double(double a, double b, double eps);
int ct_stat(void);

#endif

#ifdef CTESTS_IMPLEMENTATION

/////////////////
// SOURCE CODE //
/////////////////

size_t ct_all_counter = 0;
size_t ct_passed_counter = 0;
size_t ct_failed_counter = 0;
size_t ct_skipped_counter = 0;

int ct_assert_int(int a, int b) {
  ct_all_counter++;
  if (a == b) {
    if (ct_verbose == 2)
      printf(CTPASS "Test %zu Passed\n", ct_all_counter);

    ct_passed_counter++;
    return 0;
  } else {
    if (ct_verbose > 0)
      printf(CTFAIL "Test %zu Failed: %d != %d"
                    "\n",
             ct_all_counter, a, b);

    ct_failed_counter++;
    return 1;
  }
}

int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *)) {
  ct_all_counter++;
  if (f(a, b)) {
    if (ct_verbose == 2) {
      printf(CTPASS "Test %zu Passed\n", ct_all_counter);
    }
    ct_passed_counter++;
    return 0;
  } else {
    if (ct_verbose > 0)
      printf(CTFAIL "Test %zu Failed"
                    "\n",
             ct_all_counter);

    ct_failed_counter++;
    return 1;
  }
}

int ct_assert_float(float a, float b, float eps) {
  ct_all_counter++;
  if (fabs(a - b) < eps) {
    if (ct_verbose == 2)
      printf(CTPASS "Test %zu Passed\n", ct_all_counter);

    ct_passed_counter++;
    return 0;

  } else {
    if (ct_verbose > 0)
      printf(CTFAIL "Test %zu Failed"
                    "\n",
             ct_all_counter);

    ct_failed_counter++;
    return 1;
  }
}

int ct_assert_double(double a, double b, double eps) {
  ct_all_counter++;
  if (fabs(a - b) < eps) {
    if (ct_verbose == 2)
      printf(CTPASS "Test %zu Passed\n", ct_all_counter);

    ct_passed_counter++;
    return 0;

  } else {
    if (ct_verbose > 0)
      printf(CTFAIL "Test %zu Failed"
                    "\n",
             ct_all_counter);

    ct_failed_counter++;
    return 1;
  }
}

int ct_stat(void) {
  printf(CTLOG);
  printf("Passed: %zu/%zu\t", ct_passed_counter, ct_all_counter);
  printf("Failed: %zu/%zu\n", ct_failed_counter, ct_all_counter);

  return 0;
}

#endif

// End of dirty hack to make LSP in nvim work
#ifdef CTESTS_IMPLEMENTATION_OPEN
#undef _CTESTS_IMPLEMENTATION
#undef CTESTS_IMPLEMENTATION
#endif

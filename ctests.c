#ifndef _CTESTS
#define _CTESTS

// Dirty hack to make LSP in nvim work
#ifndef CTESTS_IMPLEMENTATION
#define CTESTS_IMPLEMENTATION
#define CTESTS_IMPLEMENTATION_OPEN
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

#define CT_ASSERT_INT(a, b) ct_assert_int((a), (b), verbose)
#define CT_ASSERT_CMP(a, b, c) ct_assert_cmp((a), (b), (c), verbose)
#define CT_ASSERT_FLT(a, b, c) ct_assert_float((a), (b), (c), verbose)
#define CT_STAT() ct_stat()

/////////////
// HEADERS //
/////////////

int ct_assert_int(int a, int b, int verbose);
int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *), int verbose);
int ct_assert_float(float a, float b, float eps, int verbose);
int ct_stat(void);

#endif

#ifdef CTESTS_IMPLEMENTATION

/////////////////
// SOURCE CODE //
/////////////////

size_t all_counter = 0;
size_t passed_counter = 0;
size_t failed_counter = 0;
size_t skipped_counter = 0;

int ct_assert_int(int a, int b, int verbose) {
  all_counter++;
  if (a == b) {
    if (verbose) {
      printf(CTPASS "Test %zu Passed\n", all_counter);
    }
    passed_counter++;
    return 0;
  } else {
    if (verbose) {
      printf(CTFAIL "Test %zu Failed: %d != %d"
                    "\n",
             all_counter, a, b);
    }
    failed_counter++;
    return 1;
  }
}

int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *), int verbose) {
  all_counter++;
  if (f(a, b)) {
    if (verbose) {
      printf(CTPASS "Test %zu Passed\n", all_counter);
    }
    passed_counter++;
    return 0;
  } else {
    if (verbose) {
      printf(CTFAIL "Test %zu Failed"
                    "\n",
             all_counter);
    }
    failed_counter++;
    return 1;
  }
}

int ct_assert_float(float a, float b, float eps, int verbose) {
  all_counter++;
  if (fabs(a - b) < eps) {
    if (verbose) {
      printf(CTPASS "Test %zu Passed\n", all_counter);
    }
    passed_counter++;
    return 0;

  } else {
    if (verbose) {
      printf(CTFAIL "Test %zu Failed"
                    "\n",
             all_counter);
    }
    failed_counter++;
    return 1;
  }
}

int ct_stat(void) {
  printf(CTLOG);
  printf("Passed: %zu/%zu\t", passed_counter, all_counter);
  printf("Failed: %zu/%zu\n", failed_counter, all_counter);

  return 0;
}

#endif

// End of dirty hack to make LSP in nvim work
#ifdef CTESTS_IMPLEMENTATION_OPEN
#undef CTESTS_IMPLEMENTATION_OPEN
#undef CTESTS_IMPLEMENTATION
#endif

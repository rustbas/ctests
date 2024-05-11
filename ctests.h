#ifndef _CTESTS
#define _CTESTS

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif

#include <stddef.h>

#define CT_RED "\033[0;31m"
#define CT_GREEN "\033[0;32m"
#define CT_NC "\033[0m"

#define CTLOG "[LOG]: "
#define CTMSG "[MSG]: "
#define CTERR "[" CT_RED "ERR" NC "]: "

#define CTFAIL "[" CT_RED "FAIL" NC "]: "
#define CTPASS "[" CT_GREEN "PASS" NC "]: "

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

  if (a == b) {
    if (verbose) {
      printf(CTPASS "Test %d Passed\n", all_counter);
    }
    passed_counter++;
    all_counter++;
    return 1;
  } else {
    if (verbose) {
      printf(CTFAIL "Test %d Failed: %d != %d"
                    "\n",
             all_counter, a, b);
    }
    failed_counter++;
    all_counter++;
  }
}

int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *), int verbose) {
  all_counter++;
  if (f(a, b)) {
    if (verbose) {
      printf(CTPASS "Test %d Passed\n", all_counter);
    }
    passed_counter++;
    return 1;
  } else {
    if (verbose) {
      printf(CTFAIL "Test %d Failed"
                    "\n",
             all_counter);
    }
    failed_counter++;
  }
}

int ct_assert_float(float a, float b, float eps, int verbose) {
  all_counter++;
  if (fabs(a - b) < eps) {
    if (verbose) {
      printf(CTPASS "Test %d Passed\n", all_counter);
    }
    passed_counter++;
    return 1;

  } else {
    if (verbose) {
      printf(CTFAIL "Test %d Failed"
                    "\n",
             all_counter);
    }
    failed_counter++;
  }
}

int ct_stat(void) {
  printf("STAT: ");
  printf("Passed: %d/%d\t", passed_counter, all_counter);
  printf("Failed: %d/%d\n", passed_counter, all_counter);
}

#endif

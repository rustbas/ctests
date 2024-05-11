#ifndef _CTESTS
#define _CTESTS

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#include <stddef.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

#define CTLOG "[LOG]: "
#define CTMSG "[MSG]: "
#define CTERR "[" RED "ERR" NC "]:"

#define CTFAIL "[" RED "FAIL" NC "]:"
#define CTPASS "[" GREEN "PASS" NC "]:"

/////////////
// HEADERS //
/////////////

int ct_assert_int(int a, int b, int verbose);
int ct_stat(void);
int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *), int verbose);

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
      printf(CTPASS "TEST %d PASSED\n", all_counter);
    }
    passed_counter++;
    all_counter++;
    return 1;
  } else {
    if (verbose) {
      printf(CTFAIL "TEST %d FAILED: %d != %d"
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
      printf(CTPASS "TEST %d PASSED\n", all_counter);
    }
    passed_counter++;
    return 1;
  } else {
    if (verbose) {
      printf(CTFAIL "TEST %d FAILED"
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

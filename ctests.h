#ifndef _CTESTS
#define _CTESTS

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

int CT_ASSERT_INT(int a, int b);
int CT_STAT(void);

#endif

#ifdef CTESTS_IMPLEMENTATION

/////////////////
// SOURCE CODE //
/////////////////

size_t all_counter = 0;
size_t passed_counter = 0;
size_t failed_counter = 0;
size_t skipped_counter = 0;

int CT_ASSERT_INT(int a, int b) {

  if (a == b) {
#ifdef CTVERBOSE
    printf(CTPASS "TEST %d PASSED\n", all_counter);
#endif
    passed_counter++;
    all_counter++;
    return 1;
  } else {
#ifdef CTVERBOSE
    printf(CTFAIL "TEST %d FAILED: %d != %d"
                  "\n",
           all_counter, a, b);
#endif
    failed_counter++;
    all_counter++;
  }
}

int CT_STAT(void) {
  printf("STAT: ");
  printf("Passed: %d/%d\t", passed_counter, all_counter);
  printf("Failed: %d/%d\n", passed_counter, all_counter);
}
#endif

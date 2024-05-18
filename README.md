# Description

Single-file library for testing for C.

# Usage

Just include the library with `define`:
```c
#define CTESTS_IMPLEMENTATION
#include "path/to/ctests.h"
```

# Description

## Functions

There are several functions to testing functions. 

1. `int ct_assert_int(int a, int b)` -- compare two integers. Returns 0 if they're equal, 1 if not.
2. `int ct_assert_cmp(void *a, void *b, int (*f)(void *, void *))` -- compare two structs. `f` -- compare function must return 1 if structs are not equal, 0 otherwise.
3. `int ct_assert_float(float a, float b, float eps)` -- compare two floats. Returns 0 if absolute error between them less than `eps`, 1 otherwise.
4. `int ct_stat(void)` -- prints stats about testing.

## Variables

1. `int ct_verbose` -- level of verbosity. Default value is 0.
    1.`0` - no verbose;
    2.`1` - show only fails;
    3.`2` - all verbose;
2. `size_t ct_all_counter` -- number of tests. Increase in each test.
3. `size_t ct_passed_counter` -- number of passed tests.
4. `size_t ct_failed_counter` -- number of failed tests.
5. `size_t ct_skipped_counter` -- number of skipped tests (at present time not in use).

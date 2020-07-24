#ifndef C_UT_H
#define C_UT_H
/**
   @file c_ut.h
   @brief Unit testing.

   Unit testing framework used by libcian in order to verify data structures
   and algorithms. Provides basic unit testing macros.
*/

/**
  Check whether the given function is true or false.

  @param message the error string printed upon failure
  @param test the function pointer to test given case
*/
#define C_ASSERT(message, test) do { if (!(test)) return message; } while (0)

/**
   Runs the given test function and returns error messages upon failure.

   @param test the function pointer to test given case
 */
#define C_RUN_TEST(test) do { char *message = test(); tests_run++; \
                               if (message) return message; } while (0)

extern int tests_run; // the number of tests executed

#endif

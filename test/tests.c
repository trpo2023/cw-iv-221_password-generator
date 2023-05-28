#include <libpwgen/argument_processing.h>

#include "ctest.h"

// CTEST(pwgen, simple_sum)
// {
//     // Given
//     const int a = 1;
//     const int b = 2;

//     // When
//     const int result = sum(a, b);

//     // Then
//     const int expected = 3;
//     ASSERT_EQUAL(expected, result);
// }


CTEST(pwgen, pool_assembling)
{
    // Given
    char **argv = {"./bin/pwgen","10","2","-y", "-N", "-A", "-0"};
    int argc = 7;
    // char *first = "-y";
    // char *second = "-N";
    // char *third = "-A";
    // char *forth = "-0";
    
    // When
    const char *result = pool_assembling(argv,argc);
    // Then
    char symbols[] = "!#$&'()*+,/:;<=>?@[]^_{|}~`";
    ASSERT_EQUAL(symbols, result);
}
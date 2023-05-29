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


// CTEST(argument_processing, pool_assembling)
// {
//     // Given
//     char *argv[] = {"./bin/pwgen","10","2","-y", "-N", "-A", "-0"};
//     int argc = 7;
//     // char *first = "-y";
//     // char *second = "-N";
//     // char *third = "-A";
//     // char *forth = "-0";
    
//     // When
//     char *result = pool_assembling(argv,argc);
//     // Then
//     char symbols[] = "!#$&'()*+,/:;<=>?@[]^_{|}~`";
//     ASSERT_EQUAL(symbols, result);
// }

CTEST(argument_processing, check_len_quantity_1)
{
    // Given
    char *argv[] = {"./bin/pwgen","10","2","-y", "-N", "-A", "-0"};
    int argc = 7;
    int len = 0; int quantity = 0;
    // When
    check_len_quantity(argv,argc,&len,&quantity);

    // Then
    int expected_len = 10;
    int expected_quan = 2;
    ASSERT_EQUAL(expected_len, len);
    ASSERT_EQUAL(expected_quan, quantity);
}

CTEST(argument_processing, check_len_quantity_2)
{
    // Given
    char *argv[] = {"./bin/pwgen","5","-0","-y", "-N", "-A", "20"};
    int argc = 7;
    int len = 0; int quantity = 0;
    // When
    check_len_quantity(argv,argc,&len,&quantity);

    // Then
    int expected_len = 5;
    int expected_quan = 20;
    ASSERT_EQUAL(expected_len, len);
    ASSERT_EQUAL(expected_quan, quantity);
}

CTEST(argument_processing, check_len_quantity_3)
{
    // Given
    char *argv[] = {"./bin/pwgen","-y","-0","100", "-N", "1", "-N"};
    int argc = 7;
    int len = 0; int quantity = 0;
    // When
    check_len_quantity(argv,argc,&len,&quantity);

    // Then
    int expected_len = 100;
    int expected_quan = 1;
    ASSERT_EQUAL(expected_len, len);
    ASSERT_EQUAL(expected_quan, quantity);
}
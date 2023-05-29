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


CTEST(argument_processing, pool_assembling_1)
{
    // Given
    char *argv[] = {"./bin/pwgen","10","2","-y"};
    int argc = 4;
    
    // When
    char *result = pool_assembling(argv,argc);
    // Then
    char *symbols= "!#$&'()*+,/:;<=>?@[]^_{|}~`abcdefghijklmnoqprstuvwyzxABCDEFGHIJKLMNOQPRSTUYWVZX0123456789";
    for(int i =0;i<strlen(result);i++){
        ASSERT_EQUAL(symbols[i], result[i]);
    }
}

CTEST(argument_processing, pool_assembling_2)
{
    // Given
    char *argv[] = {"./bin/pwgen","10","2","-N"};
    int argc = 4;
    
    // When
    char *result = pool_assembling(argv,argc);
    // Then
    char *symbols= "0123456789";
    for(int i =0;i<strlen(result);i++){
        ASSERT_EQUAL(symbols[i], result[i]);
    }
}

CTEST(argument_processing, pool_assembling_3)
{
    // Given
    char *argv[] = {"./bin/pwgen","10","2","-0"};
    int argc = 4;
    
    // When
    char *result = pool_assembling(argv,argc);
    // Then
    char *symbols= "abcdefghijklmnoqprstuvwyzxABCDEFGHIJKLMNOQPRSTUYWVZX";
    for(int i =0;i<strlen(result);i++){
        ASSERT_EQUAL(symbols[i], result[i]);
    }
}

CTEST(argument_processing, pool_assembling_4)
{
    // Given
    char *argv[] = {"./bin/pwgen","10","2","-A"};
    int argc = 4;
    
    // When
    char *result = pool_assembling(argv,argc);
    // Then
    char *symbols= "abcdefghijklmnoqprstuvwyzx0123456789";
    for(int i =0;i<strlen(result);i++){
        ASSERT_EQUAL(symbols[i], result[i]);
    }
}

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
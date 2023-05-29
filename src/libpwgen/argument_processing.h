#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void check_len_quantity(char *argv[], int argc, int *len, int *quantity);

char *pool_assembling(char *argv[], int argc);

void generator(char *pool, int len, int quantity);

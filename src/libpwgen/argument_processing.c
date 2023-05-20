#include <libpwgen/argument_processing.h>

void check_len_quantity(char *argv[], int argc, int *len, int *quantity)
{
    int lenq = 0;
    for (int i = 0; i < argc; i++)
    {
        if (isdigit(argv[i][0]) && (lenq == 0))
        {
            *len = atoi(argv[i]);
            lenq++;
        }
        else if (isdigit(argv[i][0]) && (lenq == 1))
        {
            *quantity = atoi(argv[i]);
            lenq++;
        }
    }
}


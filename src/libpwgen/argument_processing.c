#include <libpwgen/argument_processing.h>

void check_len_quantity(char* argv[], int argc, int* len, int* quantity)
{
    int lenq = 0;
    for (int i = 0; i < argc; i++) {
        if (isdigit(argv[i][0]) && (lenq == 0)) {
            *len = atoi(argv[i]);
            lenq++;
        } else if (isdigit(argv[i][0]) && (lenq == 1)) {
            *quantity = atoi(argv[i]);
            lenq++;
        }
    }
}

char* pool_assembling(char* argv[], int argc)
{
    int SymbCount = 0;
    char* pool = malloc(128 * sizeof(char));
    int NoLet = 0;
    int NoNum = 0;
    int NoUp = 0;
    char numbers[] = "0123456789";
    char allletter[] = "abcdefghijklmnoqprstuvwyzxABCDEFGHIJKLMNOQPRSTUYWVZX";
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    char symbols[] = "!#$&'()*+,/:;<=>?@[]^_{|}~`";
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-y") == 0) {
            for (int i = 0; i < strlen(symbols); i++) {
                pool[SymbCount] = symbols[i];
                SymbCount++;
            }
        }

        if (strcmp(argv[i], "-N") == 0) {
            NoLet++;
        }
        if (strcmp(argv[i], "-A") == 0) {
            NoUp++;
        }
        if (strcmp(argv[i], "-0") == 0) {
            NoNum++;
        }
    }

    if (NoUp == 1) {
        for (int i = 0; i < strlen(letter); i++) {
            pool[SymbCount] = letter[i];
            SymbCount++;
        }
    } else if (NoLet == 0) {
        for (int i = 0; i < strlen(allletter); i++) {
            pool[SymbCount] = allletter[i];
            SymbCount++;
        }
    }
    if (NoNum == 0) {
        for (int i = 0; i < strlen(numbers); i++) {
            pool[SymbCount] = numbers[i];
            SymbCount++;
        }
    }
    return pool;
}

void generator(char* pool, int len, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        for (int j = 0; j < len; j++) {
            printf("%c", pool[rand() % (strlen(pool))]);
        }
        printf("\n");
    }
}

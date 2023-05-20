#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            printf("./pwgen [ OPTION ] [ pw_length ] [ num_pw ]\nExample:./pwgen -A 6 4\n-0 В генерируемом пароле не будет цифр\n-А В генерируемом пароле не будет заглавных букв\n-N В генерируемом пароле не будет букв\n-n В генерируемом пароле будет как минимум одна цифра\n-y В генерируемом пароле будет минимум один спец. символ\n");
            return 0;
        }
    }
    return 0;
}
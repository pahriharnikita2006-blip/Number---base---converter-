
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <emscripten.h>

void convert(long long number, int base, char output[])
{
    char digits[] = "0123456789ABCDEF";
    char temp[100];
    int i = 0;
    int j = 0;

    if (number == 0)
    {
        strcpy(output, "0");
        return;
    }

    while (number > 0)
    {
        temp[i++] = digits[number % base];
        number /= base;
    }

    while (i > 0)
    {
        output[j++] = temp[--i];
    }

    output[j] = '\0';
}

EMSCRIPTEN_KEEPALIVE
char* convert_all(const char *input, int base)
{
    static char result[400];

    char decimal[100];
    char binary[100];
    char octal[100];
    char hexadecimal[100];

    unsigned long long number = 0;

    if (input == NULL || input[0] == '\0')
        return "ERROR";

    if (base != 2 && base != 8 && base != 10 && base != 16)
        return "ERROR";

    for (int i = 0; input[i] != '\0'; i++)
    {
        int digit;

        char ch = input[i];

        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            digit = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            digit = ch - 'a' + 10;
        else
            return "ERROR";

        if (digit >= base)
            return "ERROR";

        if (number > (ULLONG_MAX - digit) / base)
            return "ERROR";

        number = number * base + digit;
    }

    if (number > LLONG_MAX)
        return "ERROR";

    long long value = (long long)number;

    convert(value, 10, decimal);
    convert(value, 2, binary);
    convert(value, 8, octal);
    convert(value, 16, hexadecimal);

    snprintf(result, sizeof(result), "%s|%s|%s|%s",
             decimal, binary, octal, hexadecimal);

    return result;
}

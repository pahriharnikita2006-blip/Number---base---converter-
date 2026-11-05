

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getDecimal(char num[], int base, long long *value)
{
    char *end;
    long long result = strtoll(num, &end, base);

    if (num[0] == '\0' || *end != '\0')
        return 0;

    if (result < 0)
        return 0;

    *value = result;
    return 1;
}

void convert(long long number, int base, char output[])
{
    char digits[] = "0123456789ABCDEF";
    char temp[100];
    int i = 0;

    if (number == 0)
    {
        strcpy(output, "0");
        return;
    }

    while (number > 0)
    {
        temp[i++] = digits[number % base];
        number = number / base;
    }

    int j = 0;
    while (i > 0)
        output[j++] = temp[--i];

    output[j] = '\0';
}

int main()
{
    char input[100];
    char decimal[100];
    char binary[100];
    char octal[100];
    char hexadecimal[100];

    int choice;
    long long number;

    printf("\n==============================\n");
    printf("   NUMBER BASE CONVERTER\n");
    printf("==============================\n");

    printf("\nSelect Input Number System:\n");
    printf("1. Decimal\n");
    printf("2. Binary\n");
    printf("3. Octal\n");
    printf("4. Hexadecimal\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    int base;

    switch (choice)
    {
        case 1: base = 10; break;
        case 2: base = 2; break;
        case 3: base = 8; break;
        case 4: base = 16; break;
        default:
            printf("Invalid choice!");
            return 0;
    }

    printf("Enter number: ");
    scanf("%99s", input);

    if (!getDecimal(input, base, &number))
    {
        printf("Invalid number for selected base!");
        return 0;
    }

    convert(number, 10, decimal);
    convert(number, 2, binary);
    convert(number, 8, octal);
    convert(number, 16, hexadecimal);

    printf("\n========== RESULTS ==========\n");
    printf("Decimal      : %s\n", decimal);
    printf("Binary       : %s\n", binary);
    printf("Octal        : %s\n", octal);
    printf("Hexadecimal  : %s\n", hexadecimal);

    return 0;
}

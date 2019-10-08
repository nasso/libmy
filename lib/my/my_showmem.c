/*
** EPITECH PROJECT, 2019
** my_showmem
** File description:
** Prints a memory dump.
*/

static const char   PRINTABLE_CHARS_START = 32;
static const char   *HEX_DIGITS = "0123456789abcdef";

void    my_putchar(char);

static void puthex(int c, int digits)
{
    if (digits > 1)
        puthex(c / 16, digits - 1);
    my_putchar(HEX_DIGITS[c % 16]);
}

static void putline_row(char const *str, int n)
{
    int     i;

    for (i = 0; i < 16 && i < n; i++) {
        puthex(str[i], 2);
        if (i % 2)
            my_putchar(' ');
    }
    for (; i < 16; i++) {
        my_putchar(' ');
        my_putchar(' ');
        if (i % 2)
            my_putchar(' ');
    }
}

static int  isprint(char c)
{
    return (c >= PRINTABLE_CHARS_START);
}

static void putline(char const *str, int n)
{
    int     i;

    for (i = 0; i < 16 && i < n; i++)
        my_putchar(isprint(str[i]) ? str[i] : '.');
}

int     my_showmem(char const *str, int size)
{
    for (int row = 0; row < size; row += 16) {
        puthex(row, 8);
        my_putchar(':');
        my_putchar(' ');
        putline_row(&str[row], size - row);
        my_putchar(' ');
        putline(&str[row], size - row);
        my_putchar('\n');
    }
    return (0);
}

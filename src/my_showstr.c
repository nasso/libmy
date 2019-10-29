/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** Prints a string with non-printable characters represented hexadecimally.
*/

static const char   PRINTABLE_CHARS_START = 32;
static const char   *HEX_DIGITS = "0123456789abcdef";

void    my_putchar(char);

static void puthex(char c)
{
    my_putchar('\\');
    my_putchar(HEX_DIGITS[c / 16]);
    my_putchar(HEX_DIGITS[c % 16]);
}

int     my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= PRINTABLE_CHARS_START)
            my_putchar(str[i]);
        else
            puthex(str[i]);
    }
    return (0);
}

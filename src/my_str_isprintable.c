/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** Returns 1 if the given string contains only printable characters.
*/

static const char   PRINTABLE_CHARS_START = 32;

static int  isprintable(char c)
{
    return c >= PRINTABLE_CHARS_START;
}

int     my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isprintable(str[i]))
            return (0);
    return (1);
}

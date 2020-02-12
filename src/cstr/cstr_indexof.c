/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** cstr_indexof
*/

int my_cstr_indexof(const char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (i);
    return (-1);
}
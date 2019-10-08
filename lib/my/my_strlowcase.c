/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** Makes the given string lowercase.
*/

static const char   UPPER_TO_LOWER_OFFSET = 'a' - 'A';

char    *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += UPPER_TO_LOWER_OFFSET;
    return (str);
}

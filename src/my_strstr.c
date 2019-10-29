/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Implementation of strstr.
*/

int     my_strncmp(char const*, char const*, int);

char    *my_strstr(char *str, char const *to_find)
{
    int len;

    for (len = 0; to_find[len] != '\0'; len++) {}
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_strncmp(&str[i], to_find, len))
            return (&str[i]);
    return (0);
}

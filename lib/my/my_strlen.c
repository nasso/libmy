/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Returns the number of characters found in the string passed as parameter.
*/

int     my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {}
    return (i);
}

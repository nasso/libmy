/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** Swaps the two variables pointed by the given arguments.
*/

void    my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

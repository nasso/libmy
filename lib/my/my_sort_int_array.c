/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Sorts an int array in ascending order.
*/

void    my_swap(int*, int*);

static void sort_pair(int *a, int *b)
{
    if (*a > *b)
        my_swap(a, b);
}

void    my_sort_int_array(int *array, int size)
{
    for (int last_i = size - 1; last_i > 0; last_i--)
        for (int i = 0; i < last_i; i++)
            sort_pair(&array[i], &array[i + 1]);
}

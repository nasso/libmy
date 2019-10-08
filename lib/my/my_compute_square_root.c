/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Computes the square root of an integer.
*/

static int      search(int nb, int low, int high)
{
    int mid;
    int midmid;

    if (low == high)
        return (low * low == nb ? low : 0);
    if (low + 1 == high)
        return (0);
    mid = (low + high) / 2;
    midmid = mid * mid;
    if (midmid < nb)
        return (search(nb, mid, high));
    if (midmid > nb)
        return (search(nb, low, mid));
    return (mid);
}

int     my_compute_square_root(int nb)
{
    if (nb <= 3)
        return (nb == 1);
    return (search(nb, 0, nb));
}

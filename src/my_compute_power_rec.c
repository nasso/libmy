/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Recursively computes nb^p.
*/

int     my_compute_power_rec(int nb, int p)
{
    if (p <= 0)
        return (p == 0);
    if (nb == 0)
        return (0);
    return nb * my_compute_power_rec(nb, p - 1);
}

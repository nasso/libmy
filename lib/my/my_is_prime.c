/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Returns 1 if the given number is prime, 0 otherwise.
*/

int     my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (long i = 2; i * i <= nb; i++)
        if (nb % i == 0)
            return (0);
    return (1);
}

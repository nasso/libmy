/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Find the smallest prime greater than the given number.
*/

int     my_is_prime(int);

int     my_find_prime_sup(int n)
{
    while (!my_is_prime(n))
        n++;
    return (n);
}

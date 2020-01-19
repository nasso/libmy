/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_open
*/

#include <fcntl.h>
#include "my.h"

int my_open(const char *pathname, int flags)
{
#if defined(MY_ALLOW_FUN_OPEN)
    return (open(pathname, flags));
#else
    (void)(pathname);
    (void)(flags);
    return (-1);
#endif
}
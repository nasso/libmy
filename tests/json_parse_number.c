/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_parse_string
*/

#include "my/json.h"
#include <criterion/criterion.h>

Test(json, parse_number, .timeout = 1.0)
{
    const char *json = json_clean("8889");
    int i = 0;
    json_t *parsed_str = json_parse_number(json, &i);

    cr_assert_eq(parsed_str->u.nb, 8889);
}
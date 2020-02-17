/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_parse_string
*/

#include "my/json.h"
#include <criterion/criterion.h>

Test(json, parse_bool, .timeout = 1.0)
{
    const char *json = json_clean("true");
    int i = 0;
    json_t *parsed_str = json_parse_bool(json, &i);

    cr_assert_eq(parsed_str->u.bval, true);
}

Test(json, parse_false_bool, .timeout = 1.0)
{
    const char *json = json_clean("false");
    int i = 0;
    json_t *parsed_str = json_parse_bool(json, &i);

    cr_assert_eq(parsed_str->u.bval, false);
}

Test(json, parse_inv_bool, .timeout = 1.0)
{
    const char *json = json_clean("dqz");
    int i = 0;
    json_t *parsed_str = json_parse_bool(json, &i);

    cr_assert(!parsed_str);
}
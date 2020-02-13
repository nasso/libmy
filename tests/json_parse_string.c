/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_parse_string
*/

#include "my/json.h"
#include <criterion/criterion.h>

Test(json, parse_string, .timeout = 1.0)
{
    const char *json = json_clean("\"test string\"");
    int i = 0;
    json_t *parsed_str = json_parse_string(json, &i);

    cr_assert_str_eq(parsed_str->u.str, "test string");
}

Test(json, parse_empty_string, .timeout = 1.0)
{
    const char *json = json_clean("\"\"");
    int i = 0;
    json_t *parsed_str = json_parse_string(json, &i);

    cr_assert_str_eq(parsed_str->u.str, "");
}
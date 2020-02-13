/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_parse_array
*/

#include "my/json.h"
#include <criterion/criterion.h>

Test(json, parse_array, .timeout = 1.0)
{
    const char *json = json_clean("[\n\t\"hello\", \"world\"\n]");
    int i = 0;
    json_t *parsed_array = json_parse_array(json, &i);

    cr_assert_eq(parsed_array->u.array.len, 2);
    cr_assert_str_eq(parsed_array->u.array.data[0]->u.str, "hello");
    cr_assert_str_eq(parsed_array->u.array.data[1]->u.str, "world");
}

Test(json, parse_array_array, .timeout = 1.0)
{
    const char *json = json_clean("[\n\t[\"test\"], [\"world\"]\n]");
    int i = 0;
    json_t *parsed_array = json_parse_array(json, &i);

    cr_assert_eq(parsed_array->u.array.len, 2);
    cr_assert_eq(parsed_array->u.array.data[0]->type, JSON_ARRAY);
    cr_assert_eq(parsed_array->u.array.data[1]->type, JSON_ARRAY);
    cr_assert_eq(parsed_array->u.array.data[0]->u.array.len, 1);
    cr_assert_eq(parsed_array->u.array.data[1]->u.array.len, 1);
    cr_assert_str_eq(parsed_array->u.array.data[0]->u.array.data[0]->u.str,
    "test");
    cr_assert_str_eq(parsed_array->u.array.data[1]->u.array.data[0]->u.str, 
    "world");
}

Test(json, parse_array_one, .timeout = 1.0)
{
    const char *json = json_clean("[\n\t[\"test\"]\n]");
    int i = 0;
    json_t *parsed_array = json_parse_array(json, &i);

    cr_assert_eq(parsed_array->u.array.len, 1);
    cr_assert_eq(parsed_array->u.array.data[0]->type, JSON_ARRAY);
    cr_assert_eq(parsed_array->u.array.data[0]->u.array.len, 1);
    cr_assert_str_eq(parsed_array->u.array.data[0]->u.array.data[0]->u.str,
    "test");
}

Test(json, parse_empty_array, .timeout = 1.0)
{
    const char *json = json_clean("[\n\n]");
    int i = 0;
    json_t *parsed_array = json_parse_array(json, &i);

    cr_assert_eq(parsed_array->u.array.len, 0);
}
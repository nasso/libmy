/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_clean
*/

#include "my/json.h"
#include <criterion/criterion.h>

Test(json, clean_input, .timeout = 1.0)
{
    const char *raw_json = "{\n\t\"value\":\"data\"\n}";
    const char *cleaned_json = "{\"value\":\"data\"}";
    char *json = json_clean(raw_json);

    cr_assert_str_eq(json, cleaned_json);
    free(json);
}

Test(json, clean_input_with_space_values, .timeout = 1.0)
{
    const char *raw_json = "{ \n\t\"value lol\":\"data\"\n}";
    const char *cleaned_json = "{\"value lol\":\"data\"}";
    char *json = json_clean(raw_json);

    cr_assert_str_eq(json, cleaned_json);
    free(json);
}
/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_create
*/

#include <criterion/criterion.h>
#include "my/json.h"

Test(json, create_object, .timeout = 1.0)
{
    json_t *new_object = json_create_object();

    cr_assert_eq(new_object->type, JSON_OBJECT);
    free(new_object);
}

Test(json, create_array, .timeout = 1.0)
{
    json_t *new_object = json_create_array();

    cr_assert_eq(new_object->type, JSON_ARRAY);
    free(new_object);
}

Test(json, create_null, .timeout = 1.0)
{
    json_t *new_object = json_create_null();

    cr_assert_eq(new_object->type, JSON_NULL);
    free(new_object);
}

Test(json, create_number, .timeout = 1.0)
{
    json_t *new_object = json_create_number(6969);

    cr_assert_eq(new_object->type, JSON_NUMBER);
    cr_assert_eq(new_object->u.nb, 6969);
    free(new_object);
}

Test(json, create_string, .timeout = 1.0)
{
    json_t *new_object = json_create_string("Salut les zouzous.");

    cr_assert_eq(new_object->type, JSON_STRING);
    cr_assert_str_eq(new_object->u.str, "Salut les zouzous.");
    free(new_object);
}
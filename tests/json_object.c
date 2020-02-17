/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** json_create
*/

#include <criterion/criterion.h>
#include "my/json.h"

Test(json, get_object_data, .timeout = 1.0)
{
    json_t *new_object = json_create_object();
    json_t *num_sub_obj = json_create_number(2727930);

    cr_assert_eq(new_object->type, JSON_OBJECT);
    json_object_set(new_object, "test_number", num_sub_obj);
    cr_assert_eq(json_object_get(new_object, "test_number")->type, JSON_NUMBER);
    cr_assert_eq(json_object_get(new_object, "test_number")->u.nb, 2727930);
    free(new_object);
}
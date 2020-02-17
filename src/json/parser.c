/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** parser
*/

#include "my/my.h"
#include "my/cstr.h"
#include "my/json.h"

const char *json_identifiers = "\"[]{},";
const char *json_separators = "\t \n\r";

/* 
    This function will try to "guess" an object type based on the prepending
    token. Maybe not the best solution to do it, certainly not the most 
    elegant.
*/
static i32_t guess_object_type(const char *json_str, int i)
{
    if ((json_str[i] >= '0' && json_str[i] <= '9') || 
    (json_str[i] == '-' && (json_str[i + 1] >= '0' && json_str[i + 1] <= '9')))
        return (JSON_NUMBER);
    if (my_cstrncmp(json_str + i, "null", 4) == 0)
        return (JSON_NULL);
    if (my_cstrncmp(json_str + i, "false", 5) == 0
    || my_cstrncmp(json_str + i, "true", 4) == 0)
        return (JSON_BOOL);
    switch (json_str[i]) {
        case '[':
            return (JSON_ARRAY);
        case '{':
            return (JSON_OBJECT);
        default:
            return (JSON_STRING);
    }
}

json_t *json_parse_entity(const char *json_str, int *i)
{
    switch (guess_object_type(json_str, *i)) {
        case JSON_OBJECT:
            return (json_parse_object(json_str, i));
        case JSON_ARRAY:
            return (json_parse_array(json_str, i));
        case JSON_STRING:
            return (json_parse_string(json_str, i));
        case JSON_NUMBER:
            return (json_parse_number(json_str, i));
        case JSON_BOOL:
            return (json_parse_bool(json_str, i));
        case JSON_NULL:
            return (json_parse_null(json_str, i));
        default:
            return (NULL);
    }
    return (NULL);
}

json_t *json_parse(const char *json_str)
{
    const char *clean_str = json_clean(json_str);
    int i = 0;

    return (json_parse_entity(clean_str, &i));
}
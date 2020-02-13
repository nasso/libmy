/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** array
*/

#include "my/json.h"
#include "my/cstr.h"
#include "my/my.h"

static int get_string_len(const char *json_str, int i)
{
    int ret_length = 0;

    for (; json_str[i] != '\0' && json_str[i] != '\"'; i++)
        ret_length++;
    return (ret_length);
}

json_t *json_parse_string(const char *json_str, int *i)
{
    json_t *obj = NULL;
    char *parsed_str = NULL;
    int str_len = 0;
    int j = 0;

    if (*(json_str++) != '\"')
        return (NULL);
    str_len = get_string_len(json_str, *i);
    parsed_str = my_malloc(sizeof(char) * str_len);
    if (!parsed_str)
        return (NULL);  
    for (; j < str_len; j++)
        parsed_str[j] = json_str[(*i)++];   
    parsed_str[j] = '\0';
    obj = json_create_string(parsed_str);
    my_free(parsed_str);
    return (obj);
}
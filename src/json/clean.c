/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** clean
*/

#include "my/cstr.h"
#include "my/json.h"

char *json_clean(const char *input_str)
{
    char *dup_input = my_cstrdup(input_str);
    bool is_in_value = false; 
    int writer = 0;
    int reader = 0;

    while (dup_input[reader]) {
        if (dup_input[reader] == '\"') {
            is_in_value = !is_in_value;
            dup_input[writer++] = dup_input[reader];
        }
        else if (!(!is_in_value && my_cstr_indexof(json_separators, 
        dup_input[reader]).v != -1))
            dup_input[writer++] = dup_input[reader];
        reader++;
    }
    dup_input[writer] = '\0';
    return (dup_input);
}
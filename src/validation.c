//
// Created by Alya Karma on 26.06.2020.
//

#include "computorv1.h"

//TODO set_argument
static void set_argument(char *expression, int *value, int *i, int equal_sign) {

}

static int  set_arguments(char *expression, int **values) {
    expression += skip_spaces(expression);
    if ()
}

static int  validate_expression(char *expression) {
    while (expression && *expression) {
        if (!(ft_isdigit(*expression)) && *expression != ' ' &&
            *expression != '-' && *expression != '+' &&
            *expression != '=' && *expression != '^' &&
            *expression != 'x' && *expression != 'X')
            return (0);
        expression++;
    }
    return (1);
}

int         validation(char *expression, int ***values) {
    if (validate_expression(expression) == 0)
        return (0);
    *values = (int **) ft_memalloc(sizeof(int **) * 3);
    if (set_arguments(expression, *values))
        return (0);//TODO free_memory if invalid
    return (1);
}
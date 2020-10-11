//
// Created by Alya Karma on 26.06.2020.
//

#include "computorv1.h"

//TODO set_argument
static void set_argument(char *expression, t_value *value, int *i, int equal_sign) {

}

static int set_arguments(char *expression, t_value **values) {

}

int validation(char *expression, t_value ***values) {
    *values = (t_value**) ft_memalloc(sizeof(t_value**) * 3);
    if (set_arguments(expression, *values))
        return (1);//TODO free_memory if invalid
    return (0);
}
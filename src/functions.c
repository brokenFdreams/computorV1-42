//
// Created by voult on 11.10.2020.
//

#include "computorv1.h"

int       skip_spaces(const char* expression)
{
    int i;

    i = 0;
    while (expression[i] == ' ')
        i++;
    return (i);
}
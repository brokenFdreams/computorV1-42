//
// Created by voult on 14.10.2020.
//

#include "computorv1.h"

void ft_error(char *str)
{
	ft_putstr(str);
	ft_putendl(" I can't solve.\n");
	exit(0);
}

void ft_error_f(char *str, int **values, int **degrees)
{
	if (values && *values)
		free(*values);
	if (degrees && *degrees)
		free(*degrees);
	ft_error(str);
}

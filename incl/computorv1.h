#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"
# include <stdio.h>

void set_arguments(char *expression, int *values, int mindegree, int *degrees);
void resolution(int *values, int *degrees);

void remove_all_spaces(char *expression);
void write_reduced_form(int *values, int *degrees);
void free_memory(int **values, int **degrees);
void ft_error(char *str);
void ft_error_f(char *str, int **values, int **degrees);

double ft_sqrtf(int x);

#endif
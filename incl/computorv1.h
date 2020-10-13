#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"

typedef struct s_solution
{
	float discriminant;
	int numberofsolutions;
	float first_solution;
	float second_solution;
} t_solution;

void set_arguments(char *expression, int *values, int mindegree);

void resolution(int *values, t_solution *solution);

void remove_all_spaces(char *expression);

void write_reduced_form(int *values, int *degrees);

void ft_error(char *str);

void free_memory(int **values, t_solution **solution, int **degrees);

//void		solution(t_value** values, t_solution* output);
//
//void 		writer(t_solution* output);
//
//void		free_memory(t_value*** values, t_solution** output);

#endif
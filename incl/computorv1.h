#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"

typedef struct	s_output {
	int 		max_degree;
    float 		discriminant;
	int 		numberofsolutions;
	float 		first_solution;
    float 		second_solution;
}				t_output;

void		set_arguments(char *expression, int **values);

void		remove_all_spaces(char *expression);
void		ft_error(char *str);

//void		solution(t_value** values, t_output* output);
//
//void 		writer(t_output* output);
//
//void		free_memory(t_value*** values, t_output** output);

#endif
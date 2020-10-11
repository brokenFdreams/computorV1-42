#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"

typedef struct	s_value {
	int 		value;
	int			xdegree;
}				t_value;

typedef struct	s_output {
	char		*reducedform;
	int 		max_degree;
	int 		discriminant_sign;
	int 		numberofsolutions;
	int 		first_solution;
	int 		second_solution;
}				t_output;

int 		validation(char* expression, t_value*** values);

int         skip_spaces(const char* expression);

//void		solution(t_value** values, t_output* output);
//
//void 		writer(t_output* output);
//
//void		free_memory(t_value*** values, t_output** output);

#endif
#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"

typedef struct	s_output {
	char		*reducedform;
	int 		max_degree;
    float 		discriminant_sign;
	int 		numberofsolutions;
	float 		first_solution;
    float 		second_solution;
}				t_output;

int 		validation(char* expression, int*** values);

int         skip_spaces(const char* expression);

//void		solution(t_value** values, t_output* output);
//
//void 		writer(t_output* output);
//
//void		free_memory(t_value*** values, t_output** output);

#endif
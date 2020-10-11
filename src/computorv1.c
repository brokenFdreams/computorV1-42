//
// Created by Alya Karma on 25.06.2020.
//

#include "computorv1.h"

static int	start_progress(char* expression) {
	int		    **values;
	t_output	*output;
	int         degree;

	degree = validation(expression, &values);
	if (degree == -1)
		return (0);
    if (degree > 2) {
        ft_putendl("The polynomial degree is stricly greater than 2, I can't solve.");
        return (degree);
    }
//	solution(values, output);
//	writer(output);
//	free_memory(&values, &output);
	return (1);
}

int			main(int argc, char** argv) {
    int    check;

	if (argc == 2)
		check = start_progress(argv[1]);
	if (argc != 2 || check == 0) {
		ft_putendl("Usage: ./computor \"some reduce\"");
		ft_putendl("Example: ./computor \"5*X^0+4*X^1+6*X^2=3*X^2\"");
	}
	return (0);
}

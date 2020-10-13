//
// Created by Alya Karma on 25.06.2020.
//

#include "computorv1.h"

static void validation(char *expression)
{
	int countequals;

	countequals = 0;
	while (expression && *expression)
	{
		if (*expression == '=')
			countequals++;
		else if (!(ft_isdigit(*expression)) &&
				 *expression != '-' && *expression != '+' &&
				 *expression != '^' && *expression != '*' &&
				 *expression != 'x' && *expression != 'X')
			ft_error("There's some unexpected sign in expression");
		expression++;
	}
	if (countequals > 1)
		ft_error("There's more, then one =. I can't solve.");
}

static void	start_progress(char* expression) {
	int		    *values;
	t_output	*output;
	int         degree;

	remove_all_spaces(expression);
	validation(expression);
	set_arguments(expression, &values);
//	solution(values, output);
//	writer(output);
//	free_memory(&values, &output);
}

int			main(int argc, char** argv) {
	if (argc != 2 || ft_strequ(argv[1], "-u")) {
		ft_putendl("Usage: ./computor \"some reduce\"");
		ft_putendl("Example: ./computor \"5*X^0+4*X^1+6*X^2=3*X^2\"");
	}
	else
        start_progress(argv[1]);
    return (0);
}

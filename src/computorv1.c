//
// Created by Alya Karma on 25.06.2020.
//

#include "computorv1.h"

static int	start_progress(char* expression) {
	t_value		**values;
	t_output	*output;

	if (validation(expression, &values) == 1)
		return (1);
//	solution(values, output);
//	writer(output);
//	free_memory(&values, &output);
	return (0);
}

int			main(int argc, char** argv) {
    int    check;

	check = 1;
	if (argc == 2)
		check = start_progress(argv[1]);
	if (argc != 2 || check) {
		ft_putendl("Usage: ./computor \"some reduce\"");
		ft_putendl("Example: ./computor \"5 + 4 * X + X^2 = X^2\"");
	}
	return (0);
}

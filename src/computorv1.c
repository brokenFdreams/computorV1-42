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

static int *get_degrees(const char *expression)
{
	int i;
	int *degrees;
	int tmp;

	degrees = (int *) ft_memalloc(sizeof(int) * 2);
	degrees[0] = 0;
	degrees[1] = 0;
	i = -1;
	while (expression[++i])
	{
		if (expression[i - 1] == 'x' || expression[i - 1] == 'X')
		{
			if (expression[i] == '^')
				tmp = ft_atoi(expression + i + 1);
			else
				tmp = 1;
			degrees[0] = degrees[0] < tmp ? degrees[0] : tmp;
			degrees[1] = degrees[1] > tmp ? degrees[1] : tmp;
		}
	}
	return degrees;
}

static void start_progress(char *expression)
{
	int *values;
	int *degrees;

	remove_all_spaces(expression);
	validation(expression);
	degrees = get_degrees(expression);
	values = (int*)ft_memalloc(sizeof(int) * (degrees[1] + 1 - degrees[0]));
	set_arguments(expression, values, degrees[0], degrees);
	write_reduced_form(values, degrees);
	if (degrees[1] > 2)
		ft_error_f("The polynomial degree is stricly greater than 2.",
				   &values, &degrees);
	resolution(values, degrees);
	free_memory(&values, &degrees);
}

int main(int argc, char **argv)
{
	if (argc != 2 || ft_strequ(argv[1], "-u"))
	{
		ft_putendl("Usage: ./computor \"some reduce\"");
		ft_putendl("Example: ./computor \"5*X^0+4*X^1+6*X^2=3*X^2\"");
	} else
		start_progress(argv[1]);
	return (0);
}

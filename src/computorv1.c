/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:25 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:52:24 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static void	validation(char *expression)
{
	int	countequals;

	countequals = 0;
	while (expression && *expression)
	{
		if (*expression == '=')
			countequals++;
		else if (!(ft_isdigit(*expression))
			&& *expression != '-' && *expression != '+'
			&& *expression != '^' && *expression != '*'
			&& *expression != 'x' && *expression != 'X')
			ft_error("There's some unexpected sign in expression");
		expression++;
	}
	if (countequals > 1)
		ft_error("There's more, then one =. I can't solve.");
}

static int	*get_degrees(const char *expression)
{
	int	i;
	int	*degrees;
	int	tmp;

	degrees = (int *)ft_memalloc(sizeof(int) * 2);
	degrees[0] = 0;
	degrees[1] = 0;
	i = -1;
	while (expression[++i])
	{
		if (expression[i] == 'x' || expression[i] == 'X')
		{
			if (expression[i + 1] && expression[i + 1] == '^')
				tmp = ft_atoi(expression + i + 2);
			else
				tmp = 1;
			if (degrees[0] >= tmp)
				degrees[0] = tmp;
			if (degrees[1] <= tmp)
				degrees[1] = tmp;
		}
	}
	return (degrees);
}

static void	start_progress(char *expression)
{
	t_arguments	*arguments;

	remove_all_spaces(expression);
	validation(expression);
	arguments = (t_arguments *) ft_memalloc(sizeof(t_arguments));
	arguments->degrees = get_degrees(expression);
	arguments->values = (int *) ft_memalloc(sizeof(int)
			* (arguments->degrees[1] + 1 - arguments->degrees[0]));
	set_arguments(expression, arguments->degrees[0], arguments);
	write_reduced_form(arguments);
	if (arguments->degrees[1] > 2)
		ft_error_f("The polynomial degree is stricly greater than 2.",
			&arguments);
	resolution(arguments->values, arguments->degrees);
	free_memory(&arguments);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_strequ(argv[1], "-u"))
	{
		ft_putendl("Usage: ./computor \"some reduce\"");
		ft_putendl("Example: ./computor \"5*X^0+4*X^1+6*X^2=3*X^2\"");
	}
	else
		start_progress(argv[1]);
	return (0);
}

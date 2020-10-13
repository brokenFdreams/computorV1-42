//
// Created by voult on 11.10.2020.
//

#include "computorv1.h"

static void write_value(int value, int degree, int mindegree)
{
	if (value != 0)
	{
		if (degree == mindegree)
			ft_putnbr(value);
		else if (value < 0)
		{
			ft_putstr(" - ");
			ft_putnbr(value * -1);
		} else
		{
			ft_putstr(" + ");
			ft_putnbr(value);
		}
		ft_putstr(" * X^");
		ft_putnbr(degree);
	}
}

void write_reduced_form(int *values, int *degrees)
{
	int i;
	int degreecounter;
	int mindegree;
	int maxdegree;

	ft_putstr("Reduced form: ");
	i = 0;
	degreecounter = degrees[0];
	mindegree = 0;
	maxdegree = 0;
	while (degreecounter < degrees[1])
	{
		if (degreecounter < 0 && values[i] != 0)
			mindegree = mindegree < degreecounter ? mindegree : degreecounter;
		else if (values[i] != 0)
			maxdegree = degreecounter;
		write_value(values[i++], degreecounter++, mindegree);
	}
	ft_putendl(" = 0");
	ft_putstr("Polynomial degree: ");
	ft_putendl(ft_itoa(maxdegree));
	if (maxdegree > 2)
		ft_error("The polynomial degree is stricly greater than 2.");
	else if (mindegree < 0)
		ft_error("Expression contains negative x degree.");
}

void remove_all_spaces(char *expression)
{
	int i;
	int j;

	i = -1;
	while (expression[++i])
	{
		if (expression[i] == ' ')
		{
			j = i;
			while (expression[++j])
				expression[j - 1] = expression[j];
			expression[j - 1] = '\0';
			i--;
		}
	}
}

void free_memory(int **values, t_solution **solution, int **degrees)
{
	if (values && *values)
		free(*values);
	if (degrees && *degrees)
		free(*degrees);
	if (solution && *solution)
		free(*solution);
}

void ft_error(char *str)
{
	ft_putstr(str);
	ft_putendl(" I can't solve.\n");
	exit(0);
}
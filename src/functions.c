/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:54 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:47:05 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void	write_value(int value, int degree, int mindegree)
{
	if (value != 0)
	{
		if (degree == mindegree)
			ft_putnbr(value);
		else if (value < 0)
		{
			ft_putstr(" - ");
			ft_putnbr(value * -1);
		}
		else
		{
			ft_putstr(" + ");
			ft_putnbr(value);
		}
		ft_putstr(" * X^");
		ft_putnbr(degree);
	}
}

void	write_reduced_form(t_arguments *arguments)
{
	int	i;
	int	degreecounter;
	int	mindegree;
	int	maxdegree;

	ft_putstr("Reduced form: ");
	i = 0;
	degreecounter = arguments->degrees[i];
	mindegree = 2;
	maxdegree = 0;
	while (degreecounter <= arguments->degrees[1])
	{
		if (arguments->values[i] != 0 && mindegree > degreecounter)
			mindegree = degreecounter;
		if (arguments->values[i] != 0)
			maxdegree = degreecounter;
		write_value(arguments->values[i++], degreecounter++, mindegree);
	}
	ft_putstr(" = 0 \nPolynomial degree: ");
	ft_putnbr(maxdegree);
	ft_putendl("");
	if (mindegree < 0)
		ft_error_f("Expression contains negative x degree.",
			&arguments);
	arguments->degrees[1] = maxdegree;
}

void	remove_all_spaces(char *expression)
{
	int	i;
	int	j;

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

void	free_memory(t_arguments **arguments)
{
	if (arguments && *arguments)
	{
		if ((*arguments)->values)
			free((*arguments)->values);
		if ((*arguments)->degrees)
			free((*arguments)->degrees);
		free(*arguments);
	}
}

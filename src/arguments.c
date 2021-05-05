/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:13 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:50:18 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static int	get_sign(const char *expression, const int *start)
{
	if (expression[*start] == '=')
		return (-1);
	return (1);
}

static int	get_value(char *expression, int *start, int wasequal)
{
	int	value;
	int	sign;

	sign = get_sign(expression, start);
	if (expression[*start] == '=')
		(*start)++;
	if (expression[*start] == '-'
		|| (wasequal && expression[*start - 1] != '='))
		sign *= -1;
	if (expression[*start] == '-' || expression[*start] == '+')
		(*start)++;
	if (expression[*start] == 'x' || expression[*start] == 'X')
		return (sign);
	value = ft_atoi(expression + *start) * sign;
	while (ft_isdigit(expression[*start]))
		(*start)++;
	if (expression[*start] == '*' && ft_isdigit(expression[*start + 1]))
	{
		(*start)++;
		value *= get_value(expression, start, wasequal);
	}
	if (sign == -1 && value > -1)
		return (value * sign);
	return (value);
}

static int	get_degree(const char *expression, int start, int end,
					t_arguments *arguments)
{
	int	degree;

	if (expression[start] == '*')
		start++;
	if (expression[start] != 'x' && expression[start] != 'X')
		ft_error_f("There's no 'x' or 'X' when its expected.", &arguments);
	if (++start == end)
		return (1);
	if (expression[start] != '^')
		ft_error_f("There's unexpected characters after 'x'.", &arguments);
	if (ft_isdigit(expression[++start]))
		degree = ft_atoi(expression + start);
	else if (expression[start] == '-' && ft_isdigit(expression[start + 1]))
	{
		degree = ft_atoi(expression + start);
		start++;
	}
	else
		ft_error_f("There's no digit after '^'.", &arguments);
	while (ft_isdigit(expression[start]))
		start++;
	if (start != end)
		ft_error_f("Unexpected character after 'x' degree.", &arguments);
	return (degree);
}

static int	get_next_operator(const char *expression, int i, int *wasequal)
{
	if (expression[i] == '=')
	{
		*wasequal = 1;
		i++;
	}
	if (expression[i] == '+' || expression[i] == '-')
		i++;
	if (!(ft_isdigit(expression[i])) && expression[i] != 'x'
		&& expression[i] != 'X')
		return (0);
	while ((expression[i] && expression[i] != '+'
			&& expression[i] != '-' && expression[i] != '=')
		|| ((expression[i] == '-' || expression[i] == '+')
			&& expression[i - 1] == '^'))
		i++;
	return (i);
}

void	set_arguments(char *expression, int mindegree,
					t_arguments *arguments)
{
	int	start;
	int	end;
	int	wasequal;
	int	value;

	start = 0;
	end = 0;
	wasequal = 0;
	while (expression[end])
	{
		end = get_next_operator(expression, start, &wasequal);
		if (end == 0)
			ft_error_f(
				"There's no digit or 'x', when its expected.",
				&arguments);
		value = get_value(expression, &start, wasequal);
		if (start == end)
			arguments->values[0 - mindegree] += value;
		else
			arguments->values[get_degree(expression, start, end, arguments)
				- mindegree] += value;
		start = end;
	}
}

//
// Created by Alya Karma on 26.06.2020.
//

#include "computorv1.h"

static int get_value(char *expression, int *start, int wasequal)
{
	int value;
	int sign;

	sign = 1;
	if (expression[*start] == '-')
		sign = -1;
	if (wasequal)
		sign *= -1;
	if (expression[*start] == '-' || expression[*start] == '+' ||
		expression[*start] == '=')
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

static int get_degree(char *expression, int start, int end)
{
	int degree;

	if (start == end)
		return (0);
	if (expression[start] == '*')
		start++;
	if (expression[start] != 'x' && expression[start] != 'X')
		ft_error("There's no 'x' or 'X' when its expected.");
	if (++start == end)
		return (1);
	if (expression[start] != '^')
		ft_error("There's unexpected characters after 'x'.");
	if (ft_isdigit(expression[++start]))
		degree = ft_atoi(expression + start);
	else if (expression[start] == '-' && ft_isdigit(expression[start + 1]))
	{
		degree = ft_atoi(expression + start);
		start++;
	}
	else
		ft_error("There's no digit after '^'.");
	while (ft_isdigit(expression[start]))
		start++;
	if (start != end)
		ft_error("Unexpected character after 'x' degree.");
	return (degree);
}

static int get_next_operator(const char *expression, int i, int *wasequal)
{
	if (expression[i] == '=')
		*wasequal = 1;
	if (expression[i] == '+' || expression[i] == '-' ||
		expression[i] == '=')
		i++;
	if (!(ft_isdigit(expression[i])) && expression[i] != 'x' &&
		expression[i] != 'X')
		ft_error("There's no digit or 'x', when its expected.");
	while ((expression[i] && expression[i] != '+' &&
			expression[i] != '-' && expression[i] != '=') ||
		   ((expression[i] == '-' || expression[i] == '+') &&
			expression[i - 1] == '^'))
		i++;
	return (i);
}

void set_arguments(char *expression, int *values, int mindegree)
{
	int start;
	int end;
	int wasequal;
	int value;

	start = 0;
	end = 0;
	wasequal = 0;
	while (expression[end])
	{
		end = get_next_operator(expression, start, &wasequal);
		value = get_value(expression, &start, wasequal);
		values[get_degree(expression, start, end) - mindegree] += value;
		start = end;
	}
}

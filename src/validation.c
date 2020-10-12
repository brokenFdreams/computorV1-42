//
// Created by Alya Karma on 26.06.2020.
//

#include "computorv1.h"

//TODO set_argument
static int get_value(char *expression, int *start)
{
	int value;
	int sign;

	sign = 1;
	if (expression[*start] == '-' || expression[*start] == '=')
		sign = -1;
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
		value *= get_value(expression, start);
	}
	return (value);
}

static int set_argument(char *expression, int start, int end)
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
	if (!(ft_isdigit(expression[++start])))
		ft_error("There's no digit after '^'.");
	degree = ft_atoi(expression + start);
	if (degree > 2)
		ft_error("The polynomial degree is stricly greater than 2.");
	if (degree < 0)
		ft_error("The polynomial degree is stricly less than 0.");
	while (ft_isdigit(expression[start]))
		start++;
	if (start != end)
		ft_error("Unexpected character after 'x' degree.");
	return (degree);
}

static int get_next_operator(const char *expression, int i)
{
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

void	 set_arguments(char *expression, int **values)
{
	int start;
	int end;
	int len;
	int value;

	*values = (int *) ft_memalloc(sizeof(int) * 3);
	len = ft_strlen(expression);
	start = 0;
	while (len > 0)
	{
		end = get_next_operator(expression, start);
		len -= end - start;
		value = get_value(expression, &start);
		(*values)[set_argument(expression, start, end)] += value;
		start = end;
	}
}

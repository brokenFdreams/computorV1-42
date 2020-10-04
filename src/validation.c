//
// Created by Alya Karma on 26.06.2020.
//

#include "computorv1.h"

//TODO get_argument
static void	get_argument(char* expression, t_value* value, int* i, int equal_sign)
{

}

static int	get_arguments(char* expression, t_value** values)
{
	int	i;
	int	j;
	int equal_sign;

	i = 0;
	j = 0;
	equal_sign = 0;
	while (expression && expression[i++])
	{
		if (ft_isdigit(expression[i]) || expression[i] == 'x' ||
			expression[i] == 'X') {
			values[j] = (t_value *) ft_memalloc(sizeof(t_value));
			get_argument(expression + i, values[j++], &i, equal_sign);
		} else if (expression[i] == '=' && equal_sign == 1)
			return (1);
		else if (expression[i] == '=')
			equal_sign = 1;
	}
	return (!equal_sign);
}

static int	count_arguments(char* expression)
{
	int	len;

	len = 0;
	while (expression && *(expression++))
		if (ft_isdigit(*expression))
		{
			len++;
			//TODO FIX count
		}
	return (len);
}

int 		validation(char* expression, t_value*** values)
{
	int		len;

	len = count_arguments(expression);
	*values = (t_value**)ft_memalloc(sizeof(t_value**) * len);
	if (get_arguments(expression, *values))
		return (1);//TODO free_memory if invalid
	return (0);
}
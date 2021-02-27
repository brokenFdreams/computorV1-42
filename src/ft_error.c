/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:40 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 15:32:54 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	ft_putendl(" I can't solve.\n");
	exit(0);
}

void	ft_error_f(char *str, int **values, int **degrees)
{
	if (values && *values)
		free(*values);
	if (degrees && *degrees)
		free(*degrees);
	ft_error(str);
}

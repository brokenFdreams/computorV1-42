/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:21:05 by fsinged           #+#    #+#             */
/*   Updated: 2021/02/27 16:41:32 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"
# include <stdio.h>

typedef struct s_arguments
{
	int			*values;
	int			*degrees;
}				t_arguments;

void			set_arguments(char *expression, int mindegree,
					t_arguments *arguments);
void			resolution(int *values, int *degrees);
void			discriminant(int *values);

void			remove_all_spaces(char *expression);
void			write_reduced_form(t_arguments *arguments);
void			free_memory(t_arguments **arguments);
void			ft_error(char *str);
void			ft_error_f(char *str, t_arguments **arguments);

double			ft_sqrtf(int x);

#endif

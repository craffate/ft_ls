/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:04:44 by craffate          #+#    #+#             */
/*   Updated: 2017/02/12 16:43:52 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_parse(const char *s)
{
	int		i;

	i = 0;
	if (*s == '-' && *(s + 1))
		s++;
	else
	{
		ft_printf(USAGE);
		exit(EXIT_FAILURE);
	}
	while (*s)
	{
		if (*s != 'l' && *s != 'R' && *s != 'a' && *s != 'r' && *s != 't' &&
			*s != 'u' && *s != 'f')
		{
			ft_printf(USAGE);
			exit(EXIT_FAILURE);
		}
		i |= *s == 'l' ? LS_L : i;
		i |= *s == 'R' ? LS_CR : i;
		i |= *s == 'a' ? LS_A : i;
		i |= *s == 'r' ? LS_R : i;
		i |= *s == 't' ? LS_T : i;
		i |= *s == 'u' ? LS_U : i;
		i |= *s == 'd' ? LS_F : i;
		s++;
	}
	return (i);
}

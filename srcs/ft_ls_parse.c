/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:04:44 by craffate          #+#    #+#             */
/*   Updated: 2017/02/26 02:09:20 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	assign(const char c, int *i)
{
	*i |= c == 'l' ? LS_L : *i;
	*i |= c == 'R' ? LS_CR : *i;
	*i |= c == 'a' ? LS_A : *i;
	*i |= c == 'r' ? LS_R : *i;
	*i |= c == 't' ? LS_T : *i;
	*i |= c == 'u' ? LS_U : *i;
	*i |= c == 'f' ? LS_F : *i;
}

int			ft_ls_parse(const char *s)
{
	int		i;

	i = 0;
	if (*s == '-' && *(s + 1))
		s++;
	else
		error_handler(1, NULL);
	while (*s)
	{
		if (*s != 'l' && *s != 'R' && *s != 'a' && *s != 'r' && *s != 't' &&
			*s != 'u' && *s != 'f')
			error_handler(1, NULL);
		assign(*s, &i);
		s++;
	}
	i |= (i & LS_F) ? LS_A : i;
	return (i);
}

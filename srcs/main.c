/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:02:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/02 18:41:14 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;
	DIR				*d;

	i = 0;
	j = 1;
	ft_printf("{yellow}[ft_ls]{eoc}\n");
	if (ac == 1)
		ft_ls(create_struct("", "."), i);
	else
	{
		if (*av[1] == '-' && (i = ft_ls_parse(av[j])))
			j = 2;
		while (j != ac)
			ft_ls(create_struct(av[j++], ""), i);
	}
	return (0);
}

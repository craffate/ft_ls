/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:02:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/11 15:12:20 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	if (ac == 1 || (ac == 2 && *av[1] == '-'))
	{
		ac == 2 ? (i |= ft_ls_parse(av[1])) : 0;
		ft_printf("{yellow}[ft_ls]{eoc}\n");
		ft_ls(create_struct("", "."), i);
	}
	else
	{
		i |= ac > 3 ? MUL_ARGS : 0;
		if (*av[1] == '-' && (i |= ft_ls_parse(av[j])))
			j++;
		ft_printf("{yellow}[ft_ls]{eoc}\n");
		while (av[j])
			ft_ls(create_struct(av[j++], ""), i);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:02:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/26 00:25:52 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		error_handler(int i)
{
	if (i == 1)
	{
		write(2, USAGE, 58);
		exit(-1);
	}
	else
		perror("\x1b[33m[ft_ls]\x1b[0m");
}

int			main(int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	while (av[j] && *av[j] == '-')
		i |= ft_ls_parse(av[j++]);
	ft_printf("{yellow}[ft_ls]{eoc}\n");
	if (ac > (int)j + 1)
		i |= MUL_ARGS;
	if (!av[j])
		ft_ls(create_struct("", "."), i);
	while (av[j])
		ft_ls(create_struct(av[j++], ""), i);
	return (0);
}

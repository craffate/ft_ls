/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:02:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/26 01:31:19 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**ascii_sort(char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (av);
}

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
	char			**args;

	i = 0;
	j = 0;
	av++;
	args = ascii_sort(av);
	while (args[j] && *args[j] == '-')
		i |= ft_ls_parse(args[j++]);
	ft_printf("{yellow}[ft_ls]{eoc}\n");
	if (ac > (int)j + 1)
		i |= MUL_ARGS;
	if (!args[j])
		ft_ls(create_struct("", "."), i);
	while (args[j])
		ft_ls(create_struct(args[j++], ""), i);
	while (1)
		;
	return (0);
}

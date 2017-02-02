/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:02:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/02 15:00:34 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display(t_file *dir)
{
	S_ISSOCK((*dir).stat.st_mode) ?
	ft_printf("{white}%s{eoc}\t", (*dir).name) : 0;
	S_ISLNK((*dir).stat.st_mode) ?
	ft_printf("{yellow}%s{eoc}\t", (*dir).name) : 0;
	S_ISDIR((*dir).stat.st_mode) ?
	ft_printf("{cyan}%s{eoc}\t", (*dir).name) : 0;
	S_ISREG((*dir).stat.st_mode) ? ft_printf("%s\t", (*dir).name) : 0;
}

t_file		**insert(t_file **args, t_file *file)
{
	t_file			**tmp;
	unsigned int	i;

	i = 0;
	while (args && args[i])
		i++;
	if (!(tmp = (t_file **)malloc(sizeof(t_file *) * (i + 2))))
	{
		ft_printf(ERROR);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (args && args[i])
	{
		tmp[i] = args[i];
		i++;
	}
	tmp[i++] = file;
	tmp[i] = 0;
	args ? free(args) : 0;
	return (tmp);
}

int			main(int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;
	DIR				*d;
	t_file			**args;

	i = 0;
	j = 1;
	ft_printf("{yellow}[ft_ls]{eoc}\n");
	if (ac == 1)
		ft_ls(create_struct("", "."), i);
	else
	{
		if (*av[1] == '-' && (i = ft_ls_parse(av[j])))
			j = 2;
		while (av[j])
			ft_ls(create_struct(av[j++], ""), i);
	}
	write(1, "\n", 1);
	return (0);
}

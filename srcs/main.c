/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:02:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/26 02:29:18 by craffate         ###   ########.fr       */
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

void		error_handler(int i, char *s)
{
	char	*name;

	name = s ? ft_strjoin("\x1b[33m[ft_ls]\x1b[0m: ", s) : 0;
	if (i == 1)
	{
		write(2, USAGE, 58);
		exit(-1);
	}
	else
		perror(name);
	name ? free(name) : 0;
}

static void	pre_parsing(char **s, unsigned int i)
{
	t_file			**fs;
	t_file			**ds;
	t_file			*f;
	size_t			*schars;

	schars = arrnew(5);
	fs = 0;
	ds = 0;
	while (*s)
		if (!(f = create_struct(*s++, "")))
			error_handler(0, *(s - 1));
		else if (S_ISDIR(f->stat.st_mode) && !pathcheck(*(s - 1), i))
			ds = insert(ds, f, i);
		else
			fs = insert(fs, f, i);
	i & LS_L ? getsizes(schars, fs, ds) : 0;
	schars[4] = gettotals(fs, ds);
	displayfiles(i, schars, fs, 0);
	free(schars);
	while (ds && *ds)
		ft_ls(*ds++, i);
	fs ? freetab(fs) : 0;
}

int			main(int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	av++;
	while (av[j] && *av[j] == '-')
		i |= ft_ls_parse(av[j++]);
	ft_printf("{yellow}[ft_ls]{eoc}\n");
	if (ac > (int)j + 1)
		i |= MUL_ARGS;
	if (!av[j])
		ft_ls(create_struct("", "."), i);
	else
		pre_parsing(ascii_sort(&av[j]), i);
	return (0);
}

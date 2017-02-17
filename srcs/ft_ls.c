/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:09:27 by craffate          #+#    #+#             */
/*   Updated: 2017/02/17 13:37:40 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		displayfiles(int i, size_t *schars, t_file **files)
{
	i & LS_L ? ft_printf("Total: %lld\n", schars[4]) : 0;
	files ? display(files, i, schars) : 0;
	files ? freetab(files) : 0;
}

static t_file	**parse(DIR *d, char *path, int i, size_t *schars)
{
	struct dirent	*s;
	t_file			**fs;
	t_file			**ds;
	t_file			*f;

	fs = 0;
	ds = 0;
	while ((s = readdir(d)))
		if ((s->d_type == DT_DIR) && !pathcheck(s->d_name, i))
		{
			(f = create_struct(s->d_name, path)) && f ?
			ds = insert(ds, f, i) : 0;
			(f = create_struct(s->d_name, path)) && f ?
			fs = insert(fs, f, i) : 0;
		}
		else if (*s->d_name != '.' || i & LS_A)
			(f = create_struct(s->d_name, path)) && f ?
			fs = insert(fs, f, i) : 0;
	i & LS_L ? getsizes(schars, fs, ds) : 0;
	schars[4] = gettotals(fs, ds);
	displayfiles(i, schars, fs);
	closedir(d);
	return (ds);
}

int				ft_ls(t_file *dir, int i)
{
	t_file			**dirs;
	DIR				*d;
	char			*path;
	unsigned int	j;
	size_t			*schars;

	j = 0;
	schars = arrnew(5);
	path = join_path(dir->path, dir->name);
	d = opendir(path);
	dirs = NULL;
	(i & LS_CR || i & MUL_ARGS) ? ft_printf("{green}%s:{eoc}\n", (path)) : 0;
	!d ? ft_printf(DENIED) : 0;
	if (d && (dirs = parse(d, path, i, schars)) && i & LS_CR && dirs)
	{
		display(dirs, i, schars);
		while (dirs[j])
			ft_ls(dirs[j++], i);
	}
	free(path);
	dirs ? freetab(dirs) : 0;
	schars ? free(schars) : 0;
	return (0);
}

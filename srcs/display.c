/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:14:58 by craffate          #+#    #+#             */
/*   Updated: 2017/02/13 13:49:54 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*rights(t_file *file)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = ft_strnew(10);
	s[i++] = rights_type(file);
	s[i++] = *((*file).stat.st_mode & S_IRUSR ? "r" : "-");
	s[i++] = *((*file).stat.st_mode & S_IWUSR ? "w" : "-");
	s[i++] = *((*file).stat.st_mode & S_IXUSR ? "x" : "-");
	s[i++] = *((*file).stat.st_mode & S_IRGRP ? "r" : "-");
	s[i++] = *((*file).stat.st_mode & S_IWGRP ? "w" : "-");
	s[i++] = *((*file).stat.st_mode & S_IXGRP ? "x" : "-");
	s[i++] = *((*file).stat.st_mode & S_IROTH ? "r" : "-");
	s[i++] = *((*file).stat.st_mode & S_IWOTH ? "w" : "-");
	s[i] = *((*file).stat.st_mode & S_IXOTH ? "x" : "-");
	return (s);
}

static void	display_l_alt(t_file *dir, char *buf)
{
	if (S_ISSOCK((*dir).stat.st_mode))
		ft_printf("{white}%s{eoc}\n", (*dir).name);
	else if (S_ISLNK((*dir).stat.st_mode))
		ft_printf("{yellow}%s{eoc} -> %s\n", (*dir).name, buf);
	else if (S_ISBLK((*dir).stat.st_mode))
		ft_printf("{magenta}%s{eoc}\n", (*dir).name);
	else if (S_ISFIFO((*dir).stat.st_mode))
		ft_printf("{blue}%s{eoc}\n", (*dir).name);
	else if (S_ISCHR((*dir).stat.st_mode))
		ft_printf("{green}%s{eoc}\n", (*dir).name);
	else if (S_ISDIR((*dir).stat.st_mode))
		ft_printf("{cyan}%s{eoc}\n", (*dir).name);
	else if (execcheck(dir) && !(S_ISDIR((*dir).stat.st_mode)))
		ft_printf("{red}%s{eoc}\n", (*dir).name);
	else if (S_ISREG((*dir).stat.st_mode) && !(execcheck(dir)))
		ft_printf("%s\n", (*dir).name);
}

void		display_l(t_file *dir, size_t *schars)
{
	char	*r;
	char	*d;
	char	*buf;
	char	*tmp;

	r = rights(dir);
	tmp = join_path((*dir).path, (*dir).name);
	buf = ft_strnew((*dir).stat.st_size);
	readlink(tmp, buf, (*dir).stat.st_size + 1);
	d = getdate_ls((*dir).stat.st_mtime);
	ft_printf("%-11s %*u %-*s  %-*s %*u %s ", r, schars[3],
	(*dir).stat.st_nlink, schars[0], getpwuid((*dir).stat.st_uid)->pw_name,
	schars[1], getgrgid((*dir).stat.st_gid)->gr_name, schars[2],
	(*dir).stat.st_size, d);
	display_l_alt(dir, buf);
	free(r);
	free(d);
	free(tmp);
	free(buf);
}

void		display_nl(t_file *dir)
{
	if (S_ISSOCK((*dir).stat.st_mode))
		ft_printf("{white}%s{eoc}\n", (*dir).name);
	else if (S_ISLNK((*dir).stat.st_mode))
		ft_printf("{yellow}%s{eoc}\n", (*dir).name);
	else if (S_ISBLK((*dir).stat.st_mode))
		ft_printf("{magenta}%s{eoc}\n", (*dir).name);
	else if (S_ISFIFO((*dir).stat.st_mode))
		ft_printf("{blue}%s{eoc}\n", (*dir).name);
	else if (S_ISCHR((*dir).stat.st_mode))
		ft_printf("{green}%s{eoc}\n", (*dir).name);
	else if (S_ISDIR((*dir).stat.st_mode))
		ft_printf("{cyan}%s{eoc}\n", (*dir).name);
	else if (execcheck(dir) && !(S_ISDIR((*dir).stat.st_mode)))
		ft_printf("{red}%s{eoc}\n", (*dir).name);
	else if (S_ISREG((*dir).stat.st_mode) && !(execcheck(dir)))
		ft_printf("%s\n", (*dir).name);
}

void		display(t_file **dir, int i, size_t *schars)
{
	unsigned int	j;

	j = 0;
	while (dir[j])
	{
		if (!(i & LS_L))
			display_nl(dir[j]);
		else if (i & LS_L)
			display_l(dir[j], schars);
		j++;
	}
}

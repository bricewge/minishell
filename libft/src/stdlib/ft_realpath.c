/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/syslimits.h>
#include <string.h>
#include "libft.h"

/*
** TODO Resolve link
*/

static char	**split_path(const char *restrict dirtypath)
{
	int		i;
	char	**split;

	split = ft_strsplit(dirtypath, '/');
	i = -1;
	while (split[++i])
	{
		if (ft_strequ(split[i], "."))
			ft_strclr(split[i]);
		else if (ft_strequ(split[i], ".."))
		{
			ft_strclr(split[i]);
			if (i > 0)
				ft_strclr(split[i - 1]);
		}
	}
	return (split);
}

static char	*concat_path(char **split)
{
	int		i;
	int		pos;
	char	result[PATH_MAX];

	pos = 0;
	i = -1;
	while (split[++i])
	{
		ft_putnbr(i);
		ft_putstr(split[i]);
		ft_putchar('\n');
		if (*(split[i]))
			{
				result[pos] = '/';
				pos += 1;
				pos += strlcpy(result + pos, split[i], sizeof(result) - pos);
			}
		free(split[i]);
	}
	return (ft_strdup(result));
}

char		*ft_realpath(const char *restrict file_name,
					 char *restrict resolved_name)
{
	char	*tmp;
	char	cwd[PATH_MAX];

	if (!file_name)
		return (NULL);
	if (!resolved_name)
		resolved_name = ft_strnew(PATH_MAX);
	if (*file_name == '.')
	{
		if (getcwd(cwd, sizeof(cwd)))
		{
			tmp = ft_pathjoin(cwd, file_name);
			return (concat_path(split_path(tmp)));
		}
		else
			return (NULL);
	}
	else
		return (concat_path(split_path(file_name)));
}

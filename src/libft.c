/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Functions which ought to be moved in my libft.
*/

#include "libft.h"
#include "minishell.h"

void			ft_freearr(char **pstr)
{
	int			i;

	i = -1;
	while (pstr[++i])
		free(pstr[i]);
	free(pstr);
}

void			*ft_lfind(const void *key, t_arr array,
							int (*compar)(const void *, const void *))
{
	size_t		i;
	char		*arrmemb;

	i = -1;
	while (++i < *(array.nel))
	{
		arrmemb = (void*)array.base + (i * array.width);
		if (compar(key, arrmemb) == 0)
			return (arrmemb);
	}
	return (NULL);
}

char			*ft_pathjoin(const char *dir, const char *file)
{
	char		*path;
	int			len;

	len = ft_strlen(dir);
	if (dir[len - 1] != '/')
	{
		path = ft_strjoin(dir, "/");
		path = ft_strjoinf(path, file, 1);
	}
	else
		path = ft_strjoin(dir, file);
	return (path);
}

int				ft_puterror(char *msg, char *name, int errnum)
{
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(name, 2);
	return (errnum);
}

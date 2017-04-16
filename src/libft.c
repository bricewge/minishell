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

extern char			**environ;

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

char			*ft_getenv(const char *name)
{
	char		*value;
	int			len;
	int			i;

	if (!name)
		return (NULL);
	len = ft_strlen(name);
	i = -1;
	while (environ[++i])
	{
		if (ft_strncmp(name, environ[i], len) == 0)
		{
			value = ft_strchr(environ[i], '=');
			if (value[0] == '=')
				value += 1;
			return(value);
		}
	}
	return (NULL);
}

/* int				ft_setenv(const char *name, const char *value, */
/* 					  int overwrite) */
/* { */
/* 	char		*env; */

/* 	if (!name || !value) */
/* 		return (-1); */
/* 	if ((env = ft_getenv(name))) */
/* 	{ */

/* 	} */
/* 	else */

/* } */

int				ft_putenv(char *string)
{
	int			ret;
	char		*name;
	char		*value;


	if (!string)
		return (-1);
	value = ft_strchr(string, '=') + 1;
	name = ft_strsub(string, 0, value - string - 1);
	ret = setenv(name, value, 1);
	free(name);
	return (ret);
}

int				ft_unsetenv(const char *name)
{
	int			i;
	int			j;
	int			len;
	char		**new;

	if (!name)
		return (-1);
	i = 0;
	while (environ[i])
		++i;
	if (!(new = (char**)malloc(sizeof(*environ) * i)))
		return (-1);
	i = 0;
	j = 0;
	len = ft_strlen(name);
	while (environ[i])
	{
		if (ft_strnstr(environ[i], name, len))
			++i;
		new[j++] = ft_strdup(environ[i++]);
	}
	environ = new;
	return (0);
}

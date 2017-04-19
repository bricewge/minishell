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

// TODO Make it more generic, using t_arr type
void			ft_freearr(char **pstr)
{
	int			i;

	i = -1;
	while (pstr[++i])
		free(pstr[i]);
	free(pstr);
}

/* void			*ft_lfind(const void *key, t_arr array, */
/* 						  int (*compar)(const void *, const void *)) */
/* { */

/* } */

char	*ft_stpcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (&dst[i]);
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

/*
** On the first non NULL call store the environnment by copying it; on
** subsequent non NULL call free the environnment and replace it.
*/

char			**ft_environ(char **envp)
{
	static char	**ret = NULL;
	static int	firstrun = 0;
	int			i;

	if (firstrun == 0 && envp)
	{
		firstrun = 1;
		i = -1;
		while (envp[++i])
			continue;
		ret = (char**)malloc(sizeof(char*) * (i + 1));
		if (ret)
		{
			i = -1;
			while (envp[++i])
				ret[i] = ft_strdup(envp[i]);
			ret[i] = NULL;
		}
	}
	else if (firstrun == 1 && envp)
	{
		free(ret);
		ret = envp;
	}
	return (ret);
}

char			*ft_getenv(const char *name)
{
	char		**envp;
	char		*value;
	int			len;
	int			i;

	if (!name)
		return (NULL);
	envp = ft_environ(NULL);
	len = ft_strlen(name);
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(name, envp[i], len) == 0)
		{
			value = ft_strchr(envp[i], '=');
			if (value[0] == '=')
				value += 1;
			return(value);
		}
	}
	return (NULL);
}

/*
** Return the index at which the variable name is located in the environnment.
** Return -1 if it isn't present in the environnment.
*/

static int		ft_posinenv(const char *name, char **envp)
{
	int			i;
	int			namelen;

	namelen = ft_strlen(name);
	i = -1;
	while (envp[++i])
		if (ft_strnequ(envp[i], name, namelen))
			return (i);
	return (-1);
}

static int		ft_modenv(const char *envname, const char *envvalue,
							int indname, char **envp)
{
	char		*newvar;
	int			tlen;

	tlen = ft_strlen(envname) + ft_strlen(envvalue) + 1;
	if ((newvar = ft_strnew(tlen)))
	{
		free(envp[indname]);
		envp[indname] = newvar;
		newvar = ft_stpcpy(ft_stpcpy(newvar, envname), "=");
		newvar = ft_stpcpy(newvar, envvalue);
		return (0);
	}
	return (-1);
}

static int		ft_addenv(const char *envname, const char *envvalue,
							char **envp)
{
	int			i;
	char		*newvar;
	char		**newenv;

	i = -1;
	while (envp[++i])
		continue;
	newenv = (char**)malloc(sizeof(char*) * (i + 2));
	if (newenv)
	{
		i = -1;
		while (envp[++i])
			newenv[i] = envp[i];
		if ((newvar = ft_strnew(ft_strlen(envname) + ft_strlen(envvalue) + 1)))
		{
			newenv[i] = newvar;
			newvar = ft_stpcpy(ft_stpcpy(newvar, envname), "=");
			newvar = ft_stpcpy(newvar, envvalue);
			newenv[i + 1] = NULL;
			ft_environ(newenv);
			return (0);
		}
	}
	return (-1);
}

int				ft_setenv(const char *envname, const char *envvalue,
							int overwrite)
{
	int			indname;
	char		**envp;

	if (!envname || ft_strchr(envname, '='))
		return (-1);
	envp = ft_environ(NULL);
	indname = ft_posinenv(envname, envp);
	if (indname != -1 && overwrite == 0)
		return (0);
	else if (indname != -1)
		return (ft_modenv(envname, envvalue, indname, envp));
	else
		return (ft_addenv(envname, envvalue, envp));
}

int				ft_putenv(char *string)
{
	int			ret;
	char		*name;
	char		*value;


	if (!string)
		return (-1);
	value = ft_strchr(string, '=') + 1;
	name = ft_strsub(string, 0, value - string - 1);
	ret = ft_setenv(name, value, 1);
	free(name);
	return (ret);
}

static int		ft_unsetenv_nrm(int envlen, int indname, char **envp)
{
	int			i;
	int			j;
	char		**newenv;

	newenv = (char**)malloc(sizeof(*envp) * envlen);
	if (newenv)
	{
		free(envp[indname]);
		newenv[envlen -1] = NULL;
		i = -1;
		j = -1;
		while (envp[++i])
			if (i != indname)
			newenv[++j] = envp[i];
		ft_environ(newenv);
	}
	else
		return(-1);
	return (0);
}

int				ft_unsetenv(const char *name)
{
	int			envlen;
	int			namelen;
	int			indname;
	char		**envp;

	if (!name || ft_strchr(name, '='))
		return (-1);
	envp = ft_environ(NULL);
	envlen = -1;
	namelen = ft_strlen(name);
	indname = -1;
	while (envp[++envlen])
		if (ft_strnequ(envp[envlen], name, namelen))
			indname = envlen;
	if (indname == -1)
		return (0);
	return (ft_unsetenv_nrm(envlen, indname, envp));
}

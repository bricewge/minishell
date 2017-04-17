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

// TODO Make it more generic, using t_arr type
void			ft_freearr(char **pstr)
{
	int			i;

	i = -1;
	while (pstr[++i])
		free(pstr[i]);
	free(pstr);
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

char			**ft_environ(char **envp)
{
	static char	**ret = NULL;
	int			i;

	if (envp)
	{
		if (ret)
			ft_freearr(ret);
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

/* int				ft_putenv(char *string) */
/* { */
/* 	int			ret; */
/* 	char		*name; */
/* 	char		*value; */


/* 	if (!string) */
/* 		return (-1); */
/* 	value = ft_strchr(string, '=') + 1; */
/* 	name = ft_strsub(string, 0, value - string - 1); */
/* 	ret = setenv(name, value, 1); */
/* 	free(name); */
/* 	return (ret); */
/* } */

/*
** Return the index at which the variable name is located in the environnment.
** Return -1 if it isn't present in the environnment.
*/

static int		ft_posinenv(const char *name, char **envp)
{
	int			i;
	int			ret;
	int			namelen;

	namelen = ft_strlen(name);
	i = -1;
	while (envp[++i])
		if (ft_strnequ(envp[i], name, namelen))
			ret = i;
	return (i);
}

static int		ft_modenv(const char *envname, const char *envvalue,
							int indname, char **envp)
{
}

static int		ft_addenv(const char *envname, const char *envvalue,
							char **envp)
{
}


int				ft_setenv(const char *envname, const char *envvalue,
							int overwrite)
{
	int			envlen;
	int			namelen;
	int			indname;
	char		**envp;

	if (!envname || ft_strchr(envname, '='))
		return (-1);
	envp = ft_environ(NULL);
	envlen = -1;
	namelen = ft_strlen(name);
	indname = -1;
	while (envp[++envname])
		if (ft_strnequ(envp[envname], name, namelen))
			indname = envname;
	if (indname != -1 && overwrite == 0)
		return (0); // It exists
	else if (indname != -1)
		ft_modenv(envname, envvalue, indname, envp); //Modify entry
	else
		ft_addenv(envname, envvalue, envp); //Add entry
}

static int		ft_unsetenv_nrm(int envlen, int indname, char **envp)
{
	int			i;
	int			j;
	char		**newenv;

	newenv = (char**)malloc(sizeof(*envp) * envlen);
	if (newenv)
	{
		newenv[envlen -1] = NULL;
		i = -1;
		j = -1;
		while (envp[++i])
			if (i != indname)
			newenv[++j] = ft_strdup(envp[i]);
		ft_environ(newenv);
		ft_freearr(newenv);
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

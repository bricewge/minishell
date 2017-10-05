/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/05 20:42:52 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	newenv = (char**)malloc(sizeof(*newenv) * (i + 2));
	if (newenv)
	{
		i = -1;
		while (envp[++i])
			newenv[i] = ft_strdup(envp[i]);
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

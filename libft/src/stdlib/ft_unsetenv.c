/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_unsetenv_nrm(int envlen, int indname, char **envp)
{
	int			i;
	int			j;
	char		**newenv;

	newenv = (char**)malloc(sizeof(*envp) * envlen);
	if (newenv)
	{
		free(envp[indname]);
		newenv[envlen - 1] = NULL;
		i = -1;
		j = -1;
		while (envp[++i])
			if (i != indname)
				newenv[++j] = envp[i];
		ft_environ(newenv);
	}
	else
		return (-1);
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

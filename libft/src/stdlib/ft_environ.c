/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/09 13:36:53 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_environ_init(char **newenvp)
{
	char		**envp;
	int			i;

	i = -1;
	while (newenvp[++i])
		continue;
	envp = (char**)malloc(sizeof(char*) * (i + 1));
	if (envp)
	{
		i = -1;
		while (newenvp[++i])
			envp[i] = ft_strdup(newenvp[i]);
		envp[i] = NULL;
	}
	return (envp);
}

/*
** On the first non NULL call store the environnment by copying it; on
** subsequent non NULL call free the environnment and replace it.
*/

char			**ft_environ(char **newenvp)
{
	static char	**envp = NULL;
	static int	intialized = 0;
	int			i;

	if (intialized == 0 && newenvp)
	{
		intialized = 1;
		envp = ft_environ_init(newenvp);
	}
	else if (intialized == 1 && newenvp)
	{
		i = -1;
		while (envp[++i])
			free(envp[i]);
		free(envp);
		envp = newenvp;
	}
	return (envp);
}

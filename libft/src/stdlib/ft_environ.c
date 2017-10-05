/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/05 23:12:03 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** On the first non NULL call store the environnment by copying it; on
** subsequent non NULL call free the environnment and replace it.
*/

char			**ft_environ(char **newenvp)
{
	static char	**envp = NULL;
	static int	firstrun = 0;
	int			i;

	if (firstrun == 0 && newenvp)
	{
		firstrun = 1;
		// i = ft_arrlen((void **)envp, sizeof(*envp));
		// envp = (char **)ft_arrdup(newenvp, i, sizeof(*envp));
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
	}
	else if (firstrun == 1 && newenvp)
	{
		i = -1;
		while (envp[++i])
			free(envp[i]);
		free(envp);
		// ft_arrdel(&envp);
		envp = newenvp;
	}
	return (envp);
}

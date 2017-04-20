/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

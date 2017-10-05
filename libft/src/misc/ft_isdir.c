/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:19:49 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/05 20:56:31 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int		ft_isdir(const char *path)
{
	struct stat buf;

	if (lstat(path, &buf) == 0)
		return (S_ISDIR(buf.st_mode));
	return (0);
}

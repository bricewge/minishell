/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:59:46 by bwaegene          #+#    #+#             */
/*   Updated: 2017/09/27 17:36:20 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = (char*)malloc(sizeof(*dup) * ft_strlen(s) + 1);
	return (dup ? ft_strcpy(dup, s) : NULL);
}

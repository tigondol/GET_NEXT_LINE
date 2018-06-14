/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:25:29 by tigondol          #+#    #+#             */
/*   Updated: 2018/05/18 14:46:22 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	char	*ft_fill(int size, char *dest, char *tmp1, char *tmp2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (tmp1[j])
		{
			dest[i] = tmp1[j];
			i++;
			j++;
		}
		j = 0;
		while (tmp2[j])
		{
			dest[i] = tmp2[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(char *s1, char *s2)
{
	int		size;
	char	*dest;
	char	*tmp1;
	char	*tmp2;

	if (s1 && s2)
	{
		tmp1 = (char*)s1;
		tmp2 = (char*)s2;
		free(s1);
		size = ft_strlen(tmp1) + ft_strlen(tmp2);
		// printf("%d\n", size);
		if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		dest = ft_fill(size, dest, tmp1, tmp2);
		return (dest);
	}
	return (NULL);
}

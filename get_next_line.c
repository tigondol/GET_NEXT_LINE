/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:38 by tigondol          #+#    #+#             */
/*   Updated: 2018/06/14 17:53:51 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		checkerror(int fd, char **dest, char **line)
{
	if (fd == -1)
		return (-1);
	if (!*dest)
	{
		if (!(*dest = malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*ft_read(int fd, char *dest)
{
	int		save;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		//printf("||%d\n", ret);
		save += ret; // POUR FIN DE DEST
		//printf("__\n%d__\n", save);
		dest = ft_join(dest, buff);
		//ft_putendl(dest);
		//ft_putendl("\n________________________________/\\");
	}
	//dest[save] = '\0'; // POUR FIN DE DEST
	return (dest);
}

int		get_next_line(const int fd, char **line)
{
	int 			i;
	static	char	*dest;

	i = 0;
	if (checkerror(fd, &dest, line) == -1)
		return (-1);
	//if (*dest)
		//ft_strcpy(*line, dest);
	dest = ft_read(fd, dest);
	ft_putendl("_________________________________");
	ft_putendl(dest);
	// printf("++\n%s\n++\n", dest);
	if (dest[i])
	{
		// printf("lol");
		i = 0;
		while (dest[i] != '\n' && dest[i])
			i++;
		if (i == 0)
		{
			(*line) = ft_strdup("");
			dest = &dest[i + 1];
		}
		else
		{
			(*line) = ft_strsub(dest, 0, i);
			dest = &dest[i + 1];
			ft_strdel(&dest[i]);
	//printf("[\n%s\n]\n", *line);
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	//printf("TEST");
	return (0);
}

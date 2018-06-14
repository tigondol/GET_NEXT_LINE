/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:47:15 by tigondol          #+#    #+#             */
/*   Updated: 2018/06/13 17:44:53 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		//ft_putchar('\n');
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}

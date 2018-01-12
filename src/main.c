/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:39:46 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/12 14:53:53 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"
#include <fcntl.h>
#include "stdio.h"

int		get_rules(const int fd)
{
	int		count;
	char	*line;

	count = 0;
	get_next_line(fd, &line);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != '#')
			++count;
	}
	return (count);
}

char	**get_data(int fd, char *file)
{
	char	**data;
	char	*line;
	char	*temp;
	int		counter;

	if (!(data = ft_listnew(get_rules(fd))))
		return (NULL);
	if (fd > 0)
	{
		fd = ft_restart_file(fd, file);
		counter = 0;
		while (get_next_line(fd, &line) == 1)
		{
			temp = ft_strtrim(line);
			free(line);
			if (temp[0] != '#' && ft_strlen(temp) > 0)
			{
				line = ft_strsub(temp, 0, ft_strchr_indx(temp, '#'));
				free(temp);
				data[counter] = ft_strtrim(line);
				counter++;
			}
		}
	}
	return (data);
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	**data;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			int		i;
			if (!(data = get_data(fd, argv[1])))
			{
				ft_putendl("\x1b[31mThe file you tried is not valid or does not exist\x1b[0m");
				exit(1);
			}
			i = ft_strlen_point(data);
			while (i--)
			{
				ft_putendl(data[i]);
			}
		}
	}
	else
		ft_putendl("\x1b[31mUsage: ./expert_sytem file\x1b[0m");
	return (0);
}

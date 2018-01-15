/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:39:46 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/15 14:16:10 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"
#include <fcntl.h>
#include "stdio.h"

int		main(int argc, char *argv[])
{
	t_shunt	shnt;
	int		fd;
	int		i;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			get_data(fd, argv[1], &shnt);
			if (!(shnt.data))
			{
				ft_putendl("\x1b[31mThe file you tried is not valid or does not exist\x1b[0m");
				exit(1);
			}
			express(&shnt);
			//i = ft_strlen_point(shnt.data);
			i = 0;
			while (shnt.data[i])
			{
				ft_putendl(shnt.data[i++]);
			}
		}
		else
		{
			ft_putendl("\x1b[31mThe file you tried is not valid or does not exist\x1b[0m");
			exit(1);
		}
		close(fd);
	}
	else
		ft_putendl("\x1b[31mUsage: ./expert_sytem file\x1b[0m");
	return (0);
}

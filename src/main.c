/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:39:46 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/16 11:46:22 by lmucassi         ###   ########.fr       */
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
				get_err(FILE_ERR);
				exit(1);
			}
			express(&shnt);
			getPolish(&shnt);
			//i = ft_strlen_point(shnt.data);
			i = 0;
			//if (!shnt.polish[0])
			//	ft_putendl("NOTING");
			/*
			while (shnt.polish[i])
			{
				ft_putendl(shnt.polish[i++]);
			}*/
		}
		else
		{
			get_err(FILE_ERR);
			exit(1);
		}
		close(fd);
	}
	else
		get_err(USAGE_ERR);
	return (0);
}

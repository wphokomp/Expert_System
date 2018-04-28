/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:39:46 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/27 23:20:49 by wphokomp         ###   ########.fr       */
/*   Updated: 2018/01/23 16:07:14 by lmucassi         ###   ########.fr       */
/*   Updated: 2018/01/16 11:46:22 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	reset(t_shunt *shnt, int h)
{
	int		i;

	i = -1;
	shnt->ch_val[h] = (bool *)malloc(sizeof(bool) * ft_strlen(shnt->no_dups));
	while (shnt->no_dups[++i])
		shnt->ch_val[h][i] = false;
}

void	init(t_shunt *shnt, int i)
{
	if (i > 0)
	{
		free(shnt->queue);
		free(shnt->stack);
	}
	shnt->que = 0;
	shnt->st_len = 0;
	shnt->ch = 0;
	shnt->queue = ft_strnew(ft_strlen(shnt->data[i]));
	shnt->stack = ft_strnew(ft_strlen(shnt->data[i]));
	shnt->facts = ft_getfacts(shnt);
	shnt->ch_val = (bool **)malloc(sizeof(bool) * ft_strlen_point(shnt->facts));
}

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
			get_polish(&shnt, shnt.data);
			i = -1;
			while (shnt.facts[++i])
				reset(&shnt, i);
			store_val(&shnt);
			int	i = -1;
			while (shnt.data[++i])
				ft_putendl(shnt.data[i]);
			// process(&shnt);
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

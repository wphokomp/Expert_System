/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:51:45 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/24 17:33:02 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

int		get_rules(const int fd)
{
	int		cnt;
	char	*line;

	cnt = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != '#')
			++cnt;
	}
	return (cnt);
}

void	get_data(int fd, char *file, t_shunt *shnt)
{
	char	*line;
	char	*tmp;
	int		counter;

	if (!(shnt->data = ft_listnew(get_rules(fd))))
		return ;
	fd = ft_restart_file(fd, file);
	counter = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strtrim(line);
		free(line);
		if (tmp[0] != '#' && ft_strlen(tmp) > 0)
		{
			line = ft_strsub(tmp, 0, ft_strchr_indx(tmp, '#'));
			free(tmp);
			shnt->data[counter] = ft_strtrim(line);
			++counter;
		}
	}
}

void	store_val(t_shunt *shnt)
{
	int		i;

	shnt->que = -1;
	while (shnt->facts[++shnt->que])
	{
		i = -1;
		shnt->st_len = 0;
		while (shnt->no_dups[++i])
		{
			if (!ft_chrcmp(shnt->no_dups[i], shnt->facts[shnt->que][shnt->st_len]))
			{
				shnt->ch_val[shnt->que][i] = true;
				shnt->st_len++;
			}
		}
	}
}

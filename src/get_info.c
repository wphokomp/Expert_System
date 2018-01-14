/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:51:45 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/14 12:51:04 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

char	**express(char	**data)
{
	static char	**ret;

	if (!data)
	{
		if (!ret)
			return (NULL);
		return (ret);
	}
	return ((ret = ft_listdup(data)));
}

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
			counter++;
		}
	}
}

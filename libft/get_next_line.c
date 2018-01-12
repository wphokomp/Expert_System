/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:04:25 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/11 17:32:36 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_read(const int fd, char **temp)
{
	int		rd;
	char	*buff;
	char	*h;


	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (0);
	rd = read(fd, buff, BUFF_SIZE);
	if (rd > 0)
	{
		h = ft_strjoin(*temp, buff);
		free(*temp);
		*temp = h;
		//free(h);
	}
	free(buff);
	return (rd);
}

int			get_next_line(const int fd, char **line)
{
	static char	*temp;
	char		*feed;
	int			rd;
	
	if ((!temp && !(temp = ft_strnew(sizeof(*temp)))) ||
			!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	while (!(feed = ft_strchr(temp, '\n')))
	{
		rd = l_read(fd, &temp);
		if (!rd)
			if (!ft_strlen(temp))
				return (0);
	}
	*line = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen(feed));
	temp = ft_strdup(feed + 1);
	return (1);
}

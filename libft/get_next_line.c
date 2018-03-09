/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:23:12 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/15 14:07:05 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		end_of_line(char *temp)
{
	int word;

	word = 0;
	while (temp[word])
	{
		if (temp[word] == '\n')
			return (word);
		word++;
	}
	return (word);
}

static int		fill_line(const int fd, char *tmp[fd], char **line)
{
	int		end;
	char	*temp;

	end = end_of_line(tmp[fd]);
	*line = ft_strsub(tmp[fd], 0, end);
	if (!(temp = (char *)malloc(sizeof(temp) * (ft_strlen(tmp[fd]) + 1))))
		return (-1);
	ft_strcpy(temp, &tmp[fd][end + 1]);
	ft_strclr(tmp[fd]);
	tmp[fd] = ft_strcpy(tmp[fd], temp);
	free(temp);
	return (1);
}

static char		*strjoin_free(char *tmp, char *buff)
{
	char *temp;

	if (!(temp = ft_strjoin(tmp, buff)))
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (temp);
}

static int		fill_array(const int fd, char *tmp[fd])
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while (!(ft_strchr(tmp[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp[fd] = strjoin_free(tmp[fd], buff);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*temp[MAX_FD];

	if (fd < 0 || fd == 1 || fd == 2 || fd > MAX_FD || !line || BUFF_SIZE < 0)
		return (-1);
	if (!temp[fd] && (!(temp[fd] = ft_strnew(2))))
		return (-1);
	if (fill_array(fd, &(*temp)) < 0)
		return (-1);
	if (temp[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (fill_line(fd, temp, line) < 0)
		return (-1);
	return (1);
}

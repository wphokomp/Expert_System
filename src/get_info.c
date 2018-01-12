int		gnl(const int fd, char **line)
{
	return (get_next_line(fd, &line));
}

int		get_rules(const int fd)
{
	int		cnt;
	char	*line;

	cnt = 0;
	gnl(fd, &line);
	while (gnl(fd, &line) == 1)
	{
		if (line([0] != '#'))
			++cnt;
	}
	return (cnt);
}

char	**get_data(int fd, char *file)
{
	char	**data;
	char	*line;
	char	*tmp;
	int		counter;

	if (!(data = ft_strnew(get_rules(fd))))
		return (NULL);
	if (fd > 0)
	{
		fd = ft_restart_file(fd, file);
		counter = 0;
		while (gnl(fd, &line) == 1)
		{
			tmp = ft_strtrim(line);
			free(line);
			if (tmp[0] != '#' && ft_strlen(tmp) > 0)
			{
				line = strsub(tmp, 0, ft_strchr_index(tmp, '#'));
				free(tmp);
				data[counter] = ft_strtrim(line);
				counter++;
			}
		}
	}
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:26:17 by whan              #+#    #+#             */
/*   Updated: 2020/12/08 23:06:03 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		submit_and_trim(int i, int j, char **draw, char **line)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (i + 1));
	while (i > ++j)
		tmp[j] = (*draw)[j];
	tmp[i] = 0;
	*line = tmp;
	j = ft_strlen(*draw) - i;
	tmp = (char *)malloc(sizeof(char) * j);
	j = 0;
	while ((*draw)[++i])
		tmp[j++] = (*draw)[i];
	tmp[j] = 0;
	free(*draw);
	*draw = tmp;
	return (1);
}

int		check_nl_and_exe(char **draw, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (*draw != 0 && (*draw)[i])
	{
		if ((*draw)[i] == 10)
			return (submit_and_trim(i, j, draw, line));
		i++;
	}
	return (0);
}

int		finish(char **line)
{
	*line = (char *)malloc(sizeof(char) * 1);
	(*line)[0] = 0;
	return (0);
}

int		all_read(char **draw, char **line)
{
	if (*draw == 0 || **draw == 0)
		return (finish(line));
	*line = strjoin(*line, *draw);
	free(*draw);
	*draw = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*draw[OPEN_SIZE];
	char		buf[BUFFER_SIZE + 1];
	int			res;
	int			i;

	if(BUFFER_SIZE <= 0)
		return(-1);
	*line = 0;
	while(1)
	{
		if (draw[fd] != 0 && check_nl_and_exe(&draw[fd], line))
			return (1);
		i = -1;
		while (buf[++i])
			buf[i] = 0;
		res = read(fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (-1);
		buf[res] = 0;
		if (res == 0)
			return (all_read(&draw[fd], line));
		draw[fd] = strjoin(draw[fd], buf);
	}
}
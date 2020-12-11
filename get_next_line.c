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

char	*strjoin(char *dst, char *src)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	while (dst && dst[i])
	{
		tmp[i] = dst[i];
		i++;
	}
	while (src[j])
		tmp[i++] = src[j++];
	tmp[i] = 0;
	if (dst)
		free(dst);
	dst = tmp;
	return dst;
}

int		check_newline(char **draw, char **line)
{

	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	while (*draw != 0 && (*draw)[i])
	{
		if ((*draw)[i] == 10)
		{
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
		i++;
	}
	return (0);
}

int		finish(char **line)
{
	*line = (char *)malloc(sizeof(char) * 1);
	(*line)[0] = 0;
	return(0);
}

int		all_read (draw, line)
{
	if (draw == 0 || *draw == 0)
		return (finish(line));
	*line = strjoin(*line, draw);
	free(draw);
	draw = 0;
	return (0);
}

int		strnl(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i++] == 10)
			return(1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*draw;
	char		buf[BUFFER_SIZE + 1];
	int			res;
	int			i;

	if(BUFFER_SIZE <= 0)
		return(-1);
	*line = 0;
	while(1)
	{
		if (draw != 0 && check_newline(&draw, line))
			return (1);
		i = -1;
		while (buf[++i])
			buf[i] = 0;
		res = read(fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (-1);
		buf[res] = 0;
		if (res == 0)
<<<<<<< HEAD
			return (all_read(draw, line);
=======
		{
			if (!strnl(draw))
			{
				*line = strjoin(*line, draw);
				*draw = 0;
				return (0);
			}
			else if(*draw == 0)
				return (finish(line));
			*line = strjoin(*line, draw);
			return (1);
		}
>>>>>>> ff0af148d9de8467cb971ea21edea57ecb40e0f3
		draw = strjoin(draw, buf);
	}
}

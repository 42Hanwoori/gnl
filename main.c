/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:26:17 by whan              #+#    #+#             */
/*   Updated: 2020/11/23 11:26:22 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4

size_t	ft_strlen(const char *s)
{
	size_t n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}

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
		i++;
		if ((*draw)[i] == 10)
		{
			tmp = (char *)malloc(sizeof(char) * (i + 1));
			while (i > ++j)
				tmp[j] = (*draw)[j];
			tmp[i] = 0;
			*line = tmp;
			write(1, *line, i);
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
	}
	return (0);
}
void	finish(char **line)
{
	free(*line);
	*line = (char *)malloc(sizeof(char) * 1);
	(*line)[0] = 0;
}

int		get_next_line(int fd, char **line)
{
	static char	*draw;
	char		buf[BUFFER_SIZE + 1];
	int			res;

	while(1)
	{
		if (draw != 0 && check_newline(&draw, line))
			return (1);
		res = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = 0;
		if (res == 0 && *draw == 0)
		{
			finish(line);			
			return (0);
		}
		draw = strjoin(draw, buf);
	}
}

int		main(void)
{
	int		fd;
	char	*line;
	int		a;

	line = 0;
	fd = open("/Users/whan/Desktop/gnl/submission/test.txt", O_RDONLY);
	while ((a = get_next_line(fd, &line)) > 0)
	{
		printf("%s", line);
		printf("check");
		write(1, "\n", 1);
		free(line);
	}
	//write(1, "han", 3);
	// printf("%p", line);
	free(line);
    close(fd);
	return 0;

	// char *line = 0;
	// int ret;
	// int fd;
	// fd = open("/Users/whan/Desktop/gnl/submission/text2.txt", O_RDONLY);
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// printf("%s\n", line);
	// free(line);
	// }
	// printf("%s\n", line);
	// free(line);
	// close(fd);
	// return (0);
}


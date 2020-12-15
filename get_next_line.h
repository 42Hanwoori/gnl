/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:28:37 by whan              #+#    #+#             */
/*   Updated: 2020/12/08 15:25:29 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif

#ifndef OPEN_SIZE
#define OPEN_SIZE 256
#endif

int		submit_and_trim(int i, int j, char **draw, char **line)
int		check_nl_and_exe(char **draw, char **line)
int		finish(char **line);
int		all_read(char **draw, char **line)
size_t	ft_strlen(const char *s);
char	*strjoin(char *dst, char *src);
int		get_next_line(int fd, char **line);
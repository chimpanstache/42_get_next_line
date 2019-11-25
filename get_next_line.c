/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:01:57 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/25 17:49:41 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

static int 		ft_check_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	 return (-1);
}

char		*ft_readline(char *line, int fd)
{
	char *buf;
	int ret;

	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE+ 1))))
		return (NULL);	
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)	
	{
		buf[ret] = '\0';
		if (!(line = ft_strjoin(line, buf)))
			return (NULL);		
		if (ft_check_nl(line) >= 0)
			break ;
	}
	if (ret < 0)
		return (NULL);
	free(buf);
	return (line);
}

int 			get_next_line(int fd, char **line)
{
	static char *rest = 0;
	int nl;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = ft_strdup(rest)))
		return (-1);			
	if (!(*line = ft_readline(*line, fd)))
		return (-1);
	if ((nl = ft_check_nl(*line)) >= 0 || (ft_check_nl(rest)) >= 0)
	{
		free(rest);
		if (!(rest = ft_strdup(*line + nl + 1)))
			return (-1);
		if (!(*line = ft_substr(*line, 0, nl))) 
			return (-1);	
		return (1);
	}
	rest[0] = '\0';
	return (0);
}


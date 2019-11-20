/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:11:36 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/20 12:49:26 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
 
static char		ft_free(char **line)
{
	free(*line);
	return (-1);
}

static int 		ft_check_nl(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		//printf("%d%s\n", i, "icinl");
		if (line[i] == '\n')
		{
			//printf("%d\n", i);
			return (i);
		}
		i++;
	}
	 return (-1);
}

/*char 	ft_put_subbuf(int fd, char **line, static char bordel)
{
	line = ft_strjoin(line, bordel);

}*/

int 			get_next_line(int fd, char **line)
{	
	char buf[BUFFER_SIZE + 1];
	int nl;
	int ret;
	int i;
	static char *bordel;
	
	i = 0;

	if (fd < 0 || *line == 0 || line == 0)
		return (-1);
	ret = 1;
	if (bordel)
	{
		free (*line);
		if (!(*line = ft_strjoin(*line, bordel)))
			return (-1);
	}
	while (ret > 0)
	{	
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (!(*line = ft_strjoin(*line, buf)))  
			return (ft_free(line));
		nl = ft_check_nl(*line);
		if (nl >= 0)
		{
			if (!(*line = ft_substr(*line, 0, nl)))
				return (ft_free(line));		
			while (buf[i] != '\n') // a partir de la c'est pour ajouter notre residu de buffer a notre prochain line.
				i++;
			bordel = ft_substr(buf, i, BUFFER_SIZE - i);
			return (1);
		}
	}		
	return (0);
}


int 	main()
{
	char *line;
	int fd;

	fd = open("shakeitoff", O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	return (0);
}

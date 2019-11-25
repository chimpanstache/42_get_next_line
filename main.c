/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:21:36 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/25 17:50:24 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int 	main()
{
	char *line;
	int fd;
	int	ret;

	line = NULL;
	fd = open("lorem", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%d|%s\n", ret, line);
		free(line);
	}	
	printf("%d|%s\n", ret, line);
	free(line);	
	return (0);
}

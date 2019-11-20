/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:37:35 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/19 14:51:52 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void        *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *dest1;
	char *src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n > 0)
	{
		if (*dest1 != *src1)
			*dest1 = *src1;
		dest1++;
		src1++;
		n--;
	}
	return (dest);
}

char        *ft_strdup(const char *s)
{
	char *copy;
	char *start;

	if (!(copy = (char *)malloc(sizeof(*copy) * (ft_strlen(s) + 1))))
		return (NULL);
	start = copy;
	while (*s)
	{
		*copy = *s;
		copy++;
		s++;
	}
	*copy = '\0';
	return (start);
}

char        *ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		s1_l;
	size_t		s2_l;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	if (!(arr = malloc(sizeof(char) * (s1_l + s2_l + 1))))
		return (0);
	ft_memcpy(arr, s1, s1_l);
	ft_memcpy(arr + s1_l, s2, s2_l);
	arr[s1_l + s2_l] = '\0';
	return (arr);
}

size_t      ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char        *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (!(arr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		arr[i] = s[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}

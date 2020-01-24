/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:32:45 by namenega          #+#    #+#             */
/*   Updated: 2020/01/24 15:20:44 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tab;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((char *)s1 == '\0' || (char *)s2 == '\0')
		return (0);
	if (!(tab = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (((char *)s1)[i] != '\0')
	{
		tab[i] = ((char *)s1)[i];
		i++;
	}
	while (((char *)s2)[j] != '\0')
	{
		tab[i + j] = ((char *)s2)[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (c == '\0')
		return (str + ft_strlen(s));
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_newstr(size_t size)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
		return ((char *)str);
	}
}

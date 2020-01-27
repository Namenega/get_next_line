/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:24:05 by namenega          #+#    #+#             */
/*   Updated: 2020/01/27 21:41:28 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free_ret(char *str, char *s2, int ret)
{
	if (str)
		free(str);
	str = NULL;
	if (s2)
		free(s2);
	s2 = NULL;
	return (ret);
}

void	ft_strclr(char *s)
{
	int		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len >= 0)
	{
		s[len] = '\0';
		len--;
	}
}

char	*ft_strcpy(char *dest, char *str)
{
	int		i;

	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*check_reminder(char *reminder, char **line)
{
	char	*str;

	str = NULL;
	if (reminder)
		if ((str = ft_strchr(reminder, '\n')))
		{
			*str = '\0';
			if (!(*line = ft_strdup(reminder, NULL)))
				return (NULL);
			ft_strcpy(reminder, ++str);
		}
		else
		{
			if (!(*line = ft_strdup(reminder, NULL)))
				return (NULL);
			ft_strclr(reminder);
		}
	else
		*line = ft_newstr(1);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE > 0 ? BUFFER_SIZE + 1 : 0];
	int			byte_was_read;
	char		*str;
	static char	*reminder;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	str = check_reminder(reminder, line);
	while ((!str && ((byte_was_read = read(fd, buff, BUFFER_SIZE)) != 0)))
	{
		buff[byte_was_read] = '\0';
		if ((str = ft_strchr(buff, '\n')) != NULL)
		{
			*str = '\0';
			str++;
			if (!(reminder = ft_strdup(str, reminder)))
				return (ft_free_ret(str, reminder, -1));
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)) || byte_was_read < 0)
			return (ft_free_ret(*line, NULL, -1));
		free(tmp);
	}
	return ((byte_was_read || ft_strlen(*line)) ? 1 : 0);
}

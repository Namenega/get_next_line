/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:27:59 by namenega          #+#    #+#             */
/*   Updated: 2020/01/24 15:52:29 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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
	char	*p_n;

	p_n = 0;
	if (reminder)
		if ((p_n = ft_strchr(reminder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reminder);
			while (*reminder != '\0')
				*reminder++ = '\0';
		}
	else
		*line = ft_newstr(1);
	return (p_n);
}

int		get_line(int fd, char **line, char *reminder)
{
	char		buff[BUFFER_SIZE + 1];
	int 		byte_was_read;
	char		*p_n;
	static char	*reminder;
	char		*tmp;

	p_n = check_reminder(reminder, line);
	while (!p_n && (byte_was_read = read(fd, buff, BUFFER_SIZE)))
	{
		buff[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buff, '\n')))
		{
			*p_n = '\0';
			p_n++;
			reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return (byte_was_read || ft_strlen(*line)) ? 1 : 0;
}

int		get_next_line

int		main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n", line);

}
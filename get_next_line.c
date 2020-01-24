/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:24:05 by namenega          #+#    #+#             */
/*   Updated: 2020/01/23 21:47:02 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_error(int fd, char *line)
{
	
}



int		get_next_line(int fd, char **line)
{
	char	*buf[BUFFER_SIZE + 1];
	int		i;

	if (!line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
}
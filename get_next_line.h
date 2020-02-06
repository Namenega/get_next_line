/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 04:24:19 by namenega          #+#    #+#             */
/*   Updated: 2020/02/06 14:17:46 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
char	*ft_strjoin_modified(char *s1, char *s2, int ret);
int		ft_endline(char *s);

#endif

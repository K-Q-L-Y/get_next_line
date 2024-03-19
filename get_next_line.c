/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:21:16 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/18 13:11:15 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include "get_next_line.h"

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	get_line_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\n' && s[len] != 0)
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

static int	nl_found(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1000000] = {0};
	char		*ret;
	int			line_len;
	int			bytes_read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	while (!nl_found(buffer))
	{
		bytes_read = read(fd, &buffer[get_line_len(buffer)], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
	}
	line_len = get_line_len(buffer);
	ret = ft_strdup(buffer, line_len, bytes_read);
	if (!ret)
		return (0);
	ft_memmove(buffer, &buffer[line_len], ft_strlen(buffer) - line_len);
	ft_bzero(&buffer[ft_strlen(buffer) - line_len], line_len);
	return (ret);
}

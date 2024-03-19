/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:28:07 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/18 13:05:27 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;

	if (size == 0)
		return ;
	i = 0;
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strdup(const char *s, int line_len, int bytes_read)
{
	char	*ret;

	ret = malloc((line_len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, line_len + 1);
	if (bytes_read <= 0 && line_len == 0)
	{
		free(ret);
		return (0);
	}
	return (ret);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (!dst && !src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			s1[len] = s2[len];
	}
	return (s1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if ((!dst && !src) && n)
		return (0);
	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)0;
		i++;
	}
}

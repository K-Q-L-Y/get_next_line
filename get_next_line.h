/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:07:31 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/18 13:07:51 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		get_line_len(char *s);
int		nl_found(char *s);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s, int line_len, int bytes_read);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_strlcpy(char *dest, const char *src, int size);
void	ft_bzero(void *str, size_t n);

#endif

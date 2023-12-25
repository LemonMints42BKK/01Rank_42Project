/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:55:46 by pnopjira          #+#    #+#             */
/*   Updated: 2023/01/23 17:50:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		check_nl(char *str);
char	*ft_strjoin(char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src);
char	*get_str(int fd, char *buff, char *str);
char	*get_line(char *str);
char	*remain_data(char *str);
#endif

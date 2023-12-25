/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:00:44 by pnopjira          #+#    #+#             */
/*   Updated: 2023/01/23 18:03:30 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

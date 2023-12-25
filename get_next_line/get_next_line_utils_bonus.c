/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:49 by pnopjira          #+#    #+#             */
/*   Updated: 2023/01/19 17:31:41 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		len++;
		str++;
	}	
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	os;

	os = 0;
	if (!src)
		return (0);
	while ((os) < dstsize)
	{
		dst[os] = src[os];
		os++;
	}
	if (dstsize > 0)
		dst[os] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	str[s1_len + s2_len] = '\0';
	if (s1)
	{
		ft_strlcpy(str, s1, s1_len);
		free (s1);
	}
	if (s2)
		ft_strlcpy(&str[s1_len], s2, s2_len);
	return (str);
}

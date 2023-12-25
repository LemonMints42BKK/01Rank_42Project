/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:46:55 by pnopjira          #+#    #+#             */
/*   Updated: 2023/01/20 01:08:29 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*remain_data(char *str)
{
	char	*remain;
	int		i;
	int		j;

	j = 0;
	if (! str || str[0] == '\0')
	{
		free (str);
		return (NULL);
	}
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	remain = (char *)malloc(((ft_strlen(str) - j) + 1) * sizeof(char));
	if (!remain)
		return (NULL);
	if (str[j] == '\n')
	{
		j++;
		i = 0;
		while (str[j] != '\0')
			remain[i++] = str[j++];
		remain[i] = '\0';
	}
	free (str);
	return (remain);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	line = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (str[i] != '\0')
	{
		line[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*get_str(int fd, char *buff, char *str)
{
	int	rd_able;

	rd_able = 1;
	while (rd_able >= 0)
	{
		rd_able = read(fd, buff, BUFFER_SIZE);
		if (rd_able == -1)
			return (NULL);
		buff[rd_able] = '\0';
		if (rd_able == 0)
			break ;
		str = ft_strjoin(str, buff);
		if (check_nl(buff) == 1)
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*str = NULL;

	if (fd >= 1000 || fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	str = get_str(fd, buff, str);
	free (buff);
	buff = (char *) NULL;
	line = get_line(str);
	if (str)
		str = remain_data(str);
	return (line);
}

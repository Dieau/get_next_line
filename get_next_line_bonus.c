/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:04:06 by alakhdar          #+#    #+#             */
/*   Updated: 2021/11/18 16:07:34 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffread(char *buffer, int fd)
{
	char	*line;
	int		ret;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	ret = 1;
	while (!(ft_strchr(buffer, '\n')) && ret != 0)
	{
		ret = read(fd, line, BUFFER_SIZE);
		if (ret == -1)
		{
			free(line);
			return (NULL);
		}
		line[ret] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*find_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_leftovers(char *buffer)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	newline = malloc(ft_strlen(buffer) - i + 1);
	if (!newline)
		return (NULL);
	i++;
	while (buffer[i])
		newline[j++] = buffer[i++];
	newline[j] = '\0';
	free(buffer);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer[fd] = buffread(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = find_line(buffer[fd]);
	buffer[fd] = save_leftovers(buffer[fd]);
	return (line);
}

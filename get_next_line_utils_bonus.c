/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:05:59 by alakhdar          #+#    #+#             */
/*   Updated: 2021/11/18 16:06:17 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (NULL);
	new = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buffer)) + 1));
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			new[i] = line[i];
	while (buffer[j])
		new[i++] = buffer[j++];
	new[ft_strlen(line) + ft_strlen(buffer)] = '\0';
	free(line);
	return (new);
}

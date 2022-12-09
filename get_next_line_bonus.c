/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:38:12 by bcho              #+#    #+#             */
/*   Updated: 2022/12/08 16:00:27 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_backup(char *backup)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	if (backup[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!dest)
		return (NULL);
	while (backup[i])
		dest[j++] = backup[i++];
	dest[j] = '\0';
	free(backup);
	return (dest);
}

char	*ft_read(int fd, char *backup)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(backup, '\n') && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(backup);
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		backup = ft_strjoin(backup, temp);
	}
	free(temp);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX + 1];
	char		*line;
	int			index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	backup[fd] = ft_read(fd, backup[fd]);
	if (!backup[fd])
	{
		free(backup[fd]);
		return (NULL);
	}
	while (backup[fd][index] != '\n' && backup[fd][index])
		index++;
	line = ft_substr(backup[fd], 0, index + 1);
	backup[fd] = update_backup(backup[fd]);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}

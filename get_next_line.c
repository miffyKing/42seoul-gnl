/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:00:52 by dayun             #+#    #+#             */
/*   Updated: 2022/11/25 18:56:41 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cutword(char *ptr)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (ptr[i] != '\n' && ptr[i])
		i++;
	if (!ptr[i])
	{
		free(ptr);
		return (NULL);
	}
	if (ptr[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(ptr) - i + 1));
	if (!dest)
		return (NULL);
	while (ptr[i])
		dest[j++] = ptr[i++];
	dest[j] = '\0';
	free(ptr);
	return (dest);
}

char	*ft_read(int fd, char *ptr)							//Ptr을 buffer size 만큼 읽고, ptr에 담아 리턴.
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	if (!temp)
		return NULL;
	
	while (ft_strchr(ptr, '\n') == 0 && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(ptr);
			return NULL;
		}
		temp[bytes] = '\0';
		ptr = ft_strjoin(ptr, temp);

	}
	
	free(temp);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			index;


	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}

	if (ptr == 0)
		ptr = ft_strdup(""); // "" 복사해서 ptr에 넣음

	ptr = ft_read(fd, ptr);
	
	if (ptr == 0)
	{
		free(ptr);
		return (NULL);
	}

	while (ptr[index] != '\n' && ptr[index])
	{
		index++;
	}	
	
	line = ft_substr(ptr, 0, index + 1);
	
	ptr = ft_cutword(ptr);
	
	if (line == 0 || line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}


int main()
{
    char    *line;
    int     fd;
    int     i;

    i = 0;

    fd = open("test", O_RDONLY);

    line = get_next_line(fd);
	
    while (line != NULL)
    {
        printf("line[%d] = %s", i + 1, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    printf("no nl gj----------------------\nthis line is (null)?? ---> line[null] = %s", line);
    free(line);
    return (0);
}
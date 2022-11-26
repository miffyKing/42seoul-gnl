/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:02:12 by dayun             #+#    #+#             */
/*   Updated: 2022/08/18 19:19:57 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (0);
	while (i < s1_len)
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*arr;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0);
	if (len > slen)
		len = slen;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	while (i < len && start + i < slen)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

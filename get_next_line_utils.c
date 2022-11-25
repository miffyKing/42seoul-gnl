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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*final_str;
	int		total_len;
	int		index;
	int		index2;

	index = -1;
	index2 = 0;
	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!final_str)
		return (0);
	while (s1[++index])
		final_str[index] = s1[index];
	while (s2[index2])
		final_str[index++] = s2[index2++];
	final_str[index] = '\0';
	free((void *)s1);
	return (final_str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	while (s1 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
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

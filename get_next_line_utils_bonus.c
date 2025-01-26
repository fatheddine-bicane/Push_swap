/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:20:53 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/26 10:34:47 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char)ch)
			return ((char *)(&str[i]));
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)(&str[i]));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*s1_s2;

	if (!s1 || !s2)
		return (0);
	s1_s2 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1_s2)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		s1_s2[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		s1_s2[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s1_s2[i] = 0;
	free(s1);
	return (s1_s2);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!s && !d)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dest > src)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;

	s1_dup = (char *)malloc((ft_strlen(s1) + 1));
	if (!s1_dup)
		return (0);
	ft_memmove(s1_dup, s1, (ft_strlen(s1) + 1));
	return (s1_dup);
}

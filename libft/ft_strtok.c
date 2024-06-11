/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:43 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 15:09:34 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 == *s2)
			return (s1);
		s1++;
	}
	return (NULL);
}

char	*ft_strtok(char *s, const char *delim)
{
	static char		*olds;
	char			*token;

	if (s == NULL)
		s = olds;
	while (*s == *delim)
		s++;
	if (*s == '\0')
	{
		olds = s;
		return (NULL);
	}
	token = s;
	s = ft_strpbrk(token, delim);
	if (s == NULL)
		olds = ft_strchr(token, '\0');
	else
	{
		*s = '\0';
		olds = s + 1;
	}
	return (token);
}

char	*ft_strtok_strict(char *s, const char *delim)
{
	static char	*olds;
	char		*token;

	if (s == NULL)
		s = olds;
	if (*s == '\0')
	{
		olds = s;
		return (NULL);
	}
	token = s;
	s = ft_strpbrk(token, delim);
	if (s == NULL)
		olds = ft_strchr(token, '\0');
	else
	{
		*s = '\0';
		olds = s + 1;
	}
	return (token);
}

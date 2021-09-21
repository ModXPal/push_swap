/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:51:50 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/22 00:40:47 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			s1_len;
	int			s2_len;
	int			i;
	char		*str;
	char const	*s2_cp;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s2_cp = s2;
	(void)s2_cp;
	str = (char *)malloc(sizeof(*str) * (s1_len + s2_len) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

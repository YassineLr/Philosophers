/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:46:49 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/21 08:59:16 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*str;

	i = -1;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(s1len + s2len + 1);
	if (!str)
		return (0);
	while (++i < s1len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2len)
		str[i + s1len] = s2[i];
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
}
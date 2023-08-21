/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:35:23 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/21 11:37:47 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_isnumeric(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	int	res;
	int	i;
	int	sign;

	if(!ft_isnumeric(s))
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == 32 || (s[i] <= 13 && s[i] >= 9))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] <= '9' && s[i] >= '0')
	{
		res = res * 10;
		res = res + s[i] - 48;
		i++;
	}
	return (sign * res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:45:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 11:45:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	ft_atoi_check(const char *str, int *error)
{
	int	i;
	int	sp;
	int	ret;

	sp = 0;
	*error = 0;
	while (str[sp] == 32 || (str[sp] > 8 && str[sp] < 14))
		sp++;
	i = sp;
	if (str[sp] == '-' || str[sp] == '+')
		i++;
	ret = 0;
	if (str[i] <= 47 || str[i] >= 58)
		*error = 1;
	while (str[i] > 47 && str[i] < 58)
		ret = ret * 10 + (str[i++] - 48);
	if (str[sp] == '-')
		return (-ret);
	return (ret);
}

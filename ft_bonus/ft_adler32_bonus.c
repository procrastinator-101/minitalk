/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adler32_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:17:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 12:20:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

uint32_t	ft_adler32_bonus(char *buffer, size_t len)
{
	size_t		i;
	uint16_t	left;
	uint16_t	right;
	uint32_t	adler32;

	adler32 = 1;
	left = (adler32 >> 16) & 0xffff;
	right = adler32 & 0xffff;
	i = 0;
	while (i < len)
	{
		right = (right + buffer[i]) % ADLER32_MOD;
		left = (left + right) % ADLER32_MOD;
		i++;
	}
	adler32 = left;
	return ((adler32 << 16) + right);
}

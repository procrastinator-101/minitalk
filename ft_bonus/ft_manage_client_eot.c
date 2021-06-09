/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_client_eot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:22:07 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 16:49:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_manage_client_eot(int pid, char *str)
{
	char		c;
	uint32_t	adler32;

	ft_send_byte(pid, 0);
	adler32 = ft_adler32(str, ft_strlen(str) + 1);
	i = -1;
	while (++i < 4)
		ft_send_byte(pid, (adler32 << (8 * i)) >> 24);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:30:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/10 10:25:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_send_byte(int pid, char byte)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < 8)
	{
		if (byte & (1 << i))
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret)
			ft_manage_error(ESTF);
		usleep(SLEEP_TIME);
	}
}

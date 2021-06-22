/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_client_eot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:28:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:34:28 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_manage_client_eot(int serverpid)
{
	int	i;
	int	clientpid;

	clientpid = getpid();
	ft_send_byte(serverpid, 0);
	i = -1;
	while (++i < 4)
		ft_send_byte(serverpid, (clientpid << (i * 8)) >> 24);
}

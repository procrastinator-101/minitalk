/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:45:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 16:21:34 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_handle_signal(int signal)
{
	static int		bit;
	static int		eot;
	static char		byte;
	static t_text	*text;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit < 8)
		return ;
	if (eot)
		eof = ft_manage_server_eot(&text, &eot, byte);
	else if (!byte)
		eof = 1;
	else if (ft_append_character(text, byte))
		ft_manage_error(EMAF);
	bit = 0;
	byte = 0;
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1)
		;
	return (0);
}

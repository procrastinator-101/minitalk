/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:25:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 16:28:20 by yarroubi         ###   ########.fr       */
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
	if (bit == 8)
	{
		if (eot)
			eot = ft_manage_server_eot(byte, &text);
		else if (!byte)
			eot = 1;
		else
		{
			text = ft_text_append_char(text, byte);
			if (!text)
				ft_manage_error(EMAF);
		}
		bit = 0;
		byte = 0;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:11:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_manage_server_eot(t_text **text)
{
	if (*text)
		write(STDOUT_FILENO, (*text)->buffer, (*text)->end);
	write(STDOUT_FILENO, "\n", 1);
	ft_text_harddel(text);
}

void	ft_handle_signal(int signal)
{
	static int		bit;
	static char		byte;
	static t_text	*text;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (!byte)
			ft_manage_server_eot(&text);
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

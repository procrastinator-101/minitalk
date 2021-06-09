/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:25:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 15:53:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc > 3)
	{
		printf("truncated characters\n");
		return (EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	if (pid < 0)
	{
		printf("incorrect pid\n");
		return (EXIT_FAILURE);
	}
	ft_transmit_string(pid, argv[2]);
}

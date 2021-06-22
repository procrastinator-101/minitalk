/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:25:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/13 15:37:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	error;

	if (argc > 3)
		ft_manage_error(ETC);
	else if (argc < 3)
		ft_manage_error(EMA);
	pid = ft_atoi_check(argv[1], &error);
	if (pid < 0 || error)
		ft_manage_error(EIP);
	i = -1;
	while (argv[2][++i])
		ft_send_byte(pid, argv[2][i]);
	ft_send_byte(pid, 0);
	return (0);
}

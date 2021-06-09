/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error_msg_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:39:17 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 13:40:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_display_error_msg(int error)
{
	ft_putstr_fd("error\n", STDERR_FILENO);
	if (error == EMAF)
		ft_putstr_fd("Memory allocation failure\n", STDERR_FILENO);
	else if (error == ECD)
		ft_putstr_fd("Data was corrupted during transmission\n", STDERR_FILENO);
	else if (error == ETC)
		ft_putstr_fd("Truncated characters\n" STDERR_FILENO);
	else if (error == EMA)
		ft_putstr_fd("Missing argument(s)\n", STDERR_FILENO);
	else if (error == EIP)
		ft_putstr_fd("Incorrect pid\n", STDERR_FILENO);
}

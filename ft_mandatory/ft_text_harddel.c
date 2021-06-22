/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_harddel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:03:52 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/10 13:04:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_text_harddel(t_text **text)
{
	if (!*text)
		return ;
	free((*text)->buffer);
	free(*text);
	*text = 0;
}

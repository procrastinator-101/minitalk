/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_harddel_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:25:59 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:25:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_text_harddel(t_text **text)
{
	if (!*text)
		return ;
	free((*text)->buffer);
	free(*text);
	*text = 0;
}

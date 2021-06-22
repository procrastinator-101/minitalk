/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_append_char_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:25:59 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:25:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_text	*ft_text_append_char(t_text *text, char c)
{
	if (!text)
	{
		text = ft_text_create();
		if (!text)
			return (0);
	}
	else if (text->size == text->end + 1)
	{
		text = ft_text_expand(text);
		if (!text)
			return (0);
	}
	text->buffer[text->end++] = c;
	text->buffer[text->end] = 0;
	return (text);
}

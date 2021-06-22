/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_append_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:05:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/10 15:15:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:41:52 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/10 14:44:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_text	*ft_text_expand(t_text *text)
{
	char	*buffer;

	buffer = malloc((text->size * 2) * sizeof(char));
	if (!buffer)
	{
		free(text->buffer);
		free(text);
		return (0);
	}
	text->size *= 2;
	buffer[text->end] = 0;
	ft_memcpy(buffer, text->buffer, text->end);
	free(text->buffer);
	text->buffer = buffer;
	return (text);
}

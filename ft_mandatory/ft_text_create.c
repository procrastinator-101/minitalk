/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:40:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/10 14:02:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_text	*ft_text_create(void)
{
	t_text	*text;

	text = malloc(sizeof(t_text));
	if (!text)
		return (0);
	text->buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!text->buffer)
	{
		free(text);
		return (0);
	}
	text->end = 0;
	text->buffer[0] = 0;
	text->size = BUFFER_SIZE;
	return (text);
}

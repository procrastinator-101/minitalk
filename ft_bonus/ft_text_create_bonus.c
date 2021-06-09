/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_create_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:47:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 12:54:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

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
	text->buffer[0] = 0;
	text->size = 1;
	return (text);
}

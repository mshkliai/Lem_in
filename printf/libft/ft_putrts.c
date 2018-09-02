/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:34:02 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/28 16:37:24 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putrts(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	while (i--)
		ft_putchar(str[i]);
}
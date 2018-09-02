/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:57:49 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/11 15:59:09 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

int	len_c(char *line, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (line[++i])
		if (line[i] == c)
			count++;
	return (count);
}
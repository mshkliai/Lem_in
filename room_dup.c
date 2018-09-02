/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:31:22 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/06 15:44:27 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

t_room	*room_dup(t_room *room)
{
	t_room	*end;

	if (!(end = (t_room*)malloc(sizeof(*end))))
		return (NULL);
	end->name = ft_strdup(room->name);
	end->x = room->x;
	end->y = room->y;
	end->in = room->in;
	end->ant = room->ant;
	end->next = NULL;
	return (end);
}

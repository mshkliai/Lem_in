/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:30:28 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/16 09:01:26 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_lem_in.h"

static int	founded(t_room **way)
{
	while (*way)
	{
		if ((*way)->vis == 1)
			return (1);
		*way = (*way)->next;
	}
	return (0);
}

static void	toggle_1(t_room **way, int *n)
{
	(*way)->coms->room->vis = 1;
	(*way)->coms->room->in == -2 ? *n = -1 : 0;
	(*way)->in == -1 ? (*way)->coms->room->in = 1 : 0;
	(*way)->in != -1 ? (*way)->coms->room->in = (*way)->in + 1 : 0;
}

static int	indexing(t_room **rooms)
{
	t_room	*way;
	t_start	st;

	way = *rooms;
	st.start = way;
	while (st.n != -1 && way)
	{
		way = st.start;
		if (!founded(&way))
			return (0);
		st.start2 = way->coms;
		while (st.n != -1 && way->coms)
		{
			if (!way->coms->room->vis)
				toggle_1(&way, &st.n);
			way->coms = way->coms->next;
		}
		way->coms = st.start2;
		way->vis = 2;
		way = way->next;
	}
	return (1);
}

static void	toggle_2(t_room *rooms, t_room **end)
{
	*end = rooms;
	while ((*end)->next)
		(*end) = (*end)->next;
}

int			short_way(t_room **rooms, t_room **links)
{
	t_room	*end_room;
	t_start	st;

	if (!indexing(rooms))
		return (0);
	toggle_2(*rooms, &end_room);
	st.line = ft_strdup(end_room->name);
	st.n = end_room->in + 1;
	st.start = (*rooms);
	while (--st.n != 1)
	{
		end_room = st.start;
		while (ft_strcmp(end_room->name, st.line))
			end_room = end_room->next;
		ft_strdel(&st.line);
		st.start2 = end_room->coms;
		while (end_room->coms && end_room->coms->room->in != st.n - 1)
			end_room->coms = end_room->coms->next;
		end_room->coms->room->nice_way = 1;
		add_room(links, room_dup(end_room->coms->room), 1);
		st.line = ft_strdup(end_room->coms->room->name);
		end_room->coms = st.start2;
	}
	ft_strdel(&st.line);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:28:52 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/16 10:07:07 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

static int	how_ways(t_room **rooms)
{
	t_room	*start;
	t_comm	*start2;
	int		n;

	n = 0;
	start = *rooms;
	while ((*rooms))
	{
		start2 = (*rooms)->coms;
		while ((*rooms)->coms)
		{
			if ((*rooms)->coms->room->in == -2)
				n++;
			(*rooms)->coms = (*rooms)->coms->next;
		}
		(*rooms)->coms = start2;
		(*rooms) = (*rooms)->next;
	}
	(*rooms) = start;
	return (n);
}

static void	clear(t_room **rooms)
{
	t_room	*start;

	(*rooms)->in = -1;
	(*rooms)->vis = 1;
	start = (*rooms)->next;
	while (start->next)
	{
		start->in = 0;
		if (!start->nice_way)
			start->vis = 0;
		start = start->next;
	}
	start->vis = 0;
	start->in = -2;
}

static void	multi_ways(t_room **rooms, t_room **links, int *i)
{
	int		how;
	t_room	*end;

	parsing(rooms);
	!(*rooms)->coms ? out_error(NS) : 0;
	!(how = how_ways(rooms)) ? out_error(W) : 0;
	end = *rooms;
	while (end->next)
		end = end->next;
	while (++(*i) < how)
	{
		links[*i] = NULL;
		if (!short_way(rooms, &links[*i]))
			return ;
		add_room(&links[*i], room_dup(*rooms), 1);
		add_room(&links[*i], room_dup(end), 0);
		end = links[*i];
		links[*i]->in = -1;
		links[*i]->ant = 0;
		while (end->next)
			end = end->next;
		end->in = -2;
		clear(rooms);
	}
	links[*i] = 0;
}

static void	show_ways(t_room **links)
{
	t_room	*link;
	int		i;

	i = -1;
	ft_printf("\n");
	while (links[++i])
	{
		link = links[i];
		ft_printf("\e[32mWay %d: \e[0m", i + 1);
		while (link)
		{
			if (link->next)
				ft_printf("\e[32m%s-\e[0m", link->name);
			else
				ft_printf("\e[32m%s\e[0m", link->name);
			link = link->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n\e[32mTotal count of founded ways: %d\e[0m\n", i);
}

int			main(int ac, char **av)
{
	t_room	*rooms;
	t_room	**links;
	int		i;

	i = -1;
	rooms = NULL;
	links = NULL;
	links = (t_room**)malloc(sizeof(t_room) * (1));
	multi_ways(&rooms, links, &i);
	if (!i)
		out_error(W);
	if (ac > 1 && !ft_strcmp(av[1], "-show_ways"))
		show_ways(links);
	ft_printf("\n");
	pass_ant(links, rooms, rooms->ant);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:14:43 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/16 10:19:58 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_LEM_IN_H
# define LIST_LEM_IN_H
# define BA "\e[31mError: Bad count ants.\e[0m\n"
# define EC "\e[31mError: Extra characters.\e[0m\n"
# define IN "\e[31mError: You need enter integer.\e[0m\n"
# define WR "\e[32mError: Bad description of room.\e[0m\n"
# define WRC "\e[32mError: Bad coordinats for room.\e[0m\n"
# define BL "\e[34mError: No link or comment.\e[0m\n"
# define DC "\e[1;32mError: Double commands.\e[0m\n"
# define IR "\e[33mError: Identic rooms or them coordinats.\e[0m\n"
# define ER "\e[31mError: Empty or invalid file.\e[0m\n"
# define ESE "\e[31mError: Command, what!?\e[0m\n"
# define S "##start"
# define E "##end"
# define BD "\e[32mError: Bad line.\e[0m\n"
# define NL "\e[36mError: No links.\e[0m\n"
# define NS "\e[34mError: No links with start-room.\e[0m\n"
# define W "\e[1;34mError: No available ways.\e[0m\n"
# define NC "\e[32mError: No necessary commands.\e[0m\n"
# define EL "\e[1;35mError: Linked room doesn't exist.\e[0m\n"
# define BN "\e[1;31mError: Bad room-name.\e[0m\n"
# define DE "\e[1;32mError: Double end.\e[0m\n"
# define NA "\e[1;33mError: No ants.\e[0m\n"

# include "./gnl/get_next_line.h"
# include "./printf/libftprintf.h"

struct s_room;

typedef struct		s_comm
{
	struct s_room	*room;
	struct s_comm	*next;
}					t_comm;

typedef struct		s_room
{
	char			*name;
	int				in;
	int				x;
	int				y;
	int				ant;
	int				vis;
	int				nice_way;
	t_comm			*coms;
	struct s_room	*prev;
	struct s_room	*next;
}					t_room;

typedef struct		s_start
{
	int				n;
	int				ants;
	t_room			*start;
	t_comm			*start2;
	char			*line;
}					t_start;

int					se(char **line, t_room **rooms, int *k, char **check);
int					len_c(char *line, char c);
t_room				*new_room(char *str);
void				add_room(t_room **rooms, t_room *room, int se);
int					spacer(char **line);
void				parsing(t_room **rooms);
t_room				*room_dup(t_room *room);
int					short_way(t_room **rooms, t_room **links);
char				*join_free(char *line, char *line2, int flag);
void				pass_ant(t_room **links, t_room *rooms, int fixed);
void				out_error(char *line);

#endif

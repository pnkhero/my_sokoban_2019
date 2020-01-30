/*
** EPITECH PROJECT, 2019
** move_player.c
** File description:
** move_p
*/

#include "./include/my.h"

void player_up(struct posplayer *p, struct map *m)
{
	if (m->tab[p->y - 1][p->x] != WALL) {
		if (m->tab[p->y - 1][p->x] == BOX)
			move_box_up(m, p);
		else {
			m->tab[p->y - 1][p->x] = PLAYER;
			m->tab[p->y][p->x] = EMPTY;
			p->y--;
		}
	}
}

void player_down(struct posplayer *p, struct map *m)
{
	if (m->tab[p->y + 1][p->x] != WALL) {
		if (m->tab[p->y + 1][p->x] == BOX)
			move_box_down(m, p);
		else {
			m->tab[p->y + 1][p->x] = PLAYER;
			m->tab[p->y][p->x] = EMPTY;
			p->y++;
		}
	}
}

void player_left(struct posplayer *p, struct map *m)
{
	if (m->tab[p->y][p->x - 1] != WALL) {
		if (m->tab[p->y][p->x - 1] == BOX)
			move_box_left(m, p);
		else {
			m->tab[p->y][p->x - 1] = PLAYER;
			m->tab[p->y][p->x] = EMPTY;
			p->x--;
		}
	}
}

void player_right(struct posplayer *p, struct map *m)
{
	if (m->tab[p->y][p->x + 1] != WALL) {
		if (m->tab[p->y][p->x + 1] == BOX)
			move_box_right(m, p);
		else {
			m->tab[p->y][p->x + 1] = PLAYER;
			m->tab[p->y][p->x] = EMPTY;
			p->x++;
		}
	}
}
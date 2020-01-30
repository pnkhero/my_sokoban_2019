/*
** EPITECH PROJECT, 2019
** move box
** File description:
** move_box
*/

#include "./include/my.h"

void move_box_up(struct map *m, struct posplayer *p)
{
	if (m->tab[p->y - 2][p->x] != WALL) {
		m->tab[p->y - 1][p->x] = PLAYER;
		m->tab[p->y - 2][p->x] = BOX;
		m->tab[p->y][p->x] = EMPTY;
		p->y--;
	}
}

void move_box_down(struct map *m, struct posplayer *p)
{
	if (m->tab[p->y + 2][p->x] != WALL) {
		m->tab[p->y + 1][p->x] = PLAYER;
		m->tab[p->y + 2][p->x] = BOX;
		m->tab[p->y][p->x] = EMPTY;
		p->y++;
	}
}

void move_box_left(struct map *m, struct posplayer *p)
{
	if (m->tab[p->y][p->x - 2] != WALL) {
		m->tab[p->y][p->x - 1] = PLAYER;
		m->tab[p->y][p->x - 2] = BOX;
		m->tab[p->y][p->x] = EMPTY;
		p->x--;
	}
}

void move_box_right(struct map *m, struct posplayer *p)
{
	if (m->tab[p->y][p->x + 2] != WALL) {
		m->tab[p->y][p->x + 1] = PLAYER;
		m->tab[p->y][p->x + 2] = BOX;
		m->tab[p->y][p->x] = EMPTY;
		p->x++;
	}
}
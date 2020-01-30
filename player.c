/*
** EPITECH PROJECT, 2019
** player.c
** File description:
** player
*/

#include "./include/my.h"

void search_player(struct map *m, char *buffer, struct posplayer *p)
{
    int j = 0;
    int i = 0;
    int nb_rows = my_strlen_lines(buffer);
    int nb_cols = my_strlen_col(buffer);

    while (j < nb_rows) {
        while (i < nb_cols) {
            check_if_p(m, i, j, p);
            i++;
        }
        i = 0;
        j++;
    }
}

void check_if_p(struct map *m, int i, int j, struct posplayer *p)
{
    if (m->tab[j][i] == PLAYER) {
        p->x = i;
        p->y = j;
	}
}

char **move_arrow(int input, struct map *m, struct posplayer *p)
{
    switch (input)
    {
        case KEY_UP:
            player_up(p, m);
            break;

        case KEY_DOWN:
            player_down(p, m);
            break;

        case KEY_LEFT:
            player_left(p, m);
            break;
        
        case KEY_RIGHT:
            player_right(p, m);
            break;
    }
}
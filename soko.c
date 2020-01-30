/*
** EPITECH PROJECT, 2019
** my_sokoban.c
** File description:
** soko
*/

#include <ncurses.h>
#include <stdlib.h>
#include "./include/my.h"

void *malloc_tab(char *buffer, struct map *m)
{
    int nb_rows = my_strlen_lines(buffer);
    int nb_cols = my_strlen_col(buffer);
    m->tab = malloc(sizeof(char *) * nb_rows + 1);
    int i = 0;

    if (!m->tab) {
        return (NULL);
    }
    while (i < nb_rows) {
        m->tab[i] = malloc(sizeof(char) * nb_cols + 1);
        if (m->tab[i] == NULL) {
            return (NULL);
        }
        i++;
    }
}

void load_map_tab(struct map *m, char *buffer)
{
    int count = 0;
    int y = 0;
    int x = 0;

    while (buffer[count] != '\0') {
        m->tab[y][x] = buffer[count];
        if (buffer[count] == '\n') {
            y++;
            x = 0;
        }
        else
        {
            x++;
        }
        count++;
    }
}

void screensetup()
{
    initscr();
    noecho();
    refresh();
}

void mapsetup(struct map *m, char *buffer)
{
    int  count = 0;
    int nb_rows = my_strlen_lines(buffer);

        for (int i = 0; count < nb_rows; i = i - 1, count = count + 1)
        mvprintw(((LINES/2)-i), (COLS/2), m->tab[count]);
    refresh();
}

int main(int ac, char **av)
{
    struct posplayer p;
    struct map m;
    char *buffer;
    int ch = 0;

    buffer = openread(av[1]);
    use_tab(buffer, &m);
    search_player(&m, buffer, &p);
    screensetup();
    keypad(stdscr, TRUE);
    while (1) {
        refresh();
        mapsetup(&m, buffer);
        ch = getch();
        move_arrow(ch, &m, &p);
        }
}
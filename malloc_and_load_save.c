/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** malloc and load save
*/

#include "./include/my.h"
#include <stdlib.h>

void *malloc_save(char *buffer, struct map *m)
{
    int nb_rows = my_strlen_lines(buffer);
    int nb_cols = my_strlen_col(buffer);
    m->save = malloc(sizeof(char *) * nb_rows + 1);
    int i = 0;

    if (!m->tab) {
        return (NULL);
    }
    while (i < nb_rows) {
        m->save[i] = malloc(sizeof(char) * nb_cols + 1);
        if (m->tab[i] == NULL) {
            return (NULL);
        }
        i++;
    }
}

void load_map_save(struct map *m, char *buffer)
{
    int count = 0;
    int y = 0;
    int x = 0;

    while (buffer[count] != '\0') {
        m->save[y][x] = buffer[count];
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

void printab(struct map *m, char *buffer)
{
    int i = 0;
    int j = 0;
    int nb_rows = my_strlen_lines(buffer);
    int nb_cols = my_strlen_col(buffer);

    while (i < nb_rows) {
        while (j < nb_cols) {
            my_putchar(m->save[i][j]);
            j++;

        }
        j = 0;
        my_putstr("\n");
        i++;
    }
}

void use_tab(char *buffer, struct map *m)
{
    malloc_tab(buffer, m);
    load_map_tab(m, buffer);
    malloc_save(buffer, m);
    load_map_save(m, buffer);
}
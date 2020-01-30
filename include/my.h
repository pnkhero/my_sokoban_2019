/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <ncurses.h>

#define PLAYER 'P'
#define EMPTY ' '
#define BOX 'X'
#define OBJ 'O'
#define WALL '#'

struct posplayer
{
    int y;
    int x;
};

struct map
{
    char **tab;
    char **save;
};

char *openread(char const *filepath);
void *malloc_tab(char *buffer, struct map *m);
void load_map_tab(struct map *m, char *buffer);
int my_putstr_error(char const *str);
int my_strlen_lines(char const *str);
int my_strlen_col(char const *str);
int my_strlen(char const *str);
int my_ncurse(char **tab, char *buffer);
int my_putstr(char const *str);
int my_putcerror(char c);
int my_putchar(char c);
void search_player(struct map *m, char *buffer, struct posplayer *p);
void player_up(struct posplayer *p, struct map *m);
char **move_arrow(int input, struct map *m, struct posplayer *p);
void move_box_up(struct map *m, struct posplayer *p);
void check_if_p(struct map *m, int i, int j, struct posplayer *p);
void player_down(struct posplayer *p, struct map *m);
void player_left(struct posplayer *p, struct map *m);
void player_right(struct posplayer *p, struct map *m);
void move_box_down(struct map *m, struct posplayer *p);
void move_box_left(struct map *m, struct posplayer *p);
void move_box_right(struct map *m, struct posplayer *p);
void *malloc_save(char *buffer, struct map *m);
void load_map_save(struct map *m, char *buffer);
void use_tab(char *buffer, struct map *m);

#endif /* !MY_H_ */

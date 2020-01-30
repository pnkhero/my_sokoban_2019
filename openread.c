/*
** EPITECH PROJECT, 2019
** openread
** File description:
** openread1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./include/my.h"

int my_open (char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        my_putstr_error("open failed\n");
    }
    return (fd);
}

char *my_read(int fd, char *buffer, int size)
{
    int reader = read(fd, buffer, size);

    if  (reader == -1) {
        my_putstr_error("read failed\n"); 
    }
    buffer[size] = '\0';
    return (buffer);	
}

char *openread(char const *filepath)
{
    struct stat st;
    int fd;
    int size = 0;
    char *buffer;

    stat(filepath, &st);
    size = st.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    fd = my_open(filepath);
    my_read(fd, buffer, size);
    return (buffer);
}
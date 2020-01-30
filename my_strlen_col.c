/*
** EPITECH PROJECT, 2018
** my_strlen_col
** File description:
** Pas de fichier ici, juste un exemple d'en-tête epitech
*/

#include <string.h>

int my_strlen_col(char const *str)
{
    int i = 0;

    while (str[i] != '\n'){
        i++;
    }
    return (i);
} 
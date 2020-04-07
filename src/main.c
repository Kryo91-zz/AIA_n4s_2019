/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** test.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char **my_sep_array(char *st, char sep);

int main(void)
{
    char *tmp = NULL;
    char **cmd = NULL;
    size_t size = 0;

    write(1, "START_SIMULATION\n", 17);
    while (getline(&tmp, &size, stdin) == -1);
    // write(2, tmp, size);
    write(1, "CAR_FORWARD:1\n", 14);
    while (getline(&tmp, &size, stdin) == -1);
    sleep(2);
    // write(2, tmp, size);
    while (1) {
        write(1, "GET_INFO_LIDAR\n", 15);
        while (getline(&tmp, &size, stdin) == -1);
        cmd = my_sep_array(tmp, ':');
        for (int i = 0; cmd[i]; i++)
            fprintf(stderr, "%s\n", cmd[i]);
    }
    //write(2, tmp, size);
    sleep(6);
    write(1, "STOP_SIMULATION\n", 16);
    while (getline(&tmp, &size, stdin) == -1);
    // write(2, tmp, size);
    return (0);
}
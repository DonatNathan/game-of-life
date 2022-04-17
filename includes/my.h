#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <curses.h>

int check_alive(char **map, int line, int col);
char change_status_gol(char cellule, int nb_alive);
char change_status_hl(char cellule, int nb_alive);
char change_status_dn(char cellule, int nb_alive);
char change_status_l34(char cellule, int nb_alive);
int check_changes(char **map, int game);
char **create_map(int x, int y);
char **set_alive(char **map, char **argv);
void free_map(char **map);
int choose_game(char *game, char **map, int iteration);
int error_gestion(int argc, char **argv);
void display_help(void);

#endif /* MY_H_ */

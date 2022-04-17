#include "../includes/my.h"

int get_size(char **map)
{
    int cmpt;

    for (cmpt = 0; map[cmpt]; cmpt += 1);
    return (cmpt);
}

int check_top_left(char **map, int line, int col, int nb_alive)
{
    if (map[line - 1][col] == '*')
        nb_alive += 1;
    if (map[line - 1][col - 1] == '*')
        nb_alive += 1;
    if (map[line][col - 1] == '*')
        nb_alive += 1;
    return (nb_alive);
}

int check_bottom_right(char **map, int line, int col, int nb_alive)
{
    if (map[line + 1][col] == '*')
        nb_alive += 1;
    if (map[line + 1][col + 1] == '*')
        nb_alive += 1;
    if (map[line][col + 1] == '*')
        nb_alive += 1;
    return (nb_alive);
}

int check_alive(char **map, int line, int col)
{
    int nb_alive = 0;
    int len = strlen(map[0]) - 1;
    int size = get_size(map) - 1;

    if (line > 0 && col > 0)
        nb_alive = check_top_left(map, line, col, nb_alive);
    if (line < size && col < len)
        nb_alive = check_bottom_right(map, line, col, nb_alive);
    if (line < size && col > 0)
        if (map[line + 1][col - 1] == '*')
            nb_alive += 1;
    if (line > 0 && col < len)
        if (map[line - 1][col + 1] == '*')
            nb_alive += 1;
    return (nb_alive);
}

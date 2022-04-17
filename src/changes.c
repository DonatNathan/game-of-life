#include "../includes/my.h"

int calcul_changes(char cellule, int game, int nb_alive, int changes)
{
    if (game == 0)
        if (change_status_gol(cellule, nb_alive) == '*')
            changes += 1;
    if (game == 1)
        if (change_status_hl(cellule, nb_alive) == '*')
            changes += 1;
    if (game == 2)
        if (change_status_dn(cellule, nb_alive) == '*')
            changes += 1;
    if (game == 3)
        if (change_status_l34(cellule, nb_alive) == '*')
            changes += 1;
    return (changes);
}

int check_changes(char **map, int game)
{
    int changes = 0;
    int nb_alive;

    for (int line = 0; map[line]; line += 1) {
        for (int col = 0; map[line][col] != '\0'; col += 1) {
            nb_alive = check_alive(map, line, col);
            changes = calcul_changes(map[line][col], game, nb_alive, changes);
        }
    }
    return (changes);
}

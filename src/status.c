#include "../includes/my.h"

char change_status_gol(char cellule, int nb_alive)
{
    if (nb_alive == 3)
        cellule = '*';
    else if (nb_alive < 2 || nb_alive > 3)
        cellule = ' ';
    return (cellule);
}

char change_status_hl(char cellule, int nb_alive)
{
    if (cellule == ' ' && (nb_alive == 3 || nb_alive == 6))
        cellule = '*';
    else if (cellule == '*' && (nb_alive == 2 || nb_alive == 3))
        cellule = '*';
    else
        cellule = ' ';
    return (cellule);
}

char change_status_dn(char cellule, int nb_alive)
{
    if (cellule == ' ' && (nb_alive == 3 || nb_alive == 6 || nb_alive == 7 ||
    nb_alive == 8))
        cellule = '*';
    else if (cellule == '*' && (nb_alive == 3 || nb_alive == 4 || nb_alive ==
    6 || nb_alive == 7 || nb_alive == 8))
        cellule = '*';
    else
        cellule = ' ';
    return (cellule);
}

char change_status_l34(char cellule, int nb_alive)
{
    if (nb_alive == 3 || nb_alive == 4)
        cellule = '*';
    else
        cellule = ' ';
    return (cellule);
}

#include "../includes/my.h"

void display_map(char **map)
{
    usleep(100000);
    system("clear");
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
        printf("%s\n", map[cmpt]);
}

char **start_gol(char **map, int game)
{
    int nb_alive;
    int changes = check_changes(map, game);
    int *stock_x = malloc(sizeof(int) * changes);
    int *stock_y = malloc(sizeof(int) * changes);
    int cmpt = 0;

    for (int line = 0; map[line]; line += 1) {
        for (int col = 0; map[line][col] != '\0'; col += 1) {
            nb_alive = check_alive(map, line, col);
            if (game == 0) {
                if (change_status_gol(map[line][col], nb_alive) == '*') {
                    stock_x[cmpt] = col;
                    stock_y[cmpt] = line;
                    cmpt += 1;
                }
            }
            if (game == 1) {
                if (change_status_hl(map[line][col], nb_alive) == '*') {
                    stock_x[cmpt] = col;
                    stock_y[cmpt] = line;
                    cmpt += 1;
                }
            }
            if (game == 2) {
                if (change_status_dn(map[line][col], nb_alive) == '*') {
                    stock_x[cmpt] = col;
                    stock_y[cmpt] = line;
                    cmpt += 1;
                }
            }
            if (game == 3) {
                if (change_status_l34(map[line][col], nb_alive) == '*') {
                    stock_x[cmpt] = col;
                    stock_y[cmpt] = line;
                    cmpt += 1;
                }
            }
        }
    }
    cmpt = 0;
    for (int line = 0; map[line]; line += 1) {
        for (int col = 0; map[line][col] != '\0'; col += 1) {
            if (cmpt < changes && stock_x[cmpt] == col && stock_y[cmpt] ==
            line) {
                map[line][col] = '*';
                cmpt += 1;
            } else
                map[line][col] = ' ';
        }
    }
    free(stock_x);
    free(stock_y);
    return (map);
}

int check_game(int game_num, char *game)
{
    if (strcmp(game, "game_of_life") == 0)
        game_num = 0;
    if (strcmp(game, "hight_life") == 0)
        game_num = 1;
    if (strcmp(game, "day_night") == 0)
        game_num = 2;
    if (strcmp(game, "life_3_4") == 0)
        game_num = 3;
    return (game_num);
}

int choose_game(char *game, char **map, int iteration)
{
    int game_num = 0;

    game_num = check_game(game_num, game);
    if (game_num != 0 && game_num != 1 && game_num != 2 && game_num != 3) {
        write(2, "invalid game\n", 13);
        return (84);
    }
    while (iteration > 0) {
        display_map(map);
        map = start_gol(map, game_num);
        iteration -= 1;
    }
    return (0);
}

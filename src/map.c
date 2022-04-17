#include "../includes/my.h"

int read_x(char *pos)
{
    int cmpt;
    char *result;
    int end;

    for (cmpt = 0; pos[cmpt] != '-'; cmpt += 1);
    result = malloc(sizeof(char) * (cmpt + 2));
    for (cmpt = 0; pos[cmpt] != '-'; cmpt += 1)
        result[cmpt] = pos[cmpt];
    result[cmpt] = '\0';
    end = atoi(result);
    free(result);
    return (end);
}

int read_y(char *pos)
{
    int cmpt;
    char *result;
    int i;
    int end;

    for (i = 0; pos[i] != '-'; i += 1);
    for (cmpt = i + 1; pos[cmpt] != '\0'; cmpt += 1);
    result = malloc(sizeof(char) * (cmpt + 2));
    for (cmpt = i + 1, i = 0; pos[cmpt] != '\0'; cmpt += 1, i += 1)
        result[i] = pos[cmpt];
    result[i] = '\0';
    end = atoi(result);
    free(result);
    return (end);
}

char **set_alive(char **map, char **argv)
{
    int x;
    int y;

    for (int cmpt = 5; argv[cmpt]; cmpt += 1) {
        x = read_x(argv[cmpt]);
        y = read_y(argv[cmpt]);
        map[y][x] = '*';
    }
    return (map);
}

char **create_map(int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));

    for (int line = 0; line < y; line += 1) {
        map[line] = malloc(sizeof(char) * (x + 1));
        for (int col = 0; col < x; col += 1)
            map[line][col] = ' ';
        map[line][x] = '\0';
    }
    map[y] = NULL;
    return (map);
}

void free_map(char **map)
{
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
        free(map[cmpt]);
    free(map);
}

#include "../includes/my.h"

int main(int argc, char **argv)
{
    char **map;

    if (strcmp(argv[1], "--help") == 0) {
        display_help();
        return (0);
    }
    if (error_gestion(argc, argv) == 84)
        return (84);
    map = create_map(atoi(argv[3]), atoi(argv[4]));
    map = set_alive(map, argv);
    if (choose_game(argv[1], map, atoi(argv[2])) == 84)
        return (84);
    free_map(map);
    return (0);
}

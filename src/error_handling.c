#include "../includes/my.h"

int is_a_number(char *string)
{
    for (int cmpt = 0; string[cmpt] != '\0'; cmpt += 1)
        if (string[cmpt] < '0' || string[cmpt] > '9')
            return (84);
    return (0);
}

int cellule_handling(int argc, char **argv)
{
    int finded;

    for (int cmpt = 5; cmpt < argc; cmpt += 1) {
        finded = 1;
        for (int i = 0; argv[cmpt][i] != '\0'; i += 1)
            if (argv[cmpt][i] == '-')
                finded -= 1;
        if (finded != 0) {
            write(2, "invalid cell position\n", 22);
            return (84);
        }
    }
    return (0);
}

int error_gestion(int argc, char **argv)
{
    if (argc < 5) {
        write(2, "too few arguments\n", 18);
        return (84);
    }
    if (atoi(argv[2]) < 1 || atoi(argv[3]) < 1 || atoi(argv[4]) < 1) {
        write(2, "too few number\n", 15);
        return (84);
    }
    if (is_a_number(argv[2]) == 84 || is_a_number(argv[3]) == 84 ||
    is_a_number(argv[4]) == 84) {
        write(2, "not a number\n", 13);
        return (84);
    }
    if (cellule_handling(argc, argv) == 84)
        return (84);
    return (0);
}

void display_help(void)
{
    printf("  _______________________________________________________________\n");
    printf(" |                                                               |\n");
    printf(" | This binary create an array with a defined size.              |\n");
    printf(" | It also display cells at each iteration.                      |\n");
    printf(" | Usage : ./game_of_life [type] [iterations] [x] [y] [cells]... |\n");
    printf(" |    - type: game_of_life, hight_life, day_night or life_34     |\n");
    printf(" |    - cells: \"x-y\"                                             |\n");
    printf(" |                                                               |\n");
    printf(" |                                                       Donat.  |\n");
    printf(" |_______________________________________________________________|\n\n");
}

#include <stdlib.h>
#include <stdio.h>

void afficher()
{
    printf("┏━━━┳━━━┳━━━┳━━━┳━━━┓\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("┃ ");
        printf("\033[0;31m");
        printf("\x1b[1m");
        printf("● ");
        printf("\033[0m");
    }
    printf("┃\n┣━━━╋━━━╋━━━╋━━━╋━━━┫\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("┃ ");
        printf("\033[0;31m");
        printf("\x1b[1m");
        printf("● ");
        printf("\033[0m");
    }
    printf("┃\n┣━━━╋━━━╋━━━╋━━━╋━━━┫\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("┃ ");
        printf("\033[0;31m");
        printf("\x1b[1m");
        printf("● ");
        printf("\033[0m");
    }
    printf("┃\n┣━━━╋━━━╋━━━╋━━━╋━━━┫\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("┃ ");
        printf("\033[0;31m");
        printf("\x1b[1m");
        printf("● ");
        printf("\033[0m");
    }
    printf("┃\n┣━━━╋━━━╋━━━╋━━━╋━━━┫\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("┃ ");
        printf("\033[0;31m");
        printf("\x1b[1m");
        printf("● ");
        printf("\033[0m");
    }
    printf("┃\n┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

int main()
{
    char *str = "❤️";
    printf("%s\n", str);
    printf("┏━━━┳━━━┳━━━┳━━━┳━━━┓\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("┃ ");
        printf("\033[0;31m");
        printf("\x1b[1m");
        printf("● ");
        printf("\033[0m");
    }
    printf("┃\n");

    printf("Hello\n");
    afficher();
    return 0;
}

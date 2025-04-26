#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

Point snake[100];
int snake_length = 1;
Point food;
int game_over = 0;
char direction = 'd'; // d: derecha, a: izquierda, w: arriba, s: abajo

void initialize_game() {
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

void draw_board() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf("#");
            } else if (i == snake[0].y && j == snake[0].x) {
                printf("O");
            } else if (i == food.y && j == food.x) {
                printf("F");
            } else {
                int is_body = 0;
                for (int k = 1; k < snake_length; k++) {
                    if (snake[k].x == j && snake[k].y == i) {
                        printf("o");
                        is_body = 1;
                        break;
                    }
                }
                if (!is_body) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void update_snake() {
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    if (direction == 'w') snake[0].y--;
    if (direction == 's') snake[0].y++;
    if (direction == 'a') snake[0].x--;
    if (direction == 'd') snake[0].x++;

    if (snake[0].x == 0 || snake[0].x == WIDTH - 1 || snake[0].y == 0 || snake[0].y == HEIGHT - 1) {
        game_over = 1;
    }

    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            game_over = 1;
        }
    }

    if (snake[0].x == food.x && snake[0].y == food.y) {
        snake_length++;
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
    }
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if ((key == 'w' && direction != 's') || (key == 's' && direction != 'w') ||
            (key == 'a' && direction != 'd') || (key == 'd' && direction != 'a')) {
            direction = key;
        }
    }
}

void snake_unit() {
    char restart_key;
    do {
        srand(time(NULL));
        initialize_game();
        game_over = 0;

        while (!game_over) {
            draw_board();
            input();
            update_snake();
            Sleep(100);
        }

        printf("Game Over! Puntuación: %d\n", snake_length - 1);
        printf("Presiona cualquier tecla para reiniciar o 'R' para salir.\n");
        restart_key = _getch();
    } while (restart_key != 'R' && restart_key != 'r');
}

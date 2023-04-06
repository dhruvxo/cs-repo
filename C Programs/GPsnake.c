#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position head;
    Position tail[WIDTH * HEIGHT - 1];
    int size;
} Snake;

typedef struct {
    int x, y;
} Food;

enum Direction { UP, DOWN, LEFT, RIGHT };

char game_board[HEIGHT][WIDTH];

void draw_board()
{
    system("cls");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", game_board[i][j]);
        }
        printf("\n");
    }
}

void move_snake(Snake *snake, enum Direction dir)
{
    // move the tail
    for (int i = snake->size - 1; i > 0; i--) {
        snake->tail[i] = snake->tail[i - 1];
    }
    snake->tail[0] = snake->head;

    // move the head
    switch (dir) {
        case UP:
            snake->head.y--;
            break;
        case DOWN:
            snake->head.y++;
            break;
        case LEFT:
            snake->head.x--;
            break;
        case RIGHT:
            snake->head.x++;
            break;
    }
}

void place_food(Food *food)
{
    // find an empty spot for the food
    do {
        food->x = rand() % WIDTH;
        food->y = rand() % HEIGHT;
    } while (game_board[food->y][food->x] != ' ');
    // place the food
    game_board[food->y][food->x] = '*';
}

int check_collision(Snake *snake)
{
    // check if the head of the snake collides with the walls
    if (snake->head.x < 0 || snake->head.x >= WIDTH || snake->head.y < 0 || snake->head.y >= HEIGHT) {
        return 1;
    }
    // check if the head of the snake collides with the tail
    for (int i = 0; i < snake->size - 1; i++) {
        if (snake->head.x == snake->tail[i].x && snake->head.y == snake->tail[i].y) {
            return 1;
        }
    }
    return 0;
}

void init_game(Snake *snake, Food *food)
{
    // initialize the game board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                game_board[i][j] = '#';
            } else {
                game_board[i][j] = ' ';
            }
        }
    }
    // initialize the snake
    snake->head.x = WIDTH / 2;
    snake->head.y = HEIGHT / 2;
    snake->size = 1;
    // initialize the food
    place_food(food);
}

int main()
{
    Snake snake;
    Food food;
    int score = 0;
    enum Direction dir = RIGHT;

    init_game(&snake, &food);

    while (1) {
        draw_board();
        printf("Score: %d\n", score);
        // move the snake
        move_snake(&snake, dir);
        // check for collision
        if (check_collision(&snake)) {
            printf("Game over!\n");
            printf("Your score: %d\n", score);
            break;
        }
        // check if the snake eats the food
        if (snake.head.x == food.x && snake.head.y == food.y) {
            snake.size++;
            score++;
            place_food(&food);
        }
        // update the game board
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == snake.head.y && j == snake.head.x) {
                    game_board[i][j] = 'O';
                } else if (i == food.y && j == food.x) {
                    game_board[i][j] = '*';
                } else {
                    int is_tail = 0;
                    for (int k = 0; k < snake.size - 1; k++) {
                        if (i == snake.tail[k].y && j == snake.tail[k].x) {
                            game_board[i][j] = 'o';
                            is_tail = 1;
                            break;
                        }
                    }
                    if (!is_tail) {
                        game_board[i][j] = ' ';
                    }
                }
            }
        }
        // wait for input
        if (_kbhit()) {
            int ch = _getch();
            switch (ch) {
                case 'w':
                case 'W':
                    if (dir != DOWN) {
                        dir = UP;
                    }
                    break;
                case 's':
                case 'S':
                    if (dir != UP) {
                        dir = DOWN;
                    }
                    break;
                case 'a':
                case 'A':
                    if (dir != RIGHT) {
                        dir = LEFT;
                    }
                    break;
                case 'd':
                case 'D':
                    if (dir != LEFT) {
                        dir = RIGHT;
                    }
                    break;
                case 'x':
                case 'X':
                    printf("Game over!\n");
                    printf("Your score: %d\n", score);
                    return 0;
            }
        }
        // wait for some time
        Sleep(100);
    }

    return 0;
}

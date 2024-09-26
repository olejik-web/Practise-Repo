#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

int get_min(int a, int b) {
    int value = a;
    if (value > b) value = b;
    return value;
}

void get_digit(char char_buf[], int digit, int line_num) {
    char digits[10][5][4] = {
        {
            {'#', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', '#', '#', '\0'}
        },
        {
            {' ', ' ', '#', '\0'},
            {' ', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {' ', ' ', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {'#', '#', '#', '\0'},
            {'#', ' ', ' ', '\0'},
            {'#', '#', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {'#', '#', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {'#', '#', '#', '\0'}
        },
        {
            {'#', ' ', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', '#', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {' ', ' ', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {'#', ' ', ' ', '\0'},
            {'#', '#', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {'#', '#', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {'#', ' ', ' ', '\0'},
            {'#', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', '#', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {' ', ' ', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', '#', '#', '\0'}
        },
        {
            {'#', '#', '#', '\0'},
            {'#', ' ', '#', '\0'},
            {'#', '#', '#', '\0'},
            {' ', ' ', '#', '\0'},
            {'#', '#', '#', '\0'}
        },
    };
    strcat(char_buf, digits[digit][line_num]); //s2
}

void get_line(char value_char_buf[], int line_num, int value) {
    if (value == 0) {
        get_digit(value_char_buf, 0, line_num);
        strcat(value_char_buf, " ");
    }
    else {
        int tmp_value = value;
        int cnt = 0;
        while (tmp_value > 0) {
            tmp_value = tmp_value / 10;
            cnt++;
        }
        int digits[20];
        for (int i = cnt - 1; i > -1; i--) {
            digits[i] = value % 10;
            value = value / 10;
        }
        for (int i = 0; i < cnt; i++) {
            get_digit(value_char_buf, digits[i], line_num);
            strcat(value_char_buf, " ");
        }
    }
}

int get_sym_cnt_of_value(int value) {
    int cnt = 0;
    if (value == 0)
        cnt = 1;
    else {
        while (value > 0) {
            value = value / 10;
            cnt++;
        }
    }
    return cnt * 4;
}

void add_delimeter(char value_char_buf[], int line_num) {
    char delimeter[5][3] = {
     {' ', ' ', '\0'},
     {'#', ' ', '\0'},
     {' ', ' ', '\0'},
     {'#', ' ', '\0'},
     {' ', ' ', '\0'}
    };
    strcat(value_char_buf, delimeter[line_num]);
}

void print_left_indent(int left_indent) {
    for (int i = 0; i < left_indent; i++) {
        printf(" ");
    }
}

void print_down_indent(int down_indent) {
    for (int i = 0; i < down_indent; i++) {
        printf("\r\n");
    }
}

void print_game_score(int first_value, int second_value, int left_indent) {
    char game_score_buf[5][10000] = {
        "",
        "",
        "",
        "",
        ""
    };
    int sym_cnt = get_sym_cnt_of_value(second_value) + 
        get_sym_cnt_of_value(first_value) + 4;
    for (int i = 0; i < 5; i++) {
        get_line(game_score_buf[i], i, first_value);
        add_delimeter(game_score_buf[i], i);
    }
    for (int i = 0; i < 5; i++) {
        get_line(game_score_buf[i], i, second_value);
    }
    for (int i = 0; i < 5; i++) {
        print_left_indent(left_indent);
        for (int j = 0; j < get_min(10000, sym_cnt); j++) {
            printf("%c", game_score_buf[i][j]);
        }
        printf("\r\n");
    }

}

int get_rocket1_positon(char game_field[][80], int y_ceils[]) {
    int x = 3;
    for (int i = 0; i < 3; i++) {
        game_field[y_ceils[i]][x] = '#';
    }
    return 0;
}

int get_rocket2_positon(char game_field[][80], int y_ceils[]) {
    int x = 76;
    for (int i = 0; i < 3; i++) {
        game_field[y_ceils[i]][x] = '#';
    }
    return 0;
}

void get_ball_position(char game_field[][80], int ball_cord_x, int ball_cord_y) {
    game_field[ball_cord_y][ball_cord_x] = '@';
}

void print_game_field(char game_field[][80], int y_ceils_rocket1[], int y_ceils_rocket2[], 
    int ball_cord_x, int ball_cord_y) {
    int width = 80;
    int height = 25;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == height - 1 || i == 0)
                game_field[i][j] = '#';
            else {
                game_field[i][j] = ' ';
            }
        }
    }
    get_rocket1_positon(game_field, y_ceils_rocket1);
    get_rocket2_positon(game_field, y_ceils_rocket2);
    get_ball_position(game_field, ball_cord_x, ball_cord_y);
    for (int i = 0; i < height; i++) {
        print_left_indent(20);
        for (int j = 0; j < width; j++) {
            printf("%c", game_field[i][j]);
        }
        printf("\r\n");
    }
}

void clear_screan() {
    for (int i = 0; i < 10; i++) {
        printf("\r\n\n\n\n\n\n\n\n\n\n");
    }
}

void execute_event(int y_ceils_rocket1[], int y_ceils_rocket2[],  char event) {
    int speed = 2;
    if (event == 'a' || event == 'A') {
        int start_pos = y_ceils_rocket1[0];
        if (y_ceils_rocket1[0] > 1) {
            for (int i = 0; i < 3; i++) {
                y_ceils_rocket1[i] = y_ceils_rocket1[i] - get_min(speed, start_pos - 1);
            }
        }
    }
    if (event == 'z' || event == 'Z') {
        int start_pos = y_ceils_rocket1[0];
        if (y_ceils_rocket1[2] < 23) {
            for (int i = 0; i < 3; i++) {
                y_ceils_rocket1[i] = y_ceils_rocket1[i] + get_min(speed, 23 - start_pos);
            }
        }
    }
    if (event == 'k' || event == 'K') {
        int start_pos = y_ceils_rocket2[0];
        if (y_ceils_rocket2[0] > 1) {
            for (int i = 0; i < 3; i++) {
                y_ceils_rocket2[i] = y_ceils_rocket2[i] - get_min(speed, start_pos - 1);
            }
        }
    }
    if (event == 'm' || event == 'M') {
        int start_pos = y_ceils_rocket2[0];
        if (y_ceils_rocket2[2] < 23) {
            for (int i = 0; i < 3; i++) {
                y_ceils_rocket2[i] = y_ceils_rocket2[i] + get_min(speed, 23 - start_pos);
            }
        }
    }
}

void move_ball(char game_field[][80], int* x, int* y, int vector[], int *ball_side) {
    if (*x < 1) *ball_side = 1;
    if (*x > 78) *ball_side = 2;
    if (*x < 1 || *x > 78) {
        *x = 39;
        *y = 11;
        int ways[3] = {-1, 1};
        vector[0] = ways[rand() % 2];
        vector[1] = ways[rand() % 2];
        *x = rand() % 55;
        *y = rand() % 25;
        if (*y < 6) {
            *y = *y + 10;
        }
        if (*x < 20) {
            *x = *x + 15;
        }
    }
    int new_x = *x + vector[0];
    int new_y = *y + vector[1];
    if (game_field[new_y][new_x] == '#'
        && game_field[new_y][*x] != '#' && game_field[*y][new_x] != '#') {
        vector[0] = vector[0] * -1;
        vector[1] = vector[1] * -1;
    }
    else {
        if (game_field[new_y][*x] == '#')
            vector[1] = vector[1] * -1;
        if (game_field[*y][new_x] == '#')
            vector[0] = vector[0] * -1;
    }
    *x = *x + vector[0];
    *y = *y + vector[1];
}

void edit_play_score(int* first_value, int* second_value, int ball_side) {
    if (ball_side != 3) {
        if (ball_side == 1) {
            *second_value = *second_value + 1;
        }
        else {
            *first_value = *first_value + 1;
        }
    }
}

int get_winner(int first_value, int second_value, int win_value) {
    int winner = 3;
    if (first_value == win_value) {
        winner = 1;
    }
    if (second_value == win_value) {
        winner = 2;
    }
    return winner;
}

void print_congratulations(int winner, int first_value, int second_value) {
    clear_screan();
    print_left_indent(40);
    printf("Player %d won! Congratulations!!!", winner);
    print_down_indent(3);
    print_game_score(first_value, second_value, 50);
    print_down_indent(6);
}

struct termios orig_termios;

void disableRawModule() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawModule);

    struct termios raw = orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
    enableRawMode();
    int first_value, second_value;
    first_value = 0;
    second_value = 0;
    int left_indent = 50;
    int y_ceils_rocket1[3] = { 11, 12, 13 };
    int y_ceils_rocket2[3] = { 11, 12, 13 };
    int ball_x = 39;
    int ball_y = 11;
    int move_vector[2] = { 1, -1 };
    char game_field[25][80];
    int win_value = 21;
    int winner = 3;
    while (1) {
        char event = 'w';
        read(STDIN_FILENO, &event, 1);
        clear_screan();
        print_game_field(game_field, y_ceils_rocket1, y_ceils_rocket2, ball_x, ball_y);
        print_down_indent(1);
        print_game_score(first_value, second_value, left_indent);
        print_down_indent(4);
        execute_event(y_ceils_rocket1, y_ceils_rocket2, event);
        int ball_side = 3;
        move_ball(game_field, &ball_x, &ball_y, move_vector, &ball_side);
        edit_play_score(&first_value, &second_value, ball_side);
        winner = get_winner(first_value, second_value, win_value);
        if (winner < 3) {
            break;
        }
        for (int i = 0; i < 20000000; i++) {
            // int k = 1;
        }
        // event = 'q';
        /* char c = '\0';
        read(STDIN_FILENO, &c, 1);
        if (iscntrl(c)) {
            printf("%d\r\n", c);
        } else {
            printf("%d ('%c')\r\n", c, c);
        }*/
        // if (event == 'q') break;
    }
    print_congratulations(winner, first_value, second_value);
    return 0;
}
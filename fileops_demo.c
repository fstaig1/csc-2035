#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRST_CHAR 32
#define LAST_CHAR 126 
#define ROW_SIZE 7

const char* FILE_NAME = "printable_ascii.txt";

void write_table();
void read_table();
void get_char_row(char* row, int code);
void exit_failure(char* cmd);

int main(int argc, char** argv) {
    if (argc < 2)
        exit_failure(argv[0]);
    
    int opt = atoi(argv[1]);
    
    switch(opt) {
        case 0:
            write_table();
            break;
        case 1:
            read_table();
            break;
        case 2:
            if (argc < 3) {
                exit_failure(argv[0]);
            } else {
                int code = atoi(argv[2]);
                char row[ROW_SIZE];
                get_char_row(row, code);
                printf("%s", row);
            }
            break;
        default:
            exit_failure(argv[0]);
    }      
                
    return EXIT_SUCCESS;
}

void write_table() {
    FILE* f = fopen(FILE_NAME, "w");

    for (int i = FIRST_CHAR; i < LAST_CHAR + 1; i++) {
        fprintf(f, "%c:%03d\n", i, i);
    }
    return;
}

void read_table() {
    FILE* f = fopen(FILE_NAME, "r");

    char row[ROW_SIZE];

    while (fgets(row, ROW_SIZE, f)) {
        row[ROW_SIZE -1] = '\0';

        printf("%s", row);
    }
    fclose(f);
    return;
}

void get_char_row(char* row, int code) {
    if (code < FIRST_CHAR || code > LAST_CHAR) {
        strncpy(row, "undef\n", ROW_SIZE - 1);
        row[ROW_SIZE - 1] = '\0';
        return;
    }
    
    int line_num = code - FIRST_CHAR;
    
    printf("replace this with code to seek to line: %d\n"
            "and read that line into row\n", line_num);
}

void exit_failure(char* cmd) {
    printf("usage: %s 0|1|2 code\n", cmd);
    exit(EXIT_FAILURE);
}
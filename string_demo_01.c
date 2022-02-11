#include <stdio.h>
#include <string.h>

#define MAX_LEN 128     // used to limit strnlen searches
#define ARRAY_SIZE 5

void print_charbychar(char* sname, char* s, size_t size);

int main(int argc, char** argv) {
    char c1 = 'z';
    char c2 = 'y';
    
    char s1[ARRAY_SIZE];  // character array

    for (int i = 0; i < ARRAY_SIZE; i++) {
        s1[i] = 'a' + (i % 26);
    }
    s1[ARRAY_SIZE - 1] = '\0';
    
    char c3 = 'x';
    char c4 = 'w';
    
    char* s2 = "a"; 

    // print addresses, sizes, values and string lengths 
    printf("----------------------------------------------------------\n");
    printf("c1 addr: %p, size: %zu, val: %c\n", &c1, sizeof(c1), c1);
    printf("c2 addr: %p, size: %zu, val: %c\n", &c2, sizeof(c2), c2);
    printf("c3 addr: %p, size: %zu, val: %c\n", &c3, sizeof(c3), c3);
    printf("c4 addr: %p, size: %zu, val: %c\n\n", &c4, sizeof(c4), c4);
    
    printf("s1 addr: %p, size: %zu, val: %s\n", s1, sizeof(s1), s1);
    printf("   strlen(s1): %zu, strnlen(s1, MAX_LEN): %zu\n", strlen(s1), strnlen(s1, MAX_LEN));
    printf("s2 addr: %p, size: %zu, val: %s\n", s2, sizeof(s2), s2);
    printf("   strlen(s2): %zu, strnlen(s2, MAX_LEN): %zu\n", strlen(s2), strnlen(s2, MAX_LEN));
    printf("----------------------------------------------------------\n");
    
    print_charbychar("s1", s1, strnlen(s1, MAX_LEN) + 1); 
    print_charbychar("s2", s2, strnlen(s2, MAX_LEN) + 1);
}

 void print_charbychar(char* sname, char* s, size_t size) {
    int nul_posn = -1;
    printf("printing from start of %s, char by char, for %zu bytes:\n", 
        sname, size);
    for (int i = 0; i < size; i++) {
        if (s[i]) {
            printf("s[%d]: %c\n", i, s[i]);
        } else {
            printf("s[%d]: %s\n", i, "\\0");
            
            if (nul_posn < 0) 
                nul_posn = i;
        }
    }
    
    if (nul_posn < 0) {
        printf("no nul (0) terminator found in first %zu bytes\n", size);
    } else {
        printf("first nul (0) terminator found at position: %d\n", nul_posn);
    }
    
    printf("----------------------------------------------------------\n");
}

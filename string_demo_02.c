/*
 * See specification of functions before their declarations and the comments
 * to the initial implementation of buf_arg_infstr
 *
 * To use asprintf on a Linux machine, use the following compilation flags:
 * -std=c99 -D_GNU_SOURCE
 * e.g.
 * cc  -std=c99 -D_GNU_SOURCE string_demo_02.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 24 
                // size of string buffer, length will be MAX_BUF_SIZE - 1
#define MAX_STR_LEN 128 // limit for string length searches
#define _GNU_SOURCE

/* 
 * The buf_arg_infstr function takes the following parameters:
 * buf - a pointer to a character array of size MAX_BUF_SIZE
 * argc - the argument count for this program
 * cmd  - the command used to execute this program
 * arg1 - the first argument to the command
 *
 * it writes a string in the following format to the given buf:
 * 
 *      <arg_num>:<cmd_len>:<cmd_stem>:<arg1_len>:<arg1_stem>
 * where:
 * arg_num is the number of arguments to the command (not including the 
 * command). 
 * cmd_len is the length of the command string before truncation
 * cmd_stem is the command string truncated to a length of no more than 8 
 * characters (i.e. cmd_stem is the first 8 characters of cmd)
 * arg1_len is the length of the arg1 string before truncation
 * arg1_stem is the arg1 string truncated to a length of no more than 5 
 * characters (i.e. arg1_stem is the first 5 character of arg1)
 *
 * The angle brackets are not in the output, they just indicate the 
 * component is mandatory.
 *
 * The numbers written to buf (arg_num, cmd_len and arg1_len) will be exactly
 * 2 digits and have a leading 0 if a number is less than 10. That is, their  
 * output will be in the range 00 to 99.
 *
 * If arg1 is NULL, then the string "null" will be output for arg1_stem. 
 *
 * The function returns a pointer to the resulting formatted string. This 
 * will be a pointer to the provided buffer if there are no errors and NULL
 * if any errors are detected.
 *
 * An example of a correctly formatted string for the following invocation 
 * of the program:
 * ./a.out hello
 * 
 * is: 01:07:./a.out:05:hello
 *
 * for:
 *  ./string_demo_02 goodbye
 * 
 * it is: 01:16:./string:07:goodb
 *
 */ 
char* buf_arg_infstr(char* buf, int argc, char* cmd, char* arg1);

/*
 * new_arg_infstr has the same result (for the same input) as buf_arg_infstr.
 * The difference is that it dynamically allocates the string buffer to write 
 * to (hint: see asprintf).
 */
char* new_arg_infstr(int argc, char* cmd, char* arg1);

/*
 * arg_infstr has the same results (for the same input) as buf_arg_infstr or
 * new_arg_infstr.
 *
 * if the buf parameter is not NULL, it writes the string to buf
 * if the buf parameter is NULL, it dynamically allocates the string
 */
char* arg_infstr(char* buf, int argc, char* cmd, char* arg1);

int main(int argc, char** argv) {
    printf("-------------------------------\nusing buf_arg_infstr:\n");
    char buf1[MAX_BUF_SIZE];
    char* buf_str = buf_arg_infstr(buf1, argc, argv[0], argv[1]);
    if (buf_str) {
        // buf_str == buf1, it is the address of buf1 - you can check this
        printf("buf_str: %s\n", buf1);
        printf("strnlen(buf_str, MAX_STR_LEN): %zu\n", 
                strnlen(buf_str, MAX_STR_LEN));
    } else {
        printf("buf_arg_infstr result is NULL\n");
    }
    
    printf("\n-------------------------------\nusing new_arg_infstr:\n");
    
    char* new_str = new_arg_infstr(argc, argv[0], argv[1]);    
    if (new_str) {
        printf("new_str: %s\n", new_str);
        printf("strnlen(new_str, MAX_STR_LEN): %zu\n", 
                strnlen(new_str, MAX_STR_LEN));
    } else {
        printf("buf_arg_infstr result is NULL\n");
    }
    free(new_str);
    
    printf("\n-------------------------------\nusing arg_infstr:\n");
    char buf2[MAX_BUF_SIZE];
    char* buf2_str = arg_infstr(buf2, argc, argv[0], argv[1]);
    if (buf2_str) {
        printf("buf2_str: %s\n", buf2_str);
        printf("strnlen(buf2_str, MAX_STR_LEN): %zu\n", 
                    strnlen(buf2_str, MAX_STR_LEN));
    } else {
        printf("arg_infstr result is NULL\n");
    }
    
    // pass NULL as first parameter to dynamically allocate string
    char* buf2_str_onheap = arg_infstr(NULL, argc, argv[0], argv[1]);
    
    if (buf2_str_onheap) {
        printf("\nbuf2_str_onheap: %s\n", buf2_str_onheap);
        printf("strnlen(buf2_str_onheap, MAX_STR_LEN): %zu\n", 
                    strnlen(buf2_str_onheap, MAX_STR_LEN));
        
        free(buf2_str_onheap);
    } else {
        printf("arg_infstr result is NULL\n");
    }
    
    return 0;
}

/* 
 * First try compiling and running the program as follows:
 *      cc string_demo_02.c 
 *      ./a.out hello
 * Then try:
 * 
 *      cc string_demo_02.c -o string_demo_02.c
 *      ./string_demo_02 goodbye
 * 
 * Does the buf_arg_infstr satisfy its specification?
 * What happens if there are no arguments to the program?
 * What happens if buf is NULL? 
 *
 * Correct the function until it produces the formatted string specified
 * in the function specification and also handles error cases.
 *
 * Hints: 
 * - producing the correct string is mostly about changing the directives
 * in the fmt string
 * - error handling is about checking parameters
 */
char* buf_arg_infstr(char* buf, int argc, char* cmd, char* arg1) {
    char* fmt = "%02d:%02d:%.8s:%02d:%.5s";
    
    if (!buf)
        return NULL;
        
    if (!arg1)
        arg1 = "null";
    
    int r = snprintf(buf, MAX_BUF_SIZE, fmt, argc - 1, 
                strnlen(cmd, MAX_STR_LEN), cmd, 
                strnlen(arg1, MAX_STR_LEN), arg1);  
                
    return r < 0 ? NULL : buf;
}

char* new_arg_infstr(int argc, char* cmd, char* arg1) {
    char* fmt = "%02d:%02d:%.8s:%02d:%.5s";
    if (!arg1)
        arg1 = "null";
   
    char* buf;
    
    int r = asprintf(&buf, fmt, argc - 1, 
                strnlen(cmd, MAX_STR_LEN), cmd, 
                strnlen(arg1, MAX_STR_LEN), arg1); 
     
    return buf;
    
}

char* arg_infstr(char* buf, int argc, char* cmd, char* arg1) {
    char* fmt = "%02d:%02d:%.8s:%02d:%.5s";
    char* result_str;
    
    if (!arg1)
        arg1 = "null";

    if (buf) { 
        int r = snprintf(buf, MAX_BUF_SIZE, fmt, argc - 1, 
                    strnlen(cmd, MAX_STR_LEN), cmd, 
                    strnlen(arg1, MAX_STR_LEN), arg1);
                
        result_str = r < 0 ? NULL : buf;
    } else {
        int r = asprintf(&result_str, fmt, argc - 1, 
                    strnlen(cmd, MAX_STR_LEN), cmd, 
                    strnlen(arg1, MAX_STR_LEN), arg1); 
    }
        
    return result_str;
}

/* 
 * Given we have defined buf_arg_infstr and new_arg_infstr, an alternative 
 * would be to write arg_infstr in terms of the other two functions, as 
 * follows. If we were writing, arg_infstr from scratch without the other two 
 * functions it is simple enough to write as a single function and doesn't need
 * helper functions.

char* arg_infstr(char* buf, int argc, char* cmd, char* arg1) {
    return buf ? buf_arg_infstr(buf, argc, cmd, arg1)
                : new_arg_infstr(argc, cmd, arg1);
}
*/

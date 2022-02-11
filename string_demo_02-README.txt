This demonstration/exercise is directly related to assignment 1 release 1 
and will help you undersand and complete parts of the assignment.

In demonstrations in class you have seen me use printf to output strings
to console (STDOUT) and to use a format string to specify the format 
of the string to output.

It is a common to want to produce formatted strings for output or to 
be stored in a file or a database or somewhere else.

It is also common to have to need to restrict the total length of a formatted
string and the length of individual components. For example, the string may 
be used as the input for a fixed length field in a database.

Therefore, it can be useful therefore to write library/helper functions to
generate strings in the correct format.

Two alternative approaches to this are:

- to write the formatted string to a user-provided buffer and ensuring that the
resulting string is correctly formatted and well-formed with a NUL terminator

- dynamically allocate a buffer for the user and write the string to the 
new buffer, and making sure the resulting string is correctly formatted 
and terminated.

The advantage of writing helper/library functions for this is that the helper 
function can do the one task of producing the correctly formatted string 
and leave it up to the user to decide what to do with the string (write it to 
file, output to STDOUT, store in a database etc.). This is a simple example of 
separation of concerns and doing one (useful) thing well (part of good 
practice and the "Unix philosophy").

Writing such functions is straightforward using the printf family of C 
library functions (and the GNU library function asprintf).

In this demo we will see how to do it

You will need:
    - the string_demo_02.c file
    - to look at man pages for sprintf, snprintf, asprintf, strlen and strnlen
        - you can look these up at https://www.kernel.org/doc/man-pages/
          see: https://man7.org/linux/man-pages/man3/sprintf.3.html for 
          the printf family, that includes information on specifying print 
          formats. asprintf has a separate man page.

We will start the demo/exercise together and then you will complete the 
following three functions in string_demo_02.c:

char* buf_arg_infstr(char* buf, int argc, char* cmd, char* arg1);
char* new_arg_infstr(int argc, char* cmd, char* arg1);
char* arg_infstr(char* buf, int argc, char* cmd, char* arg1);

The specification and starting point for the functions is in string_demo_02.c 
along with a simple main function to see how they behave.
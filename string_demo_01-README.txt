Make the following changes to the string_demo_01.c.

After each change compile the program with the following command:

    $ cc string_demo_01.c

And then run it with the following command:

    $ ./a.out

Before you run the program, think about the output you expect. For
example, what do you expect from printing a string character by
character.

After you run the program, look at the program output and try to work
out the effect of the change and what it is demonstrating. What does it
tell you about the way strings are formed and how objects are stored in
memory?

Look at man pages for sizeof, strlen and strnlen.

--------------------------------------------------------------------------
Exercise 1

After the following line:

    print_charbychar("s1", s1, ARRAY_SIZE);
    
add a line to print the string s2 character by character using 
print_charbychar. Use the following parameters to the function:

sname: "s2"
s:     s2
size:  strnlen(s2, MAX_LEN) + 1

Compile the program, run it again, and look at the output.

Do you understand why the output for s1 and s2 is different? Which is a 
well-formed string?

--------------------------------------------------------------------------
Exercise 2

Change the value of ARRAY_SIZE at line 5.

Try different values for ARRAY_SIZE and at least try a value over 26.

Recompile and re-run the program after each change.

What happens when the ARRAY_SIZE is greater than 26? Why?

To reduce output for subsequent exercises, change the value of ARRAY_SIZE
back to a value between 1 and 10.

--------------------------------------------------------------------------
Exercise 3

Change the size parameter to the function call:
    
    print_charbychar("s1", s1, ARRAY_SIZE);
    
from ARRAY_SIZE to: strnlen(s1, MAX_LEN) + 1

Compile the program, run it again, and look at the output.

Is the character by character output for s1 now the same as the output
from the printf call on line 28? Why?

--------------------------------------------------------------------------
Exercise 4

Now use increasing values for the size parameter to the print_charbychar 
call for s1, e.g.:

    print_charbychar("s1", s1, 50);

Compile and re-run and then change the size parameter again, e.g. try 
size 100, 200, 1000, 2000, 3000 and so on.

What is happening for each increase in size? What information is being
printed out?

Does the program crash for a high value for the size? Why?

Comment out line 40 by inserting // before print_charbychar

--------------------------------------------------------------------------
Exercise 5

Comment out the print_charbychar function call for s1. That is, insert //
before print_charbychar("s1", s1, ...)

Change string s2 by adding extra characters to the string at line 22.

You can do this in stages. Just make sure you try one string of at least
10 characters.

Compile the program and re-run the program after each change you make to 
s2.

Why does the size output for string s2 at line 34 not change when you 
change the string s2?

--------------------------------------------------------------------------
Exercise 6

Do exercise 4 but for the print_charbychar call for s2. That is, keep 
increasing the size parameter to the call, recompiling and running the 
program again until it crashes.

After you have found a value for the size parameter that crashes the 
program, return the line to:

      print_charbychar("s2", s2, strnlen(s2, MAX_LEN) + 1);
  
--------------------------------------------------------------------------
Exercise 7

Uncomment the line:

    // print_charbychar("s1", s1, ...);
    
And edit the size parameter so that the line is:

    print_charbychar("s1", s1, strnlen(s1, MAX_LEN) + 1); 
    
After the loop at line 15 (on line 18) add the following line:
    
    s1[ARRAY_SIZE - 1] = '\0';
    
Recompile and re-run the program.

Does s1 now behave like s2?

Is s1 now a well-formed string?

Try the program with different values for ARRAY_SIZE.

Does s1 still behave like a well-formed string?
 
To see the difference run the program with:

     s1[ARRAY_SIZE - 1] = '\0';

uncommented. And with it commented out:
    
    // s1[ARRAY_SIZE - 1] = '\0';

--------------------------------------------------------------------------
  



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Smith-Waterman.h"

int main(int argc, char **argv)
{
    // first command line argument (stored in argv[1]) is the csv filename
    // open the csv file
    // load in csv line-by-line (ignoring lines starting by #;
    //                           you can assume that a line will be never
    //                           longer than 256 characters)
    // for each line:
    //   read string up to `,' as the first string
    //   read string after `,' up to the newline character as the second string
    //   remove whitespace at the start and end of each string
    //   call `print_smith_waterman' with the first and second string
    // close the csv file

    return EXIT_SUCCESS;
}
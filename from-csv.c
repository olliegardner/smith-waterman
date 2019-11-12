#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // used for isspace()

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

    FILE *file = fopen(argv[1], "r");

    if (file != NULL)
    {
        char line[256];

        while (fgets(line, sizeof line, file) != NULL)
        {            
            if (line[0] != '#')
            {
                char *token = strtok(line, ",");
                char *waterman[2];
                int w = 0;

                while (token != NULL)
                {
                    waterman[w++] = token;
                    token = strtok(NULL, ","); // when there are no tokens remaining strtok returns NULL
                }

                for (int i = 0; i < 2; i++) 
                {
                    int c = 0, d = 0;
                    char *text = waterman[i];
                    char blank[100];

                    while (text[c] != '\0')
                    {
                        if (!(text[c] == ' ' || text[c] == '\n'))
                        {
                            blank[d] = text[c];
                            d++;
                        }
                        c++;
                    }
                    blank[d] = '\0';
                    
                    waterman[i] = strdup(blank);
                }

                print_smith_waterman(waterman[0], waterman[1]);
            }
        }

        fclose(file);
    }
    else
    {
        perror("Error in opening file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

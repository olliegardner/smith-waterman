#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Smith-Waterman.h"

int main(int argc, char **argv)
{
    if (argc == 2) // if there are 2 command line arguments
    {
        FILE *file = fopen(argv[1], "r");

        if (file != NULL) // valid file name given
        {
            char line[256];

            while (fgets(line, sizeof line, file) != NULL) // while there are still lines in the file
            {            
                if (line[0] != '#') // ignore lines that start with #
                {
                    char *token = strtok(line, ","); // split the line with delimiter ,
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

                        while (text[c] != '\0') // while not at the end of the string
                        {
                            if (!(text[c] == ' ' || text[c] == '\n')) // if character is a space or new line
                            {
                                blank[d] = text[c]; // append to blank string
                                d++;
                            }
                            c++;
                        }

                        blank[d] = '\0'; // add terminating character to end of string
                        waterman[i] = strdup(blank); // get duplicate of blank string
                    }

                    print_smith_waterman(waterman[0], waterman[1]);
                }
            }

            fclose(file); // close the file
        }
        else
        {
            printf("Error in opening file.\n");
            return EXIT_FAILURE; // return exit failure
        }
    }
    else
    {
        printf("Argument format: from-csv [filename]\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#include "scoring_matrix.h"

#include <stdio.h>
#include <string.h>

// returns the max element in a given array
int find_max(int score[3])
{
    int max = 0;

    for (int i = 0; i < 3; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
        }
    }
    return max;
}

// creates the scoring matrix
scoring_matrix create_matrix(const char *a, const char *b, int match_score, int gap_cost)
{
    int height = strlen(a) + 1; // create width and height to length of string plus 1
    int width = strlen(b) + 1;
    int * data = calloc(width * height, sizeof(int)); // allocate memory and initialise array to 0

    scoring_matrix matrix = {width, height, NULL};

    if (data != NULL) // if memory allocation is successful
    {
        for (int i = 1; i < height; i++)
        {
            for (int j = 1; j < width; j++)
            {                
                // calculates scoring matrix as per formula
                int score[3];
                score[0] = *(data + ((i-1)*width) + (j-1)) + (a[i-1] == b[j-1] ? match_score : -match_score);
                score[1] = *(data + ((i-1)*width) + j) - gap_cost;
                score[2] = *(data + (i*width) + (j-1)) - gap_cost;

                *(data + i*width + j) = find_max(score); // finds the max score and adds to the data array
            }
        }

        matrix.data = data;
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return matrix;
}

void free_matrix(scoring_matrix matrix)
{
    free(matrix.data); // frees memory allocation for matrix data
    matrix.data = NULL; // good practice to assign NULL once pointer has been freed
}

// returns a view of a matrix which is essentially a subset
scoring_matrix_view matrix_as_view(scoring_matrix matrix)
{
    scoring_matrix_view view = {matrix.width, matrix.height, {matrix.width, matrix.height, matrix.data}};
    return view;
}

// loops through rows and columns of the matrix and prints the values
void print_matrix(scoring_matrix_view view)
{
    for (int i = 0; i < view.height; i++)
    {
        for (int j = 0; j < view.width; j++)
        {
            printf("%d ", *(view.matrix.data + i * view.width + j));
        }
        printf("\n");
    }
}

#include "scoring_matrix.h"

#include <stdio.h>
#include <string.h>

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

scoring_matrix create_matrix(const char *a, const char *b, int match_score, int gap_cost)
{
    int height = strlen(a) + 1;
    int width = strlen(b) + 1;
    int * data = (int*) malloc(width * height * sizeof(int));

    scoring_matrix matrix = {width, height, NULL};

    if (data != NULL) // if memory allocation is successful
    {
        for (int i = 1; i < height; i++)
        {
            for (int j = 1; j < width; j++)
            {
                if (width == 0 || height == 0)
                {
                    *(data + i*width + j) = 0;
                    continue;
                }
                
                int score[3];
                score[0] = *(data + ((i-1)*width) + (j-1)) + (a[i-1] == b[j-1] ? match_score : -match_score);
                score[1] = *(data + ((i-1)*width) + j) - gap_cost;
                score[2] = *(data + (i*width) + (j-1)) - gap_cost;

                *(data + i*width + j) = find_max(score);
            }
        }

        matrix.data = data;
        matrix_as_view(matrix);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return matrix;
}

void free_matrix(scoring_matrix matrix)
{
    free(matrix.data);   
}

scoring_matrix_view matrix_as_view(scoring_matrix matrix)
{
    scoring_matrix_view view = {matrix.width, matrix.height, {matrix.width, matrix.height, matrix.data}};
    return view;
}

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

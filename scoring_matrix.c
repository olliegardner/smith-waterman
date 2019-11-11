#include "scoring_matrix.h"

#include <stdio.h>
#include <string.h>

int calculate_score(char a, char b, int match_score)
{
    if (a != b) return -match_score;
    return match_score;
}

int get_max_value(int *data, int width, int height, const char *a, const char *b, int match_score, int gap_cost)
{
    if (width == 0 || height == 0) 
    {
        return 0;
    }

    int max = 0;
    int score[3];

    /*score[2] = data[width - 1][height - 1] + calculate_score(a[width - 1], b[height - 1], match_score);
    score[1] = data[width - 1][height] - gap_cost;
    score[0] = data[width][height - 1] - gap_cost;*/

    for (int i = 0; i < 3; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
        }
    }
    return max;
}

/*scoring_matrix create_matrix(const char *a, const char *b, int match_score, int gap_cost)
{
    int width = strlen(a);
    int height = strlen(b);
    int **data = malloc(width * sizeof *data);

    //int total_length = width * sizeof(a) + height * sizeof(b);
    //int* matrix_array = malloc(width * height * sizeof(int));

    for (int i = 0; i <= width; i++) 
    {
        data[i] = malloc(height * sizeof data[i]);
    }

    for (int i = 0; i <= width; i++) 
    {
        for (int j = 0; j <= height; j++) 
        {
            data[i][j] = get_max_value(data, i, j, a, b, match_score, gap_cost);
        }
    }

    scoring_matrix matrix = {width, height, data};
    matrix_as_view(matrix);
    
    return matrix;
}*/

int get_max(int caseone, int casetwo, int casethree) {
    int max = 0;

    if (caseone > max) {
        max = caseone;
    }
    if (casetwo > max) {
        max = casetwo;
    }
    if (casethree > max) {
        max = casethree;
    }
    return max;
}

scoring_matrix create_matrix(const char *a, const char *b, int match_score, int gap_cost)
{
    int height = strlen(a) + 1;
    int width = strlen(b) + 1;
    int * data = (int*) malloc(width * height * sizeof(int));
    //int* data = malloc(width * height * sizeof(int));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(data + i * width + j) = 0;
        }
    }

    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            int one = *(data + ((i-1)*width) + (j-1)) + (a[i-1] == b[j-1] ? match_score : -match_score);
            int two = *(data + ((i-1)*width) + j) - gap_cost;
            int three = *(data + (i*width) + (j-1)) - gap_cost;

            *(data + i*width + j) = get_max(one, two, three);

            /*if (i == 0 || j == 0) {
                *(data + i*width + j) = 0;
                continue;
            }

            if(one >= two && one >= three){
                *(data + i*width + j) = one;
            } else if(two >= three && two >= one) {
                *(data + i*width + j) = two;
            } else {   
                *(data + i*width + j) = three;
            }*/

            //*(data + i*height + j) = get_max_value(data, i, j, a, b, match_score, gap_cost);
        }
    }

    scoring_matrix matrix = {width, height, data};
    matrix_as_view(matrix);

    return matrix;
}

void free_matrix(scoring_matrix matrix)
{
    free(&matrix);   
}

scoring_matrix_view matrix_as_view(scoring_matrix matrix)
{
    scoring_matrix_view view = {matrix.width, matrix.height, {matrix.width, matrix.height, matrix.data}};
    print_matrix(view);
    return view;
}

void print_matrix(scoring_matrix_view view)
{
    for (int i = 0; i < view.height; i++)
    {
        for (int j = 0; j < view.width; j++)
        {
            //printf("%d ", view.matrix.data[i][j]);
            printf("%d\t", *(view.matrix.data + i * view.width + j));
        }
        printf("\n");
    }
}
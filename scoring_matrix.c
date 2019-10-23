#include "scoring_matrix.h"

#include <stdio.h>
#include <string.h>

scoring_matrix create_matrix(const char *a, const char *b, int match_score, int gap_cost)
{
    scoring_matrix matrix = {0, 0, NULL}; // change this!!
    // fill matrix
    return matrix;
}

void free_matrix(scoring_matrix matrix)
{
}

scoring_matrix_view matrix_as_view(scoring_matrix matrix)
{
    scoring_matrix_view view = {0, 0, {0, 0, NULL}}; // change this!!
    // set view
    return view;
}

void print_matrix(scoring_matrix_view view)
{
}
#include "Smith-Waterman.h"

#include "scoring_matrix.h"
#include "traceback.h"

#include <stdio.h>
#include <string.h>

void print_smith_waterman(const char *a, const char *b)
{
    fprintf(stderr, "print_smith_waterman(\"%s\", \"%s\")\n", a, b);

    // initialise match_score and gap_cost variables
    int match_score = 3;
    int gap_cost = 2;

    scoring_matrix matrix = create_matrix(a, b, match_score, gap_cost); // create the matrix
    
    scoring_matrix_view view = {matrix.width, matrix.height, {matrix.width, matrix.height, matrix.data}};
	print_matrix(view); // print the matrix as a view

    traceback_result * result = traceback(matrix_as_view(matrix), a, b); // create traceback pointer

    // print result strings
    printf("A: %s\n", result->a_);
    printf("B: %s\n", result->b_);

    // free allocated memory
    freeResult(result);
    free_matrix(matrix);
}

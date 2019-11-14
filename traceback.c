#include "traceback.h"

#include <string.h>
#include <stdio.h>

traceback_result *traceback_recursive(scoring_matrix_view view, const char* a, const char* b, char* b_, int old_i)
{
    char* a_ = calloc(sizeof(char), strlen(b)); // initialises memory to 0

    if (a_ != NULL) // if memory is allocated successfully
    {
        int i = 0;
        int j = 0;

        // finds the max value in the matrix
        for (int x = 0; x < view.height; x++)
        {
            for (int y = 0; y < view.width; y++)
            {
                if (view.matrix.data[(view.matrix.width) * x + y] >= view.matrix.data[(view.matrix.width) * i + j]) 
                {            
                    i = x; // set i and x to indexes of max value
                    j = y;
                }
            }
        }

        if (view.matrix.data[(view.matrix.width) * i + j] == 0) // reached end of traceback as element equals 0
        {
            strncpy(a_, a + j, strlen(b_)); // copies string a from index j into a_
            traceback_result * result = calloc(sizeof(traceback_result), sizeof(char)); // initialises memory to 0 

            if (result != NULL)
            {
                result->a_ = a_; // assign result struct variables
                result->b_ = b_;
            }
            else
            {
                printf("Memory allocation failed.\n");
            }
            return result; // return result pointer
        }

        if (old_i - i > 1)
        {
            char old_b_[strlen(b_)]; // copy of old string
            strcpy(old_b_, b_); 
            b_[0] = b[j-1]; // append character
            b_[1] = '-';  // append hyphen

            for (int k = 0; k < strlen(old_b_); k++)
            {
                b_[k+2] = old_b_[k]; // looping through and appending the old string to the end
            }
        }
        else
        {
            char old_b_[strlen(b_)];
            strcpy(old_b_, b_); // copies old_b_ string to b_
            b_[0] = b[j-1];
            
            for (int k = 0; k < strlen(old_b_); k++)
            {
                b_[k+1] = old_b_[k];
            }
        }
        
        view.height = i; // reduce the matrix
        view.width = j;

        return traceback_recursive(view, a, b, b_, i); // recursively call the function
    }
    else
    {
        printf("Memory allocation failed.\n"); // print error message to user
        return traceback_recursive(view, a, b, b_, 0);
    }
}

traceback_result *traceback(scoring_matrix_view view, const char* a, const char* b)
{
    char* b_ = calloc(sizeof(char), strlen(b)); // allocate memory to b_ and initialises memory to 0
    traceback_result * result = NULL; // initialise result to null

    if (b_ != NULL) result = traceback_recursive(view, a, b, b_, 0); // start recursion
    else printf("Memory allocation failed.\n");

    return result;
}

void freeResult(traceback_result *result)
{
    free(result->a_); // free memory allocated with malloc
    result->a_ = NULL;

    free(result->b_);
    result->b_ = NULL; // good practice to assign NULL once pointer has been freed

    free(result);
    result = NULL;
}

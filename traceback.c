#include "traceback.h"

#include <string.h>
#include <stdio.h>

traceback_result *traceback_recursive(scoring_matrix_view view, const char* a, const char* b, char* b_, int old_i)
{
    char* a_ = malloc(sizeof(char) * strlen(a));

    int i = 0;
    int j = 0;

    for (int x = 0; x < view.height; x++)
    {
        for (int y = 0; y < view.width; y++)
        {
            if (view.matrix.data[(view.matrix.width) * x + y] >= view.matrix.data[(view.matrix.width) * i + j]) 
            {            
                i = x;
                j = y;
            }
        }
    }

    if (view.matrix.data[(view.matrix.width) * i + j] == 0)
    {
        strncpy(a_, a + j, strlen(b_));
        traceback_result * result = malloc(sizeof(traceback_result));
        result->a_ = a_;
        result->b_ = b_;
        return result;
    }

    if (old_i - i > 1)
    {
        char prev_b_[strlen(b_)]; // copy of prev
        strcpy(prev_b_, b_); 
        b_[0] = b[j-1]; 
        b_[1] = '-'; 

        for (int k = 0; k < strlen(prev_b_); k++)
        {
            b_[k+2] = prev_b_[k]; // looping through and appending the old string to the end
        }
    }
    else
    {
        char prev_b_[strlen(b_)];
        strcpy(prev_b_, b_); 
        b_[0] = b[j-1];
        
        for (int k = 0; k < strlen(prev_b_); k++)
        {
            b_[k+1] = prev_b_[k];
        }
    }
    
    view.height = i;
    view.width = j;

    return traceback_recursive(view, a, b, b_, i);
}

traceback_result *traceback(scoring_matrix_view view, const char* a, const char* b)
{
    char* b_ = malloc(sizeof(char) * strlen(b));
    traceback_result * res = traceback_recursive(view, a, b, b_, 0);
    return res;
}

void freeResult(traceback_result *result)
{
    free(&result);
}

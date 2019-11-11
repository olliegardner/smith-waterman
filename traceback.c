#include "traceback.h"

#include <string.h>
#include <stdio.h>

traceback_result *traceback_help(scoring_matrix_view view, const char* a, const char* b, char* b_, int old_i) {
    char* a_ = malloc(sizeof(char) * strlen(a));

    int i = 0;
    int j = 0;

    int max = 0;

    //char* alt_b = "";
    //*(view.matrix.data + i * view.width + j)

    //print_matrix(view);

    for (int x = 0; x < view.height; x++) {
        for (int y = 0; y < view.width; y++) {
            if (view.matrix.data[(view.matrix.width) * x + y] >= view.matrix.data[(view.matrix.width) * i + j]) {            
            //if (*(view.matrix.data + x * view.width + y) >= *(view.matrix.data + i * view.width + j)) {
                //max = *(view.matrix.data + x * view.width + y);
                max = view.matrix.data[(view.matrix.width) * x + y];
                i = x;
                j = y;
            }
        }
    }

    printf("MAX: %d \n", max);

    if (view.matrix.data[(view.matrix.width) * i + j] == 0)
    //if (*(view.matrix.data + i * view.width + j) == 0)
    {
        strncpy(a_, a + j, strlen(b_));
        traceback_result * result = malloc(sizeof(traceback_result));
        result->a_ = a_;
        result->b_ = b_;
        return result;
    }

    if (old_i - i > 1) {
        char prev_b_[strlen(b_)]; // copy of prev
        strcpy(prev_b_, b_); 
        b_[0] = b[j-1]; 
        b_[1] = '-'; 
        for (int k = 0; k < strlen(prev_b_); k++) {
            b_[k+2] = prev_b_[k]; // looping through and appending the old string to the end
        }
    } else {
        char prev_b_[strlen(b_)];
        strcpy(prev_b_, b_); 
        b_[0] = b[j-1];
        for (int k = 0; k < strlen(prev_b_); k++) {
            b_[k+1] = prev_b_[k];
        }
    }

    //printf("count: %d\n", count);

    //if (old_i - i > 1) {

  //*(view.matrix.data + (i-1) * view.width + (j-1))

    //if (*(view.matrix.data + (i-1) * view.width + j) >= *(view.matrix.data + (i-1) * view.width + (j-1))) {
        //b_[count] = '-';
        //b_[count] = b[j-1];
    //} else {
        //b_[count] = '-';
       // b_[count] = b[j-1];
    //}
    
    view.height = i;
    view.width = j;

    //printf("Height: %zu\n", view.height);
    //printf("Width: %zu\n", view.width);

    //scoring_matrix_view view = {view.matrix.width, view.height, {view.width, view.height, matrix.data}};

    //printf("%s\n", b_);

    return traceback_help(view, a, b, b_, i);

    //printf("%d\n", old_i);

    //char* aa = malloc(sizeof(char) * strlen(a));
    //char* bb = malloc(sizeof(char) * strlen(b));
    //printf("aa lenngth: %s\n", aa);

    /*if (view.matrix.data[i-1][j] > view.matrix.data[i-1][j-1]) {
        // up
        printf("up %d\n", view.matrix.data[i-1][j]);

    } else {
        // diagonal
        printf("diag %d\n", view.matrix.data[i-1][j-1]);
        //aa[0] = "G";
    }*/

    //printf("old_i %d\n", old_i);

    /*if (old_i - i > 1) {
        b_ = b[j - 1] + b_;
    } else {
        b_ = b[j - 1] + '-' + b_;
    }*/

    /*if (old_i - i > 1) {
        for (int k = strlen(b_)-1; k>-1; k--) {
            b_[k] = b_[k+2];
        }
        for (int k = 0; k < strlen(b_); k++) {
            b_[k] = b_[k+2];
        }
        b_[0] = b[j-1];
    } else {
        for (int k = strlen(b_)-1; k>-1; k--) {
            b_[k] = b_[k+1];
        }
        b_[0] = b[j-1];
        b_[1] = '-';

    }*/
}

traceback_result *traceback(scoring_matrix_view view, const char* a, const char* b) {
    //char * b_ = malloc(view.matrix.width * sizeof *b_);
    int count = 0;


    char* b_ = malloc(sizeof(char) * strlen(b));

    traceback_result * res = traceback_help(view, a, b, b_, 0, count);
    return res;

    /*char* alt_b = "";
    int old_i = 0;

    int i_max = 0;
    int j_max = 0;
    //int h = view.height;

    int i = 0;
    int j = 0;

    int max = find_max(view, view.height, view.width);

    for (int x = 0; x < view.height; x++) {
        for (int y = 0; y < view.width; y++) {
            if (view.matrix.data[x][y] >= max) {
                max = view.matrix.data[x][y];
                i_max = x;
                j_max = y;
            }
        }
    }

    while (max != 0) {
        if (old_i - i_max > 1) {
            alt_b = b[j_max - 1] + alt_b;
        } else {
            alt_b = b[j_max - 1] + '-' + alt_b;
        }

        view.height = i_max;
        view.width = j_max;

        for (int x = 0; x < view.height; x++) {
            for (int y = 0; y < view.width; y++) {
                if (view.matrix.data[x][y] >= max) {
                    max = view.matrix.data[x][y];
                    i_max = x;
                    j_max = y;
                }
            }
        }

        printf("%zu\n", view.height);

        max = find_max(view, view.height, view.width);

        printf("%d\n", max);
    }

    printf("%s\n", alt_b);

    return NULL;

    traceback_result * result = {malloc(sizeof(char) * strlen(a)), malloc(strlen(b))};
    //traceback_result *result = {malloc(sizeof(char) * strlen(a))};

    int i = 0;
    for (int k = j_max; k < j_max + strlen(alt_b); k++) {
        result->a_[i] = a[k];
        i++;
    }

    result->b_ = alt_b;

    return result;*/
}


void freeResult(traceback_result *result)
{
    free(&result);
}

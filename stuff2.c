#include "traceback.h"

#include <string.h>
#include <stdio.h>

int find_max(scoring_matrix_view view, int i_max, int j_max) {
    int max = 0;

    for (int x = 0; x < i_max; x++) {
        for (int y = 0; y < j_max; y++) {
            if (view.matrix.data[x][y] >= max) {
                max = view.matrix.data[x][y];
                //i_max = x;
                //j_max = y;
            }
        }
    }
    return max;
}

traceback_result *traceback(scoring_matrix_view view, const char* a, const char* b) {
    /*char* b_ = malloc(sizeof(char)*strlen(b));
    traceback_result * res = traceback_help(view, a, b, b_, 0);
    return res;*/

    char* alt_b = "";
    int old_i = 0;

    int i_max = 0;
    int j_max = 0;
    //int h = view.height;

    /*int i = 0;
    int j = 0;*/

    int max = find_max(view, view.height, view.width);

    /*for (int x = 0; x < view.height; x++) {
        for (int y = 0; y < view.width; y++) {
            if (view.matrix.data[x][y] >= max) {
                max = view.matrix.data[x][y];
                i_max = x;
                j_max = y;
            }
        }
    }*/

    while (max != 0) {
        if (old_i - i_max > 1) {
            alt_b = b[j_max - 1] + alt_b;
        } else {
            alt_b = b[j_max - 1] + '-' + alt_b;
        }

        view.height = i_max;
        view.width = j_max;

        /*for (int x = 0; x < view.height; x++) {
            for (int y = 0; y < view.width; y++) {
                if (view.matrix.data[x][y] >= max) {
                    max = view.matrix.data[x][y];
                    i_max = x;
                    j_max = y;
                }
            }
        }*/

        printf("%zu\n", view.height);

        max = find_max(view, view.height, view.width);

        printf("%d\n", max);
    }

    printf("%s\n", alt_b);

    return NULL;

    /*traceback_result * result = {malloc(sizeof(char) * strlen(a)), malloc(strlen(b))};
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

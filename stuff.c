/*traceback_result *traceback(scoring_matrix_view view, const char* a, const char* b) {
    printf("hello");
    //int max = find_last_index_of_max_value(view);

    int max, x, y = 0;

    for (int i = 0; i < view.width; i++) 
    {
        for (int j = 0; view.height; j++)
        {
            //if (a[count] >= max && j <= view.width)
            if (view.matrix.data[i][j] > max)
            {
                max = view.matrix.data[i][j];
                x = i;
                y = j;
            }
        }
    }

    printf("MAX: %d", max);

    if (view.matrix.data[x][y] == 0)
    {

    }

    

//
//     if (view[i][j] == 0):
//         a_ = a[j:j+len(b_)]
//         return a_, b_
//     if (old_i - i > 1):
//         b_ = b[j - 1] + b_
//     else:
//         b_ = b[j - 1] + '-' + b_ 
//     return traceback(view[0:i][0:j], a, b, b_, i)



    return 0;
}*/


/*traceback_result *traceback_help(scoring_matrix_view view, const char* a, const char* b, char* b_, int old_i) {
    char* a_ = malloc(sizeof(char)*strlen(a));
    int i = 0;
    int j = 0;

    int max = 0;

    for (int x = 0; x < view.height; x++) {
        for (int y = 0; y < view.width; y++) {
            if (view.matrix.data[x][y] >= max) {
                max = view.matrix.data[x][y];
                i = x;
                j = y;
            }
        }
    }

    //printf("MAX: %d \n", max);

    if (view.matrix.data[i][j] == 0)
    {
        strncpy(a_, a + j, strlen(b_));
        traceback_result * result = malloc(sizeof(traceback_result));
        result->a_ = a_;
        result->b_ = b_;
        return result;
    }

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
    }

    //printf("old_i %d\n", old_i);

    if (old_i - i > 1) {
        /*for (int k = strlen(b_)-1; k>-1; k--) {
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

    }


    view.height = i;
    view.width = j;

    printf("%s\n", b_);

    return traceback_help(view, a, b, b_, i);
}

int findMax(scoring_matrix_view view) {
    int i = 0;
    int j = 0;

    int max = 0;

    for (int x = 0; x < view.height; x++) {
        for (int y = 0; y < view.width; y++) {
            if (view.matrix.data[x][y] >= max) {
                max = view.matrix.data[x][y];
                i = x;
                j = y;
            }
        }
    }
    return max; 
}*/

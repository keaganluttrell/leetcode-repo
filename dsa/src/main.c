#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#include "queues.h"

int main(int argc, char *argv[]) {
    char *input[] = {"MovingAverage", "next", "next", "next", "next"};
    int vals[] = {3, 1, 10, 3, 5};
    int input_len = 5;
    MovingAverage *MA_obj;

    for (int i = 0; i < input_len; ++i) {
        char *fn = input[i];
        int val = vals[i];

        if (strcmp(fn, "MovingAverage") == 0) {
            MA_obj = movingAverageCreate(val);

        } else if (strcmp(fn, "next") == 0) {

            double result = movingAverageNext(MA_obj, val);
            print_moving_avg(MA_obj);
            printf("Result:\t%f\n-------\n", result);
        } else {
            printf("err: unknown fn\n");
        }
    }

    movingAverageFree(MA_obj);

    return 0;
}

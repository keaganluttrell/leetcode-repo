#include "queues.h"
#include <stdio.h>
#include <stdlib.h>

void print_moving_avg(MovingAverage *o) {
    printf("Moving Average\n");
    printf("Size  :\t%d\n", o->size);
    printf("Index :\t%d\n", o->idx);
    printf("Sum   :\t%d\n", o->sum);
    printf("Values:\t");
    for (int i = 0; i < o->size; ++i) {
        printf("%d ", o->values[i]);
    }
    printf("\n");
}

MovingAverage *movingAverageCreate(int size) {
    MovingAverage *MA = (MovingAverage *)malloc(sizeof(MovingAverage));
    MA->size = size;
    MA->idx = 0;
    MA->sum = 0;
    MA->values = (int *)malloc(size * sizeof(int));
    return MA;
}

double movingAverageNext(MovingAverage *obj, int val) {

    if (obj->idx == obj->size) {
        int fifo = obj->values[obj->idx - 1];
        printf("fifo: %d\n", fifo);
        obj->sum -= fifo;
    }

    obj->sum += val;
    if (obj->idx < obj->size) {
        ++obj->idx;
    }
    // shift all values to the right
    for (int i = obj->idx - 2; i > -1; --i) {
        obj->values[i + 1] = obj->values[i];
    }

    obj->values[0] = val;

    return (double)obj->sum / (double)obj->idx;
}

void movingAverageFree(MovingAverage *obj) {
    free(obj->values);
    free(obj);
    return;
}

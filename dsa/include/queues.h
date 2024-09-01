
#ifndef QUEUES_H
#define QUEUES_H

typedef struct {
    int *values;
    int size;
    int idx;
    int sum;
} MovingAverage;

MovingAverage *movingAverageCreate(int size);
double movingAverageNext(MovingAverage *obj, int val);
void movingAverageFree(MovingAverage *obj);
void print_moving_avg(MovingAverage *o);
#endif

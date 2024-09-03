
#ifndef QUEUES_H
#define QUEUES_H

#define STOCK_SPANNER_MAX 10001

typedef struct {
    int *values;
    int size;
    int idx;
    int sum;
} MovingAverage;

typedef struct {
    int *values;
    int index;
    int *stack;
    int top;
} StockSpanner;

MovingAverage *movingAverageCreate(int size);
double movingAverageNext(MovingAverage *obj, int val);
void movingAverageFree(MovingAverage *obj);
void print_moving_avg(MovingAverage *o);
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
                        int *returnSize);
StockSpanner *stockSpannerCreate();
int stockSpannerNext(StockSpanner *obj, int price);
void stockSpannerFree(StockSpanner *obj);
#endif

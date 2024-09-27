#include "greedy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximum69Number(int num) {
    int start, digit, n;

    start = 1000;
    while (start > num) {
        start /= 10;
    }

    n = num;
    while (start > 0) {
        digit = n / start;
        n = n % start;
        if (digit == 6) {
            return num + (3 * start);
        }
        start /= 10;
    }

    return num;
}

int comp(const void *a, const void *b) {
    int *arr_a = *(int **)a;
    int *arr_b = *(int **)b;

    return arr_b[1] - arr_a[1];
}

int maximumUnits(int **boxTypes, int n, int *nc, int truckSize) {

    qsort(boxTypes, n, sizeof(int *), comp);
    int total_boxes = 0, total_units = 0;
    int i, j, boxes, units;

    for (i = 0; i < n && total_boxes < truckSize; ++i) {
        boxes = boxTypes[i][0];
        units = boxTypes[i][1];
        if ((boxes + total_boxes) < truckSize) {
            total_boxes += boxes;
            total_units += (units * boxes);
        } else {
            total_units += (units * (truckSize - total_boxes));
            total_boxes = truckSize;
        }
    }

    return total_units;
}

#define MAX_WT 5000
int compare(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    return (int_a > int_b) - (int_a < int_b);
}

int maxNumberOfApples(int *weight, int n) {
    qsort(weight, n, sizeof(int), compare);
    int sum = 0, i = 0;
    for (; i < n && (sum + weight[i]) <= MAX_WT; sum += weight[i], ++i)
        ;
    return i;
}

int comparator(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    return (int_b > int_a) - (int_b < int_a);
}

int minSetSize(int *arr, int n) {
    int set[100001] = {0};

    int i, sum, sets;
    for (i = 0; i < n; ++i)
        ++set[arr[i]];

    qsort(set, 100001, sizeof(int), comparator);

    for (i = 0, sum = 0, sets = 0; i < 100001 && sum < (n / 2); ++i) {
        sum += set[i];
        ++sets;
    }

    return sets;
}

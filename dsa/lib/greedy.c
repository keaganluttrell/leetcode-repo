#include "greedy.h"

#include <stdio.h>
#include <stdlib.h>

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

// boxTypes[index] = [numberOfBoxes, numberOfUnitsPerBox]
// number of boxes can't exceed truck size
int maximumUnits(int **boxTypes, int n, int *nc, int truckSize) {

    // assume sorted for now
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

    return units;
}

#include "heaps.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

typedef struct maxHeap {
    int *h;
    int len;
    int Msize;
} MaxHeap;

void create(MaxHeap *a, int n) {
    a->h = (int *)malloc(sizeof(int) * n);
    a->len = 0;
    a->Msize = n;
}

int left(int i) { return 2 * i + 1; }

int right(int i) { return 2 * i + 2; }

int parent(int i) { return (i - 1) / 2; }

void maxHeapify(MaxHeap *a, int i) {
    int large = i, l = left(i), r = right(i);
    if (l < a->len && a->h[l] > a->h[large]) {
        large = l;
    }
    if (r < a->len && a->h[r] > a->h[large]) {
        large = r;
    }
    if (i != large) {
        swap(&a->h[i], &a->h[large]);
        maxHeapify(a, large);
    }
}

void push(MaxHeap *a, int x) {
    int i = a->len++;
    a->h[i] = x;
    while (i > 0 && a->h[i] > a->h[parent(i)]) {
        swap(&a->h[i], &a->h[parent(i)]);
        i = parent(i);
    }
}

int top(MaxHeap *a) { return a->h[0]; }

bool empty(MaxHeap *a) { return a->len == 0; }

void pop(MaxHeap *a) {
    a->h[0] = a->h[--a->len];
    maxHeapify(a, 0);
}

int minStoneSum(int *piles, int n, int k) {
    MaxHeap *heap = malloc(sizeof(*heap));
    create(heap, n);
    int i, v, h, sum;

    sum = 0;
    for (i = 0; i < n; ++i) {
        push(heap, piles[i]);
        sum += piles[i];
    }

    while (k-- > 0) {
        v = top(heap);
        pop(heap);

        h = v / 2;
        sum -= h;
        push(heap, v - h);
    }

    free(heap);
    return sum;
}

typedef struct minHeap {
    int *h;
    int len;
    int Msize;
} MinHeap;

void init(MinHeap *a, int n) {
    a->h = (int *)malloc(sizeof(int) * n);
    a->len = 0;
    a->Msize = n;
}

void minHeapify(MinHeap *a, int i) {
    int small = i, l = left(i), r = right(i);
    if (l < a->len && a->h[l] < a->h[small]) {
        small = l;
    }
    if (r < a->len && a->h[r] < a->h[small]) {
        small = r;
    }
    if (i != small) {
        swap(&a->h[i], &a->h[small]);
        minHeapify(a, small);
    }
}

void add(MinHeap *a, int x) {
    int i = a->len++;
    a->h[i] = x;
    while (i > 0 && a->h[i] < a->h[parent(i)]) {
        swap(&a->h[i], &a->h[parent(i)]);
        i = parent(i);
    }
}

int length(MinHeap *a) { return a->len; }

int poll(MinHeap *a) {
    int r = a->h[0];
    a->h[0] = a->h[--a->len];
    minHeapify(a, 0);
    return r;
}

int peek(MinHeap *a) { return a->h[0]; }

int connectSticks(int *sticks, int n) {

    MinHeap *heap = malloc(sizeof(*heap));
    init(heap, n);

    for (int i = 0; i < n; ++i) {
        add(heap, sticks[i]);
    }

    int x, y, sum, cost;

    sum = 0;
    while (length(heap) > 1) {
        x = poll(heap);
        y = poll(heap);

        cost = x + y;
        add(heap, cost);
        sum += cost;
    }

    free(heap);
    return sum;
}

int findKthLargest(int *nums, int n, int k) {
    MinHeap *heap = malloc(sizeof(*heap));
    init(heap, k + 1);

    for (int i = 0; i < n; ++i) {
        add(heap, nums[i]);
        if (length(heap) == k + 1) {
            poll(heap);
        }
    }

    return peek(heap);
}

typedef struct pq_entry {
    int index;
    double distance;
} PQ_entry;

void PQ_entry_new(PQ_entry **a, int i, double d) {
    *a = malloc(sizeof(**a));
    (*a)->index = i;
    (*a)->distance = d;
}

typedef struct pq {
    PQ_entry **h;
    int len;
    int Msize;
} PQ;

void PQ_new(PQ *a, int n) {
    a->h = (PQ_entry **)malloc(sizeof(PQ_entry *) * n);
    a->len = 0;
    a->Msize = n;
}

void PQ_swap(PQ_entry *a, PQ_entry *b) {
    PQ_entry t = *a;
    *a = *b;
    *b = t;
}

int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }
int parent(int i) { return (i - 1) / 2; }

void PQ_heapify(PQ *a, int i) {
    int large = i, l = left(i), r = right(i);
    if (l < a->len && a->h[l]->distance > a->h[large]->distance) {
        large = l;
    }
    if (r < a->len && a->h[r]->distance > a->h[large]->distance) {
        large = r;
    }
    if (i != large) {
        PQ_swap(a->h[i], a->h[large]);
        PQ_heapify(a, large);
    }
}

void PQ_push(PQ *a, PQ_entry *e) {
    int i = a->len++;
    a->h[i] = e;
    while (i > 0 && a->h[i]->distance > a->h[parent(i)]->distance) {
        PQ_swap(a->h[i], a->h[parent(i)]);
        i = parent(i);
    }
}

int PQ_top(PQ *a) { return a->h[0]->index; }

void PQ_pop(PQ *a) {
    a->h[0] = a->h[--a->len];
    PQ_heapify(a, 0);
}

int **kClosest(int **points, int pointsSize, int *pointsColSize, int k,
               int *returnSize, int **returnColumnSizes) {
    PQ heap;
    PQ_new(&heap, k + 1);

    int i, x, y, d;
    for (i = 0; i < pointsSize; ++i) {
        x = points[i][0] * points[i][0];
        y = points[i][1] * points[i][1];
        d = x + y;
        PQ_entry *entry;
        PQ_entry_new(&entry, i, d);
        PQ_push(&heap, entry);
        if (heap.len > k) {
            PQ_pop(&heap);
        }
    }

    int **arr = malloc(sizeof(int *) * k);
    *returnColumnSizes = malloc(sizeof(int) * k);

    if (arr == NULL || *returnColumnSizes == NULL) {
        perror("Failed to allocate memory for kClosest arrays");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < k; ++i) {
        arr[i] = malloc(sizeof(int) * 2);
        if (arr[i] == NULL) {
            perror("Failed to allocate memory for kClosest sub-arrays");
            exit(EXIT_FAILURE);
        }
        (*returnColumnSizes)[i] = 2;
    }

    for (i = 0; i < k; ++i) {
        int idx = PQ_top(&heap);
        arr[i][0] = points[idx][0];
        arr[i][1] = points[idx][1];
        PQ_pop(&heap);
    }

    *returnSize = k;
    return arr;
}

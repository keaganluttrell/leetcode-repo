#include "heaps.h"
#include <stdbool.h>
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

int peek(MinHeap *a) { return a->h[0]; }

bool is_empty(MinHeap *a) { return a->len == 0; }

int length(MinHeap *a) { return a->len; }

void rm_top(MinHeap *a) {
    a->h[0] = a->h[--a->len];
    minHeapify(a, 0);
}

int connectSticks(int *sticks, int n) {
    int i, x, y, sum, cost;

    MinHeap *heap;
    init(heap, n);

    for (i = 0; i < n; ++i) {
        add(heap, sticks[i]);
    }

    sum = 0;
    while (length(heap) > 1) {
        x = peek(heap);
        rm_top(heap);
        y = peek(heap);
        rm_top(heap);

        cost = x + y;
        add(heap, cost);
        sum += cost;
    }

    free(heap);
    return sum;
}

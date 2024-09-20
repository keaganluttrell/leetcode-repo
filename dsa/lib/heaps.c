#include "heaps.h"
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
} Heap;

void create(Heap *a, int n) {
    a->h = (int *)malloc(sizeof(int) * n);
    a->len = 0;
    a->Msize = n;
}

int left(int i) { return 2 * i + 1; }

int right(int i) { return 2 * i + 2; }

int parent(int i) { return (i - 1) / 2; }

void maxHeapify(Heap *a, int i) {
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

void push(Heap *a, int x) {
    int i = a->len++;
    a->h[i] = x;
    while (i > 0 && a->h[i] > a->h[parent(i)]) {
        swap(&a->h[i], &a->h[parent(i)]);
        i = parent(i);
    }
}

int top(Heap *a) { return a->h[0]; }

bool empty(Heap *a) { return a->len == 0; }

void pop(Heap *a) {
    a->h[0] = a->h[--a->len];
    maxHeapify(a, 0);
}

int minStoneSum(int *piles, int n, int k) {
    Heap *heap = malloc(sizeof(*heap));
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

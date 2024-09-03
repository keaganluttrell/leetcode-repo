#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#include "queues.h"

int main(int argc, char *argv[]) {

    int input_sz = 8;
    char *cmds[] = {"StockSpanner", "next", "next", "next",
                    "next",         "next", "next", "next"};
    int values[] = {0, 3, 4, 5, 6, 7, 8, 9};
    StockSpanner *SP;
    int val;
    int ct = 0;

    for (int i = 0; i < input_sz; ++i) {
        if (strcmp(cmds[i], "StockSpanner") == 0) {
            SP = stockSpannerCreate();

        } else if (strcmp(cmds[i], "next") == 0) {
            val = stockSpannerNext(SP, values[i]);
            printf("%d: return %d\n", ++ct, val);
        }
    }

    stockSpannerFree(SP);

    return 0;
}

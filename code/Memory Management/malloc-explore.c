/*
Filename: malloc-explore.c
A C-program to experiment with malloc( )
Author: Shivakant Mishra (with lots of help from various Internet sites)
Date created: November 03, 2016
*/

#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <assert.h>
#include <unistd.h>

int main(void) {
    void *b1 = sbrk(0); //start of heap
    printf("Heap start address: \t%010p\n", b1);

    int *p = (int *)malloc(1);

    void *b2 = sbrk(0); 
    printf("Heap top address after first malloc: \t%010p\n", b2);

    int *q = (int *)malloc(1);

    void *b3 = sbrk(0);
    printf("Heap top address after second malloc: \t%010p\n", b3);

    int *r = (int *)malloc(100);

    void *b4 = sbrk(0);
    printf("Heap top address after third malloc: \t%010p\n", b4);

    free(r);

    void *b5 = sbrk(0);
    printf("Heap top address after first free: \t%010p\n", b5);

    return 0;
}

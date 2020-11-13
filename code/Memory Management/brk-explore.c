/*
Filename: brk-explore.c
A C-program to experiment with brk() and sbrk() functions
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

    int *p = (int *)b1;

    /* Move it 2 ints forward */
    brk(p + 3);
    void *b2 = sbrk(0); //heap extends from b1 to b2 now
    printf("Heap top address after first allocation: \t%010p\n", b2);

    /* Use the ints. */
    *p = 1;
    *(p + 2) = 2;
    assert(*p == 1);
    assert(*(p + 2) == 2);

	//sbrk(12);
    void *b3 = sbrk(12);
    printf("1Heap top address after second allocation: \t%010p\n", b3);
    void *b4 = sbrk(0); //heap extends from b1 to b3 now
    printf("2Heap top address after second allocation: \t%010p\n", b4);

    /* Deallocate back. */

    void *b7 = sbrk(-12);
    printf("3Heap top address after second allocation: \t%010p\n", b7);
    printf("Heap top address after first deallocation: \t%010p\n", sbrk(0));

    sbrk(-11);
    printf("Heap top address after the new allocatuon allocation: \t%010p\n", sbrk(0));
    return 0;
}

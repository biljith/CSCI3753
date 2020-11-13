/*
Filename: virtual-memory-explore.c
A C-program to experiment with getpagesize(), getrlimit() and setrlimit() functions
Author: Shivakant Mishra (with lots of help from various Internet sites)
Date created: November 03, 2016
*/

#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void) {
    printf("Page size = %d\n", getpagesize());
    
    struct rlimit x;

    getrlimit(RLIMIT_AS, &x);
    printf("Current maximum size of this process virtual address space = %lu\n", x.rlim_cur);
    printf("Limit on maximum size of this process virtual address space = %lu\n", x.rlim_max);

    x.rlim_cur -= 1073741824; //reducing the size by 1GB

    setrlimit(RLIMIT_AS, &x);
    printf("Current (new) maximum size of this process virtual address space = %lu\n", x.rlim_cur);

    printf("\nExperiment with other resources in a similar way. Read manpage of getrlimt and setrlimit\n");
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

double t[0x02000000];

void segments()
{
    static int s = 42;
    void *p = malloc(1024);
    printf("stack\t%p\nbrk\t%p\nheap\t%p\n"
           "static\t%p\nstatic\t%p\ntext\t%p\n",
           &p, sbrk(0), p, t, &s, segments);
}

int main(int argc, char *argv[])
{
    segments();
    exit(0);
}


#include <sys/time.h>
#include <stdio.h>

int main()
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    printf ("currnet time: %ld seconds, %d microseconds\n", current_time.tv_sec, current_time.tv_usec); 
}
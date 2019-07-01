// build with g++ -std=c++11

#include <iostream>
#include <unordered_set>
#include <inttypes.h>
 
int main()
{  
    std::unordered_set<uint64_t> set;
    uint64_t size = 100000;
    for (uint64_t i = 0; i < size; i++)
        set.insert(i);
    
    struct timespec start, stop;
    int randNum;
    long ns = 0;

    for (uint64_t i = 0; i < size; ++i) {
    	randNum = rand()%(size + 1);
    	clock_gettime(CLOCK_REALTIME, &start);
    	set.find(randNum);
    	clock_gettime(CLOCK_REALTIME, &stop);
    	ns += stop.tv_nsec - start.tv_nsec;
    }
    printf( "%" PRIu64 " elements, lookup takes %ld nanoseconds\n", size, ns / size);
}

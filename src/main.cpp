#include<iostream>
#include<x86intrin.h>

#define HUGE_SIZE 8*1024*1024
#define STRIDE 64

int main(){
    unsigned long long int start, end, sum=0, i, j, k, m, n;
    char *cacheBlock = (char*) malloc(HUGE_SIZE);
    _mm_sfence();
    for(j = 0;j < HUGE_SIZE; j+=1)
        _mm_clflushopt(&cacheBlock[j]);
    _mm_sfence();
    std::cout<<"-----START-----"<<std::endl;
    for (long long int i = 0; i < HUGE_SIZE; i += STRIDE){
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        sum+=cacheBlock[i];
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<(end-start)<<std::endl;
    }
    std::cout<<"Sum: "<<std::endl; // without this, sum+= statement will get optimised out - won't happen at all.
    std::cout<<"---------END---------"<<std::endl;
    free(cacheBlock);
}

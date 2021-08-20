#include<iostream>
#include<x86intrin.h>

#define HUGE_SIZE 8*1024*1024
#define CACHE_SIZE 32*1024
#define STRIDE 64

#define BLOCK_SIZE 64
#define BLOCK_NUM CACHE_SIZE/BLOCK_SIZE
#define ASSOC 8
#define SET_NUM BLOCK_NUM/ASSOC

void blockSize(){
    unsigned long long int start, end, sum=0, i, j;
    char *cacheBlock = (char*) malloc(HUGE_SIZE);
    _mm_sfence();
    for(j = 0;j < HUGE_SIZE; j+=1)
        _mm_clflushopt(&cacheBlock[j]);
    _mm_sfence();
    std::cout<<"---------START---------"<<std::endl;
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
    std::cout<<"Sum: "<<sum<<std::endl; // without this, sum+= statement will get optimised out - won't happen at all.
    std::cout<<"---------END---------"<<std::endl;
    free(cacheBlock);
}

void associativity(){
    unsigned long long int start, end, i, j, dummy;
    char *cacheBlock = (char*) malloc(HUGE_SIZE);
    _mm_sfence();
    for(j = 0;j < HUGE_SIZE; j+=1)
        _mm_clflushopt(&cacheBlock[j]);
    _mm_sfence();
    std::cout<<"---------START---------"<<std::endl;
    for(i=0;i<ASSOC;i+=1){
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        cacheBlock[CACHE_SIZE*i] = (i+10);
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<(end-start)<<std::endl;
        std::cout<<"Dummy: "<<dummy<<std::endl;
    }
    std::cout<<"---------END---------"<<std::endl;
    for(int l=0;l<10;l++){
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        dummy=cacheBlock[CACHE_SIZE*16];
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<(end-start)<<std::endl;
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        dummy=cacheBlock[0];
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<(end-start)<<std::endl;
    }
    free(cacheBlock);
}

int main(){
    /* blockSize(); */
    associativity();

}

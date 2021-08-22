#include "funcs.h"

void blockSize(){
    unsigned long long int start, end, i, j;
    char *cacheBlock = (char*) malloc(HUGE_SIZE);
    for(j = 0;j < HUGE_SIZE; j+=1){
        _mm_sfence();
        _mm_clflushopt(&cacheBlock[j]);
        _mm_sfence();
    }
    std::cout<<"========== BLOCK SIZE CALCULATION =========="<<std::endl;
    std::cout<<"---------START---------"<<std::endl;
    for (long long int i = 0; i < HUGE_SIZE; i += STRIDE){
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        cacheBlock[i] = 10;
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<"ACCESS "<<i<<": \t"<<(end-start)<<"\t TSC"<<std::endl;
    }
    std::cout<<"---------END---------"<<std::endl;
    free(cacheBlock);
}

void associativity(){
    unsigned long long int start, end;
    int i, j;
    char *cacheBlock = (char*) malloc(HUGE_SIZE);
    for(j = 0;j < HUGE_SIZE; j+=1){
        _mm_sfence();
        _mm_clflushopt(&cacheBlock[j]);
        _mm_sfence();
    }
    std::cout<<"========== ASSOCIATIVITY CALCULATION =========="<<std::endl;
    std::cout<<"---------START Populating---------"<<std::endl;
    for(i=0;i<=ASSOC;i+=1){
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        cacheBlock[CACHE_SIZE*i] = 10;
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<"Byte "<<CACHE_SIZE*i<<": \t"<<(end-start)<<std::endl;
    }
    std::cout<<"---------FINISH Populating---------"<<std::endl;
    std::cout<<"---------START New Access---------"<<std::endl;
    for(i=0;i<=ASSOC;i+=1){
        _mm_mfence();
        _mm_lfence();
        start = __rdtsc();
        _mm_lfence();
        cacheBlock[CACHE_SIZE*i] = 10;
        _mm_mfence();
        _mm_lfence();
        end = __rdtsc();
        std::cout<<"Byte "<<CACHE_SIZE*i<<": \t"<<(end-start)<<std::endl;
    }
    std::cout<<"---------FINISH New Access---------"<<std::endl;
    free(cacheBlock);
}

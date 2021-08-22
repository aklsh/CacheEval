#include<iostream>
#include "options.h"
#include<x86intrin.h>

#define HUGE_SIZE 8*1024*1024
#define CACHE_SIZE 32*1024
#define BLOCK_SIZE 64
#define BLOCK_NUM CACHE_SIZE/BLOCK_SIZE

#define SET_NUM BLOCK_NUM/ASSOC


void blockSize();
void associativity();

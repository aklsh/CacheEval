#include "funcs.h"
#include "options.h"

int main(){
#ifdef BLK_SZ
    blockSize();
#endif
#ifdef ASC
    associativity();
#endif
}

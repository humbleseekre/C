/******************************************************************************
 
 Online C++ Compiler.
 Code, Compile, Run and Debug C++ program online.
 Write your code in this editor and press "Run" button to compile and execute it.
 
 *******************************************************************************/

#include <iostream>
#include<stdint.h>

using namespace std;

void* memcpy_m(void* dst, void const* src, size_t len){
    unsigned char *pcDst = (unsigned char *)dst;
    unsigned char const *pcSrc = (unsigned char const*)src;
    if(
       (((uintptr_t)pcDst & (sizeof(long)-1)) == ((uintptr_t)pcSrc & (sizeof(long)-1)))){
           while((((uintptr_t)pcSrc) & (sizeof(long) -1)) != 0){
               *pcDst++ = *pcSrc++;
               --len;
           }
           
        long *plDst = (long *)pcDst;
        long const* plSrc = (long const*)pcSrc;
        // loop unrolling
        while(len >= sizeof(long)*4){
            plDst[0] = plSrc[0];
            plDst[1] = plSrc[1];
            plDst[2] = plSrc[2];
            plDst[3] = plSrc[3];
            plDst += 4;
            plSrc += 4;
            len -= sizeof(long)*4;
        }
        
        while(len >= sizeof(long)){
            *plDst++ = *plSrc++;
            len -= sizeof(long);
        }
        
        pcDst = (unsigned char*)plDst;
        pcSrc = (unsigned char const*)plSrc;
        while(len--){
            *pcDst++ = *pcSrc++;
        }
    
    }
    else{
        while(len--){
            *pcDst++ = *pcSrc++;
        }
    }
    return dst;
}

int main(){
    long buff1[] = {1, 2, 3, 4, 5, 6};
    long buff2[6] = {0};
    memcpy_m(buff2, buff1, 6*sizeof(long));
    for(int i=0; i< 6; ++i){
        cout << buff2[i] << " ";
    }
    cout << endl;
}

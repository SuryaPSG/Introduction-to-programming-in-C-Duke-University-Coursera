#include<stdio.h>
#include<stdlib.h>

unsigned power(unsigned x,unsigned y){
  if(y==0)
    return 1;
  if(x==0)
    return 0;
  if(y<0)
    return 1/(power(x,y));
  return x*power(x,y-1);
}

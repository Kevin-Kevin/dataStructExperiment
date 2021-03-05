#include <stdio.h>
#include <stdlib.h>
int main (void){
  int* a=(int*)malloc(10*sizeof(int));
  int b = sizeof(a);
  
  printf("%d",b);

  return 0;
}
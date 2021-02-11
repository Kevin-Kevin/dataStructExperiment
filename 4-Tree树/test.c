#include <stdio.h>
#include <stdlib.h>

int main (void){
  int i = 0;
  int a[8];
  while (i != 8)
  {
    scanf("%d", a+i);
    printf("\n%d\n", a[i]);
    i++;
  }

  return 0;
}
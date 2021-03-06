/*
 * 冒泡排序(递减)
 * 
 * bubble 为数组最后一个数字
 * 从数组[last]开始向前遍历
 *    如果遇到比自身大的,就交换值
 *    一直遍历到最前面,直到下标为 0
 *    这样就使得数组第一个是最小的数
 * 然后又从最后一个数开始冒泡
 *    一直遍历到最前面,直到下标为 1
 * 然后又开始冒泡...
 * 
 *  
 */
#include <stdio.h>
void printNums(int* nums, int size);
void BubbleSort(int nums[], int size);
// 递增排序
void BubbleSort(int *nums,int size){
  for (int index = 0;index < size;index++) {
    for (int i = size-1;i > index;i-- ) {
     if(nums[i]<nums[i-1]){
       int m=nums[i];
       nums[i]=nums[i-1];
       nums[i - 1] = m;
     } 
    }
  }
  printNums(nums,size);

}
void printNums(int *nums, int size){
  printf("nums = ");
  int compareN = -1;
  for(int i=0;i<size;i++){
    if(compareN<nums[i]){
      compareN = nums[i];
    }
    printf("%d ", nums[i]);
  }
  printf("\n");
  if(compareN==nums[size-1]){
    printf("this array is sorted ! \n");
  }

}
int main()
{
  int nums[] = { 3, 44, 38, 5, 47,
                15, 36, 26, 27, 2,
                46, 4, 19, 50, 48 };
  BubbleSort(nums,sizeof(nums)/sizeof(int));
  printNums(nums,sizeof(nums)/sizeof(int));

  return 0;
}
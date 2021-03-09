/* 
 * 插入排序(递减)
 * 
 * 将数组[0]作为最开始的牌堆
 * 选择数组[1]向前比较
 *    遇到小于的牌就交换
 *    直到遇到大于的牌就停止代表加入了牌堆
 * 选择数组[2]向前比较
 *    遇到小于的牌就交换
 *    直到遇到大于的牌就停止代表加入了牌堆
 * 选择数组[3]...
 */
#include <stdio.h>
void printNums(int* nums, int size);
void InsertSort(int nums[], int size);

void InsertSort(int *nums,int size){
  for(int index=1;index<size;index++){
    for(int i=index;i>0;i--)
    if(nums[i]>nums[i-1]){
      int m = nums[i];
      nums[i] = nums[i - 1];
      nums[i-1]=m;
    }else{
      break;
    }
  }
  
  printNums(nums,size);

}
void printNums(int *nums, int size){
  printf("nums = ");
  for(int i=0;i<size;i++){
    printf("%d ", nums[i]);
  }
  printf("\n");

}
int main()
{
  int nums[] = { 3, 44, 38, 5, 47,
                15, 36, 26, 27, 2,
                46, 4, 19, 50, 48 };
  InsertSort(nums,sizeof(nums)/sizeof(int));
  printNums(nums,sizeof(nums)/sizeof(int));

  return 0;
}
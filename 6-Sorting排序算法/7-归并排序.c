/* 
 * 归并排序
 * 
 * 归并操作 : 
 *    将两个已排序的子序列合并成一个有序序列
 * 
 * 归并排序原理 : 
 *    将序列分为 n 个长度为 1 的子序列
 *    相邻子序列两两进行归并操作
 *    归并后,有 n/2 个长度为 2 的子序列
 *    然后继续两两归并直到子序列长度为 n
 * 
 * 实现算法:
 *  - 递归算法 : 
 *   
 *  - 非递归算法 :
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
void printNums(int* nums, int size);

// 归并操作
// 将 nums[] 中的两个有序子序列按序合并至 result[]
// 然后复制 result[] 到 nums[]
void Merge(int nums[], int result[], int l, int r, int rightEnd)
{
  printf("--------\nmerge start \nl=%d,r=%d,rightend=%d\n",l,r,rightEnd);
  printNums(nums, 10);

  int leftEnd = r - 1;
  int num = rightEnd - l + 1;
  int i = l;
  // 将 l 数组与 r 数组的数按序放到 result 数组
  while (l <= leftEnd && r <= rightEnd)
  {
    if (nums[l] < nums[r])
    {
      result[i] = nums[l];
      l++;
    }
    else
    {
      result[i] = nums[r];
      r++;
    }
    i++;
  }
  // 若 l 指针未到 l 数组的末尾,继续放入 result 数组
  while (l <= leftEnd)
  {
    result[i] = nums[l];
    l++;
    i++;
  }
  // 若 r 指针未到 r 数组的末尾,继续放入 result 数组
  while (r <= rightEnd)
  {
    result[i] = nums[r];
    r++;
    i++;
  }
  // 将 result[] 的数字复制到 nums[]
  for (i = 0; i < num; i++, rightEnd--)
  {
    nums[rightEnd] = result[rightEnd];
    printf("nums[%d]=%d ", rightEnd, nums[rightEnd]);
  }
    
  printf("\n--------\n");
}

// 归并排序递归算法
void MSort(int nums[], int result[], int l, int rightEnd)
{
  if (l < rightEnd)
  {
    int mid = (l + rightEnd) / 2;
    printf("l,m,rEnd = %d %d %d \n", l, mid, rightEnd);
    printf("left[] : ");
    MSort(nums, result, l, mid);
    printf("right[] : ");
    MSort(nums, result, mid + 1, rightEnd);
    Merge(nums, result, l, mid+1, rightEnd);
  }else{
    if(l==rightEnd)
      printf("l equals rightEnd\n");

  }
}
// 输出数组,测试用
void printNums(int* nums, int size) {
  printf("nums = ");
  for (int i = 0;i < size;i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  int ascend = 1;
  int descend = 1;
  for (int i = 1;i < size;i++) {
    if (nums[i] > nums[i - 1]) {
      ascend++;
    }
    if (nums[i] < nums[i - 1]) {
      descend++;
    }
  }

  if (ascend == size) {
    printf("✅ sorted in ascending order ! \n");
  } else if (descend == size) {
    printf("✅ sorted in descending order ! \n");
  } else {
    printf("❌ not been sorted !\n");
  }

}
int main(void)
{
  int nums[10] = {2, 12, 6, 8, 9, 1, 3, 11, 7, 10};
  int result[10];
  printNums(nums, 10);

  //Merge(nums, result, 0, 5, 9);
  MSort(nums, result, 0, 9);
  printNums(nums, 10);

  printf("\n");
  return 0;
}

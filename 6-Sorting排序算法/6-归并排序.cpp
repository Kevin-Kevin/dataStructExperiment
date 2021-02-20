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

// 归并操作
// 将 Nums[] 中的两个有序子序列按序合并至 result[]
// 然后复制 result[] 到 Nums[]
void Merge(int Nums[], int result[], int l, int r, int rightEnd)
{

  int leftEnd = r - 1;
  int num = rightEnd - l + 1;
  int i = 0;
  while (l <= leftEnd && r <= rightEnd)
  {
    if (Nums[l] < Nums[r])
    {
      result[i] = Nums[l];
      l++;
    }
    else
    {
      result[i] = Nums[r];
      r++;
    }
    i++;
  }
  while (l <= leftEnd)
  {
    result[i] = Nums[l];
    l++;
    i++;
  }
  while (r <= rightEnd)
  {
    result[i] = Nums[r];
    r++;
    i++;
  }


  for (i = 0; i < num; i++, rightEnd--){
    Nums[rightEnd] = result[rightEnd];
  
  }
  for (i = 0; i < num; i++)
    printf("%d ", Nums[i]);
  printf("merge\n");
}

// 归并排序递归算法
void MSort(int nums[],int result[], int l ,int rightEnd){
  int mid = l + (rightEnd - l) / 2;
  printf("l,m,rEnd = %d %d %d \n", l, mid, rightEnd);
  if (l != mid)
  {
    MSort(nums, result, l, mid);
    MSort(nums, result, mid+1, rightEnd);
  }
    Merge(nums, result, l, mid , rightEnd);
}
int main(void)
{
  int nums[10] = {2, 4, 6, 8, 9, 1, 2, 6, 7, 10};
  int result[10];

  //Merge(nums, result, 0, 5, 9);
  MSort(nums,result,0,9);
  for (int i = 0; i <= 9;i++)
    printf("%d ", nums[i]);

  printf("\n");
  return 0;
}

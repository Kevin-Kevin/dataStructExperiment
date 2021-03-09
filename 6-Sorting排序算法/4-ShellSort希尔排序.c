/*
 * 希尔排序 插入排序的升级
 *
 * 增量 m=n/2
 *    从数组[0]开始选取间隔为 m 的数 组成新数组
 *        进行插入排序
 *    从数组[1]开始选取间隔为 m 的数 组成新数组
 *        进行插入排序
 *    直到数组[x]已经在之前被选取
 * 增量 m=(n/2)/2
 *    从数组[0]开始选取间隔为 m 的数 组成新数组
 *        进行插入排序
 *    从数组[1]开始选取间隔为 m 的数 组成新数组
 *        进行插入排序
 *    直到数组[x]已经在之前被选取
 * 增量 m= ...
 * 直到 m=0 break
 */
#include <stdio.h>
void printNums(int* nums, int size);
void ShellSort(int nums[], int size);

void ShellSort(int* nums, int size) {
  int m = (size-1) / 2;
  // 增量 m 不断减半
  for (;m != 0;m /= 2) {
    // 对间隔为 m 的数进行希尔排序
    for (int index = m;index < size;index++) {
      for (int i = index;i >= m;i=i-m) {
        //printf("start i=%d m=%d\n",i,m);
        if (nums[i] > nums[i - m]) {
          int mid = nums[i];
          nums[i] = nums[i - m];
          nums[i - m] = mid;
        } else {
          break;
        }
      }
    }
  }
  printNums(nums,size);
}

void printNums(int* nums, int size) {
  printf("nums = ");
  for (int i = 0;i < size;i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
int main() {
  int nums[] = { 3, 44, 38, 5, 47,
                15, 36, 26, 27, 2,
                46, 4, 19, 50, 48 };
  ShellSort(nums, sizeof(nums) / sizeof(int));
  printNums(nums, sizeof(nums) / sizeof(int));

  return 0;
}
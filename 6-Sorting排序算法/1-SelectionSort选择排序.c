/*
 * 选择排序
 * 
 * 从数组[0]开始
 *    在 1-n 中互相比较选择一个最小的数 数组[min]
 *    将 数组[min]与数组[0]交换
 * 从数组[1]开始
 *    在 2-n 中互相比较选择一个最小的数 数组[min]
 *    将 数组[min]与数组[1]交换
 * 从数组[2]开始 ...
 */
#include <stdio.h>
void printNums(int* nums, int size);
void SelectionSort(int nums[], int size);
// 递减排序
void SelectionSort(int *nums,int size){
  for (int index = 0;index < size;index++) {
    int min = index;
  printNums(nums,size);
    for (int i = index + 1;i < size;i++) {
      if (nums[min] > nums[i]) {
        min = i;
      }
    }
    printf("min = %d\n",nums[min]);
    int m = nums[min];
    nums[min] = nums[index];
    nums[index] = m;
    
  }
}
void printNums(int* nums, int size) {
  printf("nums = ");
  for (int i = 0;i < size;i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  int ascend = 1;
  for (int i = 1;i < size;i++) {
    if (nums[i] > nums[i - 1]) {
      ascend++;
    }
  }
  int descend = 1;
  for (int i = 1;i < size;i++) {
    if (nums[i] < nums[i - 1]) {
      descend++;
    }
  }
  if (ascend == size ) {
    printf("✅ sorted in ascending order ! \n");
  } else if (descend == size ) {
    printf("✅ sorted in descending order ! \n");
  } else {
    printf("❌ not been sorted !\n");
  }

}

int main()
{
  int nums[] = { 3, 44, 38, 5, 47,
                15, 36, 26, 27, 2,
                46, 4, 19, 50, 48 };
  SelectionSort(nums,sizeof(nums)/sizeof(int));
  printNums(nums,sizeof(nums)/sizeof(int));

  return 0;
}
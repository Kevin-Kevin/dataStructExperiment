/*
 * 堆排序 选择排序的升级
 *
 * --------算法一 :
 * 把原有数组变成一个最小堆数组
 * 申请一个 n 空间的新数组
 * 从最小堆数组中取最小的数依次放入新数组[0][1][2]...
 * 然后将新数组的值复制到原有数组
 * --------需要额外 O(N) 空间, T(N)=O(NLogN)
 *
 * --------算法二 :
 * 将原有数组变成一个最大堆
 *    将数组[0]既数组最大的数交换到堆的末尾 数组[n]
 * 然后将 0到n-1的数组变成一个最大堆
 *    将数组[0]既数组最大的数交换到堆的末尾 数组[n-1]
 * 然后是 0到 n-2
 *    ...
 * --------时间复杂度不变, 空间复杂度 O(1)
 *
 * ps : 我这里就用算法二实现, 性能更好
 */
#include<stdio.h>
#include<stdlib.h>

 // 堆排序
void heapSort(int* nums, int size);
// 数组转换成堆
void arrayToHeap(int* nums, int size);
// 交换后变成堆
void swapHeap(int* nums, int last);
// 输出数组
void printNums(int* nums, int size);
// 输出堆
void printArrayHeap(int* nums, int size);

void heapSort(int* nums, int size) {
  arrayToHeap(nums, size);
  printArrayHeap(nums, size);
  for (int i = size - 1;i >= 0;i--) {
    swapHeap(nums, i);
  }
  printNums(nums, size);

}
void arrayToHeap(int* nums, int size) {
  int start = (size - 1) / 2;
  for (int i = start;i >= 0;i--) {
    int parent = i;
    int child = (parent * 2) + 1;
    while (child < size) {
      if (nums[child + 1] > nums[child]) {
        child++;
      }
      if (nums[parent] < nums[child]) {
        int t = nums[parent];
        nums[parent] = nums[child];
        nums[child] = t;
        parent = child;
        child = (parent * 2) + 1;
      } else {
        break;
      }
    }
  }
}
void swapHeap(int* nums, int last) {
  int t = nums[0];
  nums[0] = nums[last];
  nums[last] = t;
  int parent = 0;
  int child = nums[1] > nums[2] ? 1 : 2;
  while (child < last) {
    if (child + 1 < last && nums[child + 1] > nums[child]) {
      child++;
    }
    if (nums[parent] < nums[child]) {
      t = nums[parent];
      nums[parent] = nums[child];
      nums[child] = t;
      parent = child;
      child = (parent * 2) + 1;
    } else {
      break;
    }
  }
}

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
void printArrayHeap(int* nums, int size) {
  printf("------- heap ------- \n");

  for (int index = 0; index <= size; index = index * 2 + 1) {
    for (int i = index; i <= (index * 2) && i < size; i++) {
      printf("%d ", nums[i]);
    }
    printf("\n");
  }
  printf("-------------------- \n");

}
int main() {
  int nums[] = { 3, 44, 38, 5, 47,
                15, 36, 26, 27, 2,
                46, 4, 19, 50, 48 };
  int size = sizeof(nums) / sizeof(nums[0]);
  heapSort(nums, size);

  return 0;
}

/*
  快速排序 : 
   
    被誉为 20 世纪十大经典算法
    这么多排序算法只有它被称为快速排序
  
  算法思路 : 
    
    取要排序的数组中的一个数作为枢轴 pivot
    将数组中比其小的数挪到它的左边, 比其大的数挪到右边,这一步可用交换法,也可用替换法
    然后以 pivot 为界限, 分为左右两部分, 递归执行上面的操作
  
  复杂度 :
  
    最优情况 : 
      每次取的 pivot 都是中位数, 划分的两部分长度相等
      T(n) = 2T(n/2)+n
      T(n) = 2(2T(n/4)+n/2)+n = 4T(n/4)+2n
      T(n) = 2(2(2T(n/8)+n/4)+n/2)+n = 8T(n/8)+3n
      ...
      T(n) = [2^log2(n)]*T(0)+n*log2(n)
           = O( n*log(n) )
    最差情况 : 
      数组为正序或逆序, 每次取到 pivot 都使得划分的两部分一个为 1, 一个为大小递减的序列
      T(n) = T(n-1) + n-1
      T(n) = T(n-2) + n-2 + n-1
      ...
      T(n) = 1 + ... + n-2 + n-1
           = n(n-1)/2
           = O( n^2 )

  算法优化 :
  
    1. 优化 pivot
      如果每次都能取到数组的中位数, 那速度就很让人满意
      a) 随机选取 : 
      b) 三数取中 : 
          选三个数, 一般是 left right 和 mid
          然后选这三个数的中位数作为 pivot
      c) 九数取中 : 做三次三数取中, 然后对选出来的三个pivot 取中位数 
    
    2. 优化不必要的交换
      先把 nums[pivot] 的值保存起来
      在执行 "将数组中比 pivot 的数挪到它的左边, 比其大的数挪到右边" 这一步时
      不使用交换而是直接替换
    3. 优化小数组时的排序方案
      数组较小时使用递归是大材小用, 直接使用插入排序, 在快速排序开头加入判断语句
      这样一来, 数组较大时使用快速排序, 直到数组被分成小部分的子序列时就使用插入排序
    4. 优化递归
      在递归对子序列进行排序时, 递归了两次, 使用迭代加尾递归可以减少栈的深度
*/

#include<stdio.h>
#include<stdlib.h>

// 快速排序的包装
void quickSort(int* nums, int size);
// 真正的快速排序, 参数和包装有些不同, 为了和其他排序算法的调用是一致的
void quickSortForRecursion(int* nums, int left, int right);
// 交换两个数
void swap(int* low, int* high);
// 输出数组
void printNums(int* nums, int size);

void quickSort(int *nums, int size){
  printf("size = %d\n",size);
  quickSortForRecursion(nums, 0, size-1);
}

void quickSortForRecursion(int *nums, int left, int right){
  if(left>=right){
    return;
  }
  // 每次取左边界第一个数作为 pivot
  int pivot = nums[left];
  int low = left;
  int high = right;
  printf("left = %d , right = %d\n",left, right);
  // 执行循环,使得比 pivot 小的在左边,大的放右边
  while (low < high) {
    while (low<high && nums[high] >= pivot) {
      high--;
    }
    swap(&nums[low], &nums[high]);
    while (low<high && nums[low] <= pivot) {
      low++;
    }
    swap(&nums[low], &nums[high]);
  }
  // 递归左右两部分
  quickSortForRecursion(nums, left, low-1);
  quickSortForRecursion(nums, low + 1, right);
}
void swap(int* low, int* high){
  int m = *low;
  *low = *high;
  *high = m;
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
int main(){
  int nums[] = { 3, 44, 38, 5, 47,
              15, 36, 26, 27, 2,
              46, 4, 19, 50, 48 };
  quickSort(nums, sizeof(nums) / sizeof(int));
  printNums(nums, sizeof(nums) / sizeof(int));
  return 0;
}

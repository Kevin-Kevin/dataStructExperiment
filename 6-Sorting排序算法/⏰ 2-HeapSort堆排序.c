/* 
 * 堆排序 选择排序的升级
 * 
 * --------算法一 
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
 * 
 * 
 */
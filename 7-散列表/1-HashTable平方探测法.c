/*
  哈希表
    基本操作 :
      - 创建空的哈希表
      - 查找 key 对应的 value
      - 插入键值对 (平方探测法)

*/
#include <stdio.h>
#include <stdlib.h>

// hashTable 地址空间存放的结构体
struct Cell;
// hashTable 结构体
typedef struct HashTable* pointerHashTable;



// 操作函数 -------------------------------

int nextPrimeNumber(int n);
pointerHashTable initializeTable(int tableSize);
int hashFunction(pointerHashTable hashTable, int key);
int findBySquare(pointerHashTable hashTable, int key);
int insertBySquare(pointerHashTable hashTable, int key);
void printHashTable(pointerHashTable hashTable);

// end -----------------------------------



// hashTable 地址空间的状态
typedef enum { Legitimate, Empty, Deleted } EntryType;
typedef struct Cell {
  int value;
  int key;
  EntryType info;
}Cell;
typedef struct HashTable {
  int tableSize;
  Cell* theCells;
} HashTable;

// 获取一个不小于 n 的最小素数
int nextPrimeNumber(int n) {
  // 素数不会被大于一的数整除
  // 首先排除偶数, 在奇数里面找

  int p = (n % 2) ? n : n + 1;

  int maxNum = 10000;
  while (p < 10000) {
    // 书上这里i 的取值范围是 sqrt(p)-2 ,真的精悍
    int i = p - 1;
    for (;i > 1;i--) {
      if (0 == p % i) {
        break;
      }
    }
    if (i == 1) {
      return p;
    }
    p += 2;
  }
  return -1;
}
// 初始化哈希表
// 这里表的大小有点不同, 视频里老师讲的是用传进来的大小, 但是课本里是用比 tableSize 大的最小素数
// 我用的是课本里的, 方便哈希函数的使用
pointerHashTable initializeTable(int tableSize) {
  int size = nextPrimeNumber(tableSize);
  printf("next prime number = %d\n", nextPrimeNumber(tableSize));

  pointerHashTable hashTable = (pointerHashTable)malloc(sizeof(HashTable));
  hashTable->theCells = (Cell*)malloc(size * sizeof(Cell));
  hashTable->tableSize = size;

  for (int i = 0;i < size;i++) {
    hashTable->theCells[i].info = Empty;
  }
  return hashTable;
}
// 哈希函数
// 使用除留余数法
int hashFunction(pointerHashTable hashTable, int key) {
  return key % hashTable->tableSize;
}
// 查找 key
// 使用平方探测法, 但是有个问题, 表如果满了怎么办, 不就无限循环了
int findBySquare(pointerHashTable hashTable, int key) {
  // 得到哈希函数结果
  int currentPosition = hashFunction(hashTable, key);
  int newPosition = currentPosition;
  // 标志位, 记录平方探测法当前 di 是否为正
  // 课本直接用一个变量 count 取代两个变量, 代码不易读
  int sign = 1;
  int di = 1;
  printf("------>>>> insert %d , current position = %d\n", key, currentPosition);
  while (hashTable->theCells[newPosition].info != Empty && hashTable->theCells[newPosition].key != key) {
    printf("hash table position %d conflict ", newPosition);
    newPosition = currentPosition + sign * (di * di);
    while (newPosition >= hashTable->tableSize) {
      newPosition = newPosition - hashTable->tableSize;
    }
    while (newPosition < 0) {
      newPosition = newPosition + hashTable->tableSize;
    }
    printf(", new pos = %d\n", newPosition);
    if (sign == -1) {
      di++;
      sign = 1;
    }     else {
      sign = -1;
    }

  }
  return newPosition;
}
// 插入 key
// 使用平方探测法
int insertBySquare(pointerHashTable hashTable, int key) {
  // 先看一下表里面有没有这个键值对
  int position = findBySquare(hashTable, key);

  // 有就返回 -1 表示错误
  if (hashTable->theCells[position].info == Legitimate) {
    return -1;
  }   else {
    // 没有就插入
    hashTable->theCells[position].key = key;
    hashTable->theCells[position].info = Legitimate;
    return 0;
  }

}


//输出键值对
void printHashTable(pointerHashTable hashTable) {
  for (int i = 0;i < hashTable->tableSize;i++) {
    if (hashTable->theCells[i].info == Legitimate) {
      printf("%d ", hashTable->theCells[i].key);
    }     else {
      printf("%d ", -1);
    }
  }
}
int main() {
  pointerHashTable hashTable = initializeTable(100);

  // 测试一下平方探测
  int x = 8;
  for (int i = 0;i < 98;i++) {
    x++;
    insertBySquare(hashTable, x * i);
  }
  printHashTable(hashTable);
  //
  return 0;
}

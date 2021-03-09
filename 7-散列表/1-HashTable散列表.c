/*
  哈希表
    基本操作 : 
    创建空的哈希表
    插入(平方探测)
    删除
    查找

*/
#include <stdio.h>
#include <stdlib.h>
struct Cell;

struct HashTable;
typedef enum { Legitmate, Empty, Deleted } EntryType;

typedef struct Cell {
  int data;
  EntryType info;
  int* p;
}Cell;

typedef struct HashTable {
  int tableSize;
  Cell* theCells;
} HashTable, * pointerHashTable;

// 获取一个不小于 n 的最小素数
int nextPrimeNumber(int n){
  // 素数不会被大于一的数整除
  // 首先排除偶数
  int p;
  if(0==n%2){
    p = n + 1;
  }
}
// 初始化哈希表

pointerHashTable initializeTable(int tableSize) {
  pointerHashTable hashTable = (pointerHashTable)malloc(sizeof(HashTable));
  hashTable->theCells = (Cell*)malloc(tableSize * sizeof(Cell));
  int a = 1;
  for (int i = 0;i < tableSize - 2;i++) {
    hashTable->theCells[i].info = Empty;
  }
  return hashTable;
}

int main() {
  pointerHashTable hashTable = initializeTable(15);

  return 0;
}

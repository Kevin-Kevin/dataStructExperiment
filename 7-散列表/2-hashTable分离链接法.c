/*
  哈希表
    基本操作 :
      - 创建空的哈希表
      - 查找 key 对应的 value
      - 插入键值对 ( 分离链接法)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// hashTable 地址空间存放的结构体
typedef struct Node* pointerNode;
// hashTable 结构体
typedef struct HashTable* pointerHashTable;



// 操作函数 -------------------------------

int nextPrimeNumber(int n);

pointerHashTable initializeTable(int tableSize);

int hashFunction(pointerHashTable hashTable, int key);

pointerNode findBySeparateChaining(pointerHashTable hashTable, char* key);

int insertBySeparateCaining(pointerHashTable hashTable, char* key);

void printHashTable(pointerHashTable hashTable);

// end -----------------------------------


// hashTable 地址空间的状态

typedef struct Node {
  char key[15];
  pointerNode next;
}Node;
typedef struct HashTable {
  int tableSize;
  Node* head;
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
// 这里表的大小为比 tableSize 大的最小素数
// 哈希表数组元素为 Node
pointerHashTable initializeTable(int tableSize) {
  int size = nextPrimeNumber(tableSize);
  printf("next prime number = %d\n", nextPrimeNumber(tableSize));

  pointerHashTable hashTable = (pointerHashTable)malloc(sizeof(HashTable));
  hashTable->head = (pointerNode)malloc(size * sizeof(Node));
  hashTable->tableSize = size;

  for (int i = 0;i < size;i++) {
    hashTable->head[i].key[i] = '\0';
    hashTable->head[i].next = NULL;
  }
  printf("initialize end\n");
  return hashTable;
}
// 哈希函数
// 使用除留余数法
int hashFunction(pointerHashTable hashTable, int key) {
  return key % hashTable->tableSize;
}
// 查找 key
// 使用分离链接法
pointerNode findBySquare(pointerHashTable hashTable, char* key) {
  // 先把字符串 key 使用移位法处理一下赋值给 hashKey ,不然冲突太严重  
  int hashKey = 0;
  for(int i =0;i<strlen(key);i++){
    int index = i;
    int intKey = key[strlen(key)-1-i];
    while(index>0){
      intKey = intKey << 5;
      index--;
    }
    hashKey += intKey;
  }
  
  // 使用哈希函数获取下标
  int currentPosition = hashFunction(hashTable, hashKey);
  pointerNode currentNode = hashTable->head[currentPosition].next;
  pointerNode resultNode = (pointerNode)malloc(sizeof(Node));
  
  resultNode->key[0] = '\0';
  resultNode->next = NULL;

  if(currentNode==NULL){
    hashTable->head[currentPosition].next = resultNode;
    return resultNode;
  }
  
  while (currentNode->next != NULL && strcmp(currentNode->key, key) != 0) {
    printf("哈希冲突 ");
    currentNode = currentNode->next;
  }
  // hashtable 找到相同的 key
  if (strcmp(currentNode->key, key) == 0) {
    printf("find same key");
    return currentNode;
  } else {
    // 没找到就加新结点
    currentNode->next = resultNode;
    return resultNode;
  }
}
// 插入 key
// 使用分离链接法
int insertBySquare(pointerHashTable hashTable, char* key) {
  // 先看一下表里面有没有这个键值对
  pointerNode node = findBySquare(hashTable, key);
  if (strcmp(node->key, key) == 0) {
    return -1;
  } else {
    strcpy(node->key, key);
    return 0;
  }

}

// 输出键值对
// 实际只有 key 没有 value
void printHashTable(pointerHashTable hashTable) {
  printf("\n");
  for (int i = 0;i < hashTable->tableSize;i++) {
    pointerNode node = hashTable->head[i].next;
    printf("hash index %d = ",i);
    while (node != NULL) {
      printf("%s ", node->key);
      node = node->next;
    }
    printf("\n");
  }
}
int main() {
  pointerHashTable hashTable = initializeTable(80);

  // 测试一下分离链接法
  int x = 8;
  char str[15] = "\0";
  for (int i = 0;i < 98;i++) {
    x += i;
    sprintf(str, "%d ", x);
    insertBySquare(hashTable, str);
  }
   printHashTable(hashTable);
    //
  return 0;
}

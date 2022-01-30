/*
    线性表 List
        List MakeEmpty() // 初始化空线性表
        ElementType FindKth( int K, List L) // 查找位序为 K 的元素并返回
        int Find( ElementType X, List L ) // 查找 X 第一次出现顺序
        void Insert( ElementType X, int i, List L) // 在位序 i 前插入一个新元素 X
        void Delete( int i, List L) // 删除指定位序 i 的元素
        int Length( List L ) // 返回线性表 L 的长度 n
*/
#include <iostream>

#define MaxSize 100

typedef struct LNode *List;
typedef int ElementType;

struct LNode
{
    ElementType DataArray[MaxSize];
    int Last = -1;
};

void Print(List L)
{
	int i;
    printf("l = ");
	for(i=0;i<=L->Last;i++)
		printf("%d ",L->DataArray[i]);
	printf("\n");
}
// 1. 初始化空线性表
List MakeEmpty()
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(LNode));
    Ptrl->Last = -1;
    return Ptrl;
}
// 2. 查找 X 第一次出现顺序
int Find(ElementType X, List L)
{
    for (int index = 0; index <= L->Last; index++)
    {
        if (L->DataArray[index] == X)
            return index;
    }
    // 未查找到返回 -1
    return -1;
}
// 3. 在位序 i 前插入一个新元素 X (1 <= i <= n+1)
void Insert(ElementType X, int i, List L)
{
    if (L->Last + 1 == MaxSize)
    {
        printf(" the list is full ");
        return;
    }
    if (i < 1 || i > L->Last + 2)
    {
        printf("位置不合法");
        return;
    }

    for (int index = L->Last; index >= i - 1; index--)
        L->DataArray[index] = L->DataArray[index - 1];
    L->DataArray[i - 1] = X;
    L->Last++;
    return;
}

// 4. 删除指定位序 i 的元素
void Delete(int i, List L)
{
    printf("Delete start\n");
    printf("last = %d \n", L->Last);
    if (i < 1 || i > L->Last + 1)
    {
        printf("不存在该元素 i = %d\n",i);
        return;
    }
    for (int index = i - 1; index < L->Last; index++)
        L->DataArray[index] = L->DataArray[index + 1];

    L->Last--;
    printf("last = %d \n", L->Last);
    Print(L);
    return;
}
// 5. 查找位序为 K 的元素并返回
ElementType FindKth(int K, List L)
{
    if(K<1 || K>L->Last+1) {
        printf("不存在该元素");
        return -1;
    }
    else
    {
        return L->DataArray[K];
    }
}

// 6. 返回线性表 L 的长度 n
int Length(List L) {
    return L->Last;
}

int main()
{
    List l = MakeEmpty();

    int i = 0,numBeenFind = 0;
    Print(l);
    while (i<5){
        Insert(i, 1, l);
        i++;
    }
    Print(l);

    i = 0;
    while(i<4) {
        numBeenFind = Find(i, l);
        std::cout << "num been found = " << numBeenFind << std::endl;
        i++;
    }

    Print(l);

    i = 5;
    while (i > 0)
    {
        Delete(i, l);
        i--;
    }

    Print(l);
    return 0;
}

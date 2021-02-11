/*
    链表 link list
        创建链表
        插入
        删除
        查找


*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct LNode *List;
typedef struct LNode *NodePoint;
typedef int ElementType;

typedef struct LNode
{
    ElementType Data;
    struct LNode *Next;
} LNode;
// 1. 创建链表
List creatList(List l)
{
    int i = 0;
    srand((unsigned)time(NULL));
    i = rand() % 100 + 1;
    l = (List)malloc(sizeof(LNode));
    NodePoint p, r;
    r = l;
    cout << endl;
    cout << "i = " << i << endl;

    for (; i < 100; i++)
    {
        p = (NodePoint)malloc(sizeof(LNode));
        p->Data = rand() % 100 + 1;
        r->Next = p;
        r = p;
    }
    r->Next = nullptr;
    return l;
}
// 2. 求表长
int Length(List l)
{
    int i = 0;
    while (l->Next)
    {
        l = l->Next;
        i++;
    }
    cout << "the length of List = " << i << endl;
    return i;
}
// 3. 按序号查找
List FindKth(int K, List l)
{

    // K 必须在 1 和 链表长度之间
    int i = 1;
    //cout << "find start" << endl;
    while (i < K && l != nullptr)
    {
        l = l->Next;
        i++;
    }
    if (i == K)
    {
        return l;
    }
    else
    {
        cout << "can not find this th element in list" << endl;
        return nullptr;
    }
}
// 4. 按照值查找
NodePoint Find(ElementType X, List l)
{
    while (l != nullptr)
    {
        if (X == l->Data)
            return l;
        l = l->Next;
    }
    cout << "can not find this value in List" << endl;
    return nullptr;
}
// 5. 插入 在第 i-1 个节点后插入一个值为 x 的节点（1 <= i <= n+1）
List Insert(int i, ElementType x, List l)
{

    int index = 1;

    List p;

    if (i == 1)
    {
        NodePoint X = (NodePoint)malloc(sizeof(LNode));
        X->Data = x;
        X->Next = l;
        return X;
    }
    p = FindKth(i - 1, l);
    if (p == nullptr)
    {
        cout << "插入序号 i 错误" << endl;
        return l;
    }
    else
    {
        NodePoint X = (NodePoint)malloc(sizeof(LNode));
        X->Data = x;
        X->Next = p->Next;
        p->Next = X;
        return l;
    }
}
// 6. 删除第 i 个节点
List Delete(int i, List l)
{
    List p = l;
    List s;
    if (i == 1)
    {
        l = p->Next;
        free(p);
        return l;
    }
    p = FindKth(i - 1, l);
    if(p==nullptr)
    {
        printf("不存在第 i-1= %d 个元素\n", i - 1);
        return l;
    }
    else if(p->Next==nullptr)
    {
        printf("不存在第 i =  %d 个元素\n", i);
        return l;
    }
    
    s = p->Next;
    p->Next = s->Next;
    free(s);
    return l;
}

// 打印链表
void Print(List l)
{
    NodePoint p;
    p = l;
    cout << endl;
    printf("List = ");
    while (p->Next != nullptr)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    cout << endl;
    cout << "print end" << endl;
    cout << endl;
}

void test(List l)
{
    l = l->Next;
    cout << "l=l->Next = " << l << endl;
}

int main()
{
    List l;
    int index = -2;

    l = creatList(l);
    Print(l);

    int length = Length(l);
    cout << l->Next->Data << endl;

    while (index < 100)
    {
        List findKth;
        findKth = FindKth(index, l);
        index++;
    }
    NodePoint find;
    find = Find(20, l);
    if (find != nullptr)
        cout << "find data = " << find->Data << endl;

    index = 100;
    while (index > 0)
    {
        l = Insert(index, -100, l);
        index--;
    }
    Print(l);

    index = 100;
    while (index > 0)
    {
        l = Delete(index, l);
        index--;
    }
   // Print(l);


    return 0;
}

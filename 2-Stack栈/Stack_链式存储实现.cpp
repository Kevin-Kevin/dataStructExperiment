/*
    栈 stack
        创建空栈
        入栈 push
        出栈 pop

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


typedef int ElementType;
typedef struct StackNode *PointStack;
typedef struct StackNode *PointStackNode;

typedef struct StackNode {
    ElementType Data;
    struct StackNode *Next;
} StackNode;


// 创建空栈
PointStack CreatEmptyStack(){
    PointStack stack = (PointStackNode)malloc(sizeof(StackNode));
    stack->Next = nullptr;
    return stack;
}

// 入栈 push
void Push(ElementType x, PointStack stack) {
    PointStackNode X = (PointStackNode)malloc(sizeof(StackNode));
    X->Data = x;
    X->Next = stack->Next;
    stack->Next = X;
    return;
}
// 出栈 pop
ElementType Pop(PointStack stack) {
    // 判断是否栈空
    if(stack->Next==nullptr){
        printf("stack is empty !\n");
        return -10000;
    }
    // 出栈
    PointStackNode X;
    X = stack->Next;
    stack->Next = X->Next;
    ElementType popElement = X->Data;
    free(X);
    return popElement;
}

int main (){
    PointStack stack = CreatEmptyStack();

    int i = 0;
    while (i<110)
    {
        Push(i, stack);
        i++;
    }
    i = i + 2;
    cout << "pop stack = ";
    while (i > 0)
    {
       cout<< Pop(stack)<<" ";
        i--;
    }

        return 0;
}
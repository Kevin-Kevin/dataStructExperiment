/*
    栈 stack
        创建空栈
        判断是否栈满
        入栈 push
        判断是否栈空
        出栈 pop

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


typedef int ElementType;
typedef struct Stack *PointStack;

typedef struct Stack
{
    int MaxSize;
    int Top;
    ElementType *array;
} Stack;

// 创建空栈
PointStack CreatEmptyStack(int MaxSize){
    PointStack stack = (PointStack)malloc(sizeof(Stack));
    stack->MaxSize = MaxSize;
    stack->array = (ElementType *)malloc(sizeof(ElementType));
    stack->Top = -1;
    return stack;
}

// 入栈 push
bool Push(ElementType x, PointStack stack) {
    // 判断是否栈满
    if(stack->Top == stack->MaxSize - 1){
        return false;
    }
    // 入栈
    stack->Top++;
    stack->array[stack->Top] = x;
    return true;
}
// 出栈 pop
ElementType Pop(PointStack stack) {
    // 判断是否栈空
    if(stack->Top == -1){
        return -100000;
    }
    // 出栈
    ElementType x = stack->array[stack->Top];
    stack->array[stack->Top] = 0;
    stack->Top--;
    return x;
}


int main (){
    PointStack stack = CreatEmptyStack(100);

    int i = 0;
    while (i<110)
    {
        Push(1, stack);
        i++;
    }
    i = i + 2;
    while (i > 0)
    {
       cout<<"pop stack = "<< Pop(stack)<<endl;
        i--;
    }

        return 0;
}
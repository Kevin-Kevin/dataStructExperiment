#include<stdio.h>
#include <iostream>
#define MAXSIZE 1024
using namespace std;
typedef int elemtype;
typedef struct {
	elemtype data[MAXSIZE];
	int last;
}SequenList;
bool cmp(int a,int b)
{
	return (b<a); 
} 
SequenList* init()
{
	SequenList* L;
	L=(SequenList*)malloc(sizeof(SequenList));
	L->last=-1;
	return L;
}
SequenList* creat(SequenList* L)
{
	int x;
	printf("请输入要存储的数据（以0为结束）：");
	scanf("%d",&x);
	while(1)
	{
		L->last++;
		L->data[L->last]=x;
		scanf("%d",&x);
		if(x==0)
			return L;
	} 
}
void Print(SequenList* L)
{
	int i;
	for(i=0;i<=L->last;i++)
		printf("%d ",L->data[i]);
	printf("\n");
}
void mumen()
{
	printf("1.删除\n");
	printf("2.插入\n");
	printf("3.查找\n");
	printf("4.排序\n");
	printf("5.销毁\n");
}
int find(SequenList* L,int x)
{
	int i,j;
	for(i=0;i<=L->last;i++)	
		if(L->data[i]==x)
			return i;
	return -1;
}
void delet(SequenList* L,int x)
{
	int i,j;
	for(i=0;i<=L->last&&L->data[i]!=x;i++);	
	for(j=i+1;j<=L->last;j++)
		L->data[j-1]=L->data[j];
	L->last--;
}
void insert(SequenList* L,int index)
{
	int data,i;
	if(index<1||index>L->last+2)
	{
		printf("位置错误!\n");
		return ;
	}
	printf("请输入要插入的数据：");
	scanf("%d",&data);
	for(i=L->last+1;i>index-1;i--)
	{
		L->data[i]=L->data[i-1];
	}
	L->data[i]=data;
	L->last++;
	printf("插入成功!\n");
}
void data_sort(SequenList* L)
{
	int x;
	printf("1.升序排序\n");
	printf("2.降序排序\n");
	scanf("%d",&x);
	if(x==1)
		sort(L->data,L->data+L->last+1);
	if(x==2)
		sort(L->data,L->data+L->last+1,cmp);
}
void destroy(SequenList* L)
{
	free(L);
}
int main()
{
	SequenList* L;
	L=init();
	L=creat(L);
	Print(L);
	
	int n,x,f,index,f1=0;
	while(1)
	{
		mumen();
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("请输入要删除的数据：");
				scanf("%d",&x);
				f=find(L,x);
				if(f==-1)
					printf("未找到该数\n");
				else
				{
					delet(L,x); 
					printf("删除成功!\n");
					Print(L);
				}
				break;
			case 2:
				printf("请选择要插入的位置：");
				scanf("%d",&index);
				insert(L,index); 
				
				Print(L);
				break;
			case 3:
				printf("请输入要查询的数据：");
				scanf("%d",&x);
				f=find(L,x);
				if(f==-1)
					printf("没有该数\n");
				else
					printf("存在该数,在第%d位\n",f+1);
				Print(L);
				break;				
			case 4:
				data_sort(L);
				Print(L); 
				break;
			case 5:
				destroy(L);
				printf("顺序表已销毁\n");
				f1=1;
		}	
		if(f1==1)
			break;
	}
}

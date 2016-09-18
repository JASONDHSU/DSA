#ifndef LINK_LIST_H  
#define LINK_LIST_H  
#include<stdlib.h>  
#include <stdio.h>  
typedef int ElementType;
#define MAXSIZE 20
typedef struct LNode *List;//List=struct LNode *，线性表结构指针
struct LNode {//把整个表当成一个结构
  ElementType Data[MAXSIZE];//数组
	int Last;//最后一个元素的位置
};//长度：Ptrl->last+1
extern struct LNode L;//结构体
extern List PtrL;//结构体指针

List MakeEmpty();//初始化
int Find(ElementType X, List PtrL);//（查找元素，数组头指针）
void Insert(ElementType X, int i, List PtrL);//x插在顺序表第i个位置
void Delete(int i, List PtrL);//删除顺序表上第i个位置的元素
void Traverse(List PtrL);//遍历

#endif // LINK_LIST_H  

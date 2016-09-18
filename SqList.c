#include "SqList.h"
//基本操作
//初始化：建立一个空的线性表
List MakeEmpty()
{
	List PtrL;//数组头指针
	PtrL = (List)malloc(sizeof(struct LNode));//分配LNode结构体
	PtrL->Last = -1;//last表示结构体内没有元素
	return PtrL;
}
//查找
int Find(ElementType X, List PtrL)//（查找元素，数组头指针）
{
	int i = 0;//循环变量
	while (i <= PtrL->Last && PtrL->Data[i] != X)
		i++;
	if (i > PtrL->Last) return -1; /* 如果没找到， 返回-1 */
	else return i; /* 找到后返回的是存储位置 */
}//O（n）复杂度
 //插入，数组，先每个元素都往后挪，再插入
void Insert(ElementType X, int i, List PtrL)//x插在顺序表第i个位置
{
	int j;//j是和指针数相连的，0-n
	if (PtrL->Last == MAXSIZE - 1) { /* 表空间已满，不能插入，指针从0开始*/
		printf("表满");
		return;
	}
	if (i < 1 || i > PtrL->Last + 2) { /*检查插入位置的合法性，位置是从1到n+1*/
		printf("位置不合法");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)
		PtrL->Data[j + 1] = PtrL->Data[j]; /*将 ai～ an倒序向后移动*/
	PtrL->Data[i - 1] = X; /*新元素插入*/
	PtrL->Last++; /*Last仍指向最后元素*/
	return;
}
//删除：先删除，后每个前挪
void Delete(int i, List PtrL)//删除顺序表上第i个位置的元素
{
	int j;//j是和指针数相连的，0 - n-1
	if (i < 1 || i > PtrL->Last + 1) { /*检查空表及删除位置的合法性,位置i从1到n*/
		printf("不存在第%d个元素", i);
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
		PtrL->Data[j - 1] = PtrL->Data[j]; /*将 ai+1～ an顺序向前移动*/
	PtrL->Last--; /*Last仍指向最后元素*/
	return;
}
//遍历
void Traverse(List PtrL)
{
	int i = 0;//位置：从1到N
	while (i <= PtrL->Last)
	{
		printf("%d\n", PtrL->Data[i]);
		i++;
	}
	printf("\n");
}

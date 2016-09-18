#include "SqList.h"
int main()
{
	List SqList = MakeEmpty();
	Insert(1, 1, SqList);
	Insert(3, 2, SqList);
	Insert(2, 3, SqList);
	Traverse(SqList);
	Delete(2, SqList);
	Traverse(SqList);
	int Location = Find(2, SqList);
	printf("%d", Location);
	getchar();
	return 0;
}

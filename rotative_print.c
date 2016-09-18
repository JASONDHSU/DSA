#include <stdio.h>
//循环实现：可以一直进行
int PrintN(int N)
{
	int i = 0;
	for (i = 1; i <= N; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}

int main()
{
	int N = 0;
	printf("n = ");
	scanf("%d", &N);
	PrintN(N);
	getchar();
	getchar();
	return 0;
}

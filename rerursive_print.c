#include <stdio.h>
//递归实现：占用空间，N取10W后崩溃
int PrintN(int N)
{
	if (N)
	{
		PrintN(N - 1);
		printf("%d\n", N);
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

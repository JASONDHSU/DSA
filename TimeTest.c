#include <stdio.h>
#include <time.h>
#include <math.h>//pow函数调用
clock_t start, stop;//clock_t是clock（）函数的返回类型
double duration;//记录时间，以秒为单位
#define MAXN 100//多项式项数
#define MAXK 1e5//被侧函数最大调用次数
double f1(int n, double a[], double x);//多项式相加算法一：一项一项地加
double f2(int n, double a[], double x);//多项式相加算法二：先算提取后最内层
				       //比如 f(x)=a0+x(a1+x(a2...x(an-1 + xan)...))
double f1(int n, double a[], double x)
{
	int i;
	double p = a[0];
	for (i = 1; i<n; i++)
		p += (a[i] * pow(x, i));
	return p;
}

double f2(int n, double a[], double x)
{
	int i;
	double p = a[n];
	for (i = n; i>0; i--)
		p = a[i - 1] + x*p;
	return p;
}

int main()
{
	int i;
	double a[MAXN];
	for (i = 0; i<MAXN; i++)
		a[i] = (double)i;
	//不在测试范围内的工作写在clock()之前

	start = clock();//开始计时
	for (i = 0; i<MAXK; i++)
		f1(MAXN, a, 1.1);//被测函数
	stop = clock();//停止计时
	duration = ((double)(stop - start)) / CLK_TCK;//计算运行时间
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

	start = clock();//开始计时
	for (i = 0; i<MAXK; i++)
		f2(MAXN, a, 1.1);//被测函数
	stop = clock();//停止计时
	duration = ((double)(stop - start)) / CLK_TCK;//计算运行时间
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

	//其他不在测试范围内的工作写在后面
	getchar();
	return 0;
}

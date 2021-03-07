#include<stdio.h>
//int main()
//{
//	int i = 0, a = 0;
//	while (i<20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0) break;
//			else i--;
//		}
//		i += 11; a += i;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//#define N 2
//#define M N+1
//#define NUM (M+1)*M/2
//int main()
//{
//	printf("%d\n", NUM);
//}
//int main()
//{
//	int n = 2;
//	n += n -= n*n;
//	printf("%d", n);
//	return 0;
//}
//#include <stdio.h>
void main()
{
	int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	p = a;
	k = &p;
	printf(" % d", *(p++));
	printf(" % d\n", **k);
	return 0;
}
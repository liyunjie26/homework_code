/*
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��



ʾ�� 1:

����: a = "11", b = "1"
���: "100"

ʾ�� 2:

����: a = "1010", b = "1011"
���: "10101"



��ʾ��

ÿ���ַ��������ַ� '0' �� '1' ��ɡ�
1 <= a.length, b.length <= 10^4
�ַ���������� "0" ���Ͷ�����ǰ���㡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-binary
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/
#include<stdio.h>
#include<string.h>
void changesort(char* a)//��ת�ַ���
{
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++)
	{
		char temp = a[i];
		a[i] = a[len - i - 1];
		a[len - 1 - i] = temp;
	}

}
char * addBinary(char * a, char * b){
	changesort(a);
	changesort(b);
	int length1 = strlen(a);
	int length2 = strlen(b);
	int capa = length1 > length2 ? length1 : length2;
	int carry = 0;
	char* arr = (char*)malloc(sizeof(char)*(capa+2));
	int len = 0;
	for (int i = 0; i < capa; ++i)
	{
		carry += i < length1 ? (a[i] == '1') : 0;
		carry += i < length2 ? (b[i] == '1') : 0;
		arr[len++] = carry % 2 + '0';
		carry = carry / 2;
	}
	if (carry)
		arr[len++] = '1';
	arr[len] = '\0';
	changesort(arr);
	return arr;
}
/*
����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��



ʾ�� 1��

���룺"ab-cd"
�����"dc-ba"

ʾ�� 2��

���룺"a-bC-dEf-ghIj"
�����"j-Ih-gfE-dCba"

ʾ�� 3��

���룺"Test1ng-Leet=code-Q!"
�����"Qedo1ct-eeLg=ntse-T!"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-only-letters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool is_char(char p)
{
	return (p >= 'a'&&p <= 'z') || (p >= 'A'&&p <= 'Z');
}
void swap(char* arr, int begin, int end)
{
	char temp = arr[begin];
	arr[begin] = arr[end];
	arr[end] = temp;
}
char * reverseOnlyLetters(char * S){
	int length = strlen(S);
	int begin = 0;
	int end = length - 1;
	while (begin < end)
	{
		if (is_char(S[begin]) && is_char(S[end]))
		{
			swap(S, begin, end);
			begin++;
			end--;
		}
		else if (!is_char(S[begin]))
			begin++;
		else
			end--;
	}
	return S;
}


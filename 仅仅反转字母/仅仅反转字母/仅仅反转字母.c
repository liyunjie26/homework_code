/*
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。



示例 1：

输入："ab-cd"
输出："dc-ba"

示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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


/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。



示例 1:

输入: a = "11", b = "1"
输出: "100"

示例 2:

输入: a = "1010", b = "1011"
输出: "10101"



提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include<stdio.h>
#include<string.h>
void changesort(char* a)//翻转字符串
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
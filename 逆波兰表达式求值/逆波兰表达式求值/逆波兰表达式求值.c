/*

���� �沨����ʾ��������ʽ��ֵ��

��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��



˵����

��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������



ʾ�� 1��

����: ["2", "1", "+", "3", "*"]
���: 9
����: ����ʽת��Ϊ��������׺�������ʽΪ��((2 + 1) * 3) = 9

ʾ�� 2��

����: ["4", "13", "5", "/", "+"]
���: 6
����: ����ʽת��Ϊ��������׺�������ʽΪ��(4 + (13 / 5)) = 6

ʾ�� 3��

����: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
���: 22
����:
����ʽת��Ϊ��������׺�������ʽΪ��
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22



�沨�����ʽ��

�沨�����ʽ��һ�ֺ�׺���ʽ����ν��׺����ָ���д�ں��档

ƽ��ʹ�õ���ʽ����һ����׺���ʽ���� ( 1 + 2 ) * ( 3 + 4 ) ��
����ʽ���沨�����ʽд��Ϊ ( ( 1 2 + ) ( 3 4 + ) * ) ��

�沨�����ʽ��Ҫ�����������ŵ㣺

ȥ�����ź���ʽ�����壬��ʽ����д�� 1 2 + 3 4 + * Ҳ�������ݴ���������ȷ�����
�ʺ���ջ�������㣺������������ջ�����������ȡ��ջ���������ֽ��м��㣬�������ѹ��ջ�С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
bool is_number(char* arr)
{
	int leng = strlen(arr);
	if (leng == 1 && (arr[0] == '+' || arr[0] == '-' || arr[0] == '*' || arr[0] == '/'))
		return false;
	return true;
}
int change_num(char* arr)
{
	if (arr[0] == '-')
	{
		int i = 1;
		int temp = 0;
		while (arr[i] != '\0')
		{
			temp = temp * 10 + arr[i] - '0';
			i++;
		}
		return temp*(-1);
	}
	else
	{
		int temp = 0;
		int i = 0;
		while (arr[i] != '\0')
		{
			temp = temp * 10 + arr[i] - '0';
			i++;
		}
		return temp;
	}
}

int evalRPN(char ** tokens, int tokensSize){
	int* number = (int *)malloc(sizeof(int)*tokensSize);
	int cur = 0;
	int begin = 0;
	while (begin < tokensSize)
	{
		if (is_number(tokens[begin]))
		{
			int temp = change_num(tokens[begin]);
			number[cur++] = temp;
			begin++;
		}
		else
		{
			int b = number[--cur];
			int a = number[--cur];
			switch ((int)tokens[begin++][0])
			{
			case 43:
				number[cur++] = a+b;
				break;
			case 45:
				number[cur++] = a - b;
				break;
			case 42:
				number[cur++] = a * b;
				break;
			case 47:
				number[cur++] = a / b;
				break;			
			}
		}
	}
	return number[--cur];
}
int main()
{
	char *arr[] = { { "10" }, { "13" }, { "5" }, { "/" }, {"+" }};

	int k = evalRPN(&arr,5);
	printf("%d", k);
	return 0;
}
/*


����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��



ʾ�� 1��

���룺digits = [1,2,3]
�����[1,2,4]
���ͣ����������ʾ���� 123��

ʾ�� 2��

���룺digits = [4,3,2,1]
�����[4,3,2,2]
���ͣ����������ʾ���� 4321��

ʾ�� 3��

���룺digits = [0]
�����[1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/plus-one
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

#include<stdio.h>
#include<malloc.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
	int end = digitsSize - 1;
	int count = (digits[end] + 1) / 10;
	digits[end] = (digits[end] + 1) % 10;
	end--;
	*returnSize = digitsSize;
	while (end >= 0)
	{
		digits[end] += count;
		count = digits[end] / 10;
		digits[end] = digits[end] % 10;
		end--;
		if (count == 0)
			break;
	}

	if (count == 1)
	{
		digits = (int*)realloc(digits, sizeof(int)*(digitsSize + 1));
		for (int i = digitsSize - 1; i >= 0; --i)
		{
			digits[i + 1] = digits[i];
		}
		digits[0] = count;
		*returnSize = digitsSize + 1;
	}
	return digits;
}
int main()
{

	int arr[] = { 9, 4, 5, 6 };
	int k = 0;
	int *arr1 = plusOne(arr, 4,&k);

	return 0;
}
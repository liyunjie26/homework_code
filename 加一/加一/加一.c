/*


给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。



示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：

输入：digits = [0]
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
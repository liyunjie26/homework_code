/*

给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。



示例 1:

输入: [1,2,3,1]
输出: true

示例 2:

输入: [1,2,3,4]
输出: false

示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



#include<stdbool.h>
#include<stdio.h>
int getMid(int* arr, int begin, int end)
{
	int mid = (end - begin) / 2 + begin;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])//begin<mid
			return mid;
		else if (arr[begin]>arr[end])
			return begin;
		else
			return end;
	}
}
void swap(int* arr, int begin, int end)
{
	int temp = arr[begin];
	arr[begin] = arr[end];
	arr[end] = temp;
}
//快速排序
int partion(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		
		while (begin < end && arr[end] >= key)
			end--;
		while (begin < end && arr[begin] <= key)
			begin++;
		swap(arr, begin, end);
	}
	swap(arr, start, begin);
	return begin;
}

void quickSort_1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int div = partion(arr, begin, end);
	quickSort_1(arr, begin, div - 1);
	quickSort_1(arr, div + 1, end);
}
bool containsDuplicate(int* nums, int numsSize){
	if (numsSize == 0 || numsSize == 1)
		return false;
	quickSort_1(nums, 0, numsSize - 1);
	int i = 0;
	for (; i < numsSize - 1; ++i)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}

int main()
{
	int arr[] = { 0,4,5,0,3,6};
	bool key = containsDuplicate(arr, 6);
	return 0;
}
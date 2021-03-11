/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。



示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]

示例 2：

输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<malloc.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if (n == 0)
		return;
	int *nums3 = (int*)malloc( sizeof(int)*(m + n));
	int i ,j,t ;
	i = j =t= 0;
	while (i<m && j <n)//两个数组依旧有元素
	{
		if (nums1[i] < nums2[j])
		{
			nums3[t++] = nums1[i];
			i++;
		}
		else
		{
			nums3[t++] = nums2[j];
			j++;
		}
	}
	if (i < m)
	{
		for (; i < m; ++i)
		{
			nums3[t++] = nums1[i];
		}
	}
	if (j< n)
	{
		for (; j < n; ++j)
		{
			nums3[t++] = nums2[j];
		}
	}
	for (int i = 0; i < (n + m); ++i)
	{
		nums1[i] = nums3[i];
	}
	free(nums3);
}
int main()
{
	int a1[] = { 1, 2, 3, 0, 0, 0 };
	int a2[] = { 2, 4, 5 };
	merge(a1,6, 3, a2,3, 3);
	return 0;
}
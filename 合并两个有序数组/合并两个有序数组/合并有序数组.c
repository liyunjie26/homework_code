/*
�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n ������Լ��� nums1 �Ŀռ��С���� m + n�������������㹻�Ŀռ䱣������ nums2 ��Ԫ�ء�



ʾ�� 1��

���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]

ʾ�� 2��

���룺nums1 = [1], m = 1, nums2 = [], n = 0
�����[1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<malloc.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if (n == 0)
		return;
	int *nums3 = (int*)malloc( sizeof(int)*(m + n));
	int i ,j,t ;
	i = j =t= 0;
	while (i<m && j <n)//��������������Ԫ��
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
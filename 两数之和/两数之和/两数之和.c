/*

����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣

����԰�����˳�򷵻ش𰸡�



ʾ�� 1��

���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��

ʾ�� 2��

���룺nums = [3,2,4], target = 6
�����[1,2]

ʾ�� 3��

���룺nums = [3,3], target = 6
�����[0,1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/two-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				int *arr = (int*)malloc(sizeof(int)* 2);
				arr[0] = i;
				arr[1] = j;
				*returnSize = 2;
				return arr;
			}
		}
	}
		*returnSize = 0;
		return NULL;
}



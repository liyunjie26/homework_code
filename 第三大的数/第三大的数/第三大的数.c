/*
����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������



ʾ�� 1��

���룺[3, 2, 1]
�����1
���ͣ������������ 1 ��

ʾ�� 2��

���룺[1, 2]
�����2
���ͣ����������������, ���Է��������� 2 ��

ʾ�� 3��

���룺[2, 2, 3, 1]
�����1
���ͣ�ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
��������ֵΪ2���������Ƕ��ŵڶ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/third-maximum-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/
#include<stdio.h>
int thirdMax(int* nums, int numsSize){
	int max, second, third, flag1, flag2;
	flag1=flag2 = 0;
	second = third = 0;
	max = nums[0];
	for (int i = 1; i < numsSize; i++){
		if ((nums[i] == max || (nums[i] == second && flag1 == 1) || (nums[i] == third) && flag2 == 1))
			continue;
		if (nums[i]>max)//���������ֵ������Ҫ�ж��Ƿ���ڵڶ���ֵ�����
		{
			if (flag1 == 0)//���ڶ�����û�з��ã����Դ˷���
			{	second = max;
				max = nums[i];
				flag1 = 1;}
			else//���ڶ��������ã�����Ըı��������ֵ
			{	third = second;
				second = max;
				max = nums[i];
				flag2 = 1;}}
		else//��С�����ֵ������Ҫ�жϵڶ���ֵ�Ƿ���ڣ���������ֱ�ӷ���
		{
			if (flag1 == 0){
				second = nums[i];
				flag1 = 1;}
			else//���ڶ���ֵ�Է��ã�����Ҫ�жϸ�ֵ��ڶ���ֵ����Դ�С
			{
				if (nums[i] > second)//���ȵڶ���ֵ��������Դ˷���
				{
					third = second;
					second = nums[i];
					flag2 = 1;}
				else
				{
					if (flag2 == 0){
						third = nums[i];
						flag2 = 1;}
					else if (nums[i] > third){
						third = nums[i];}}}}}
	if (flag2 == 0)
		return max;
	else
		return third;
}

int main()
{
	int arr[] = { 2,-2,3,-1};
	int k = thirdMax(arr, 4);
	printf("%d", k);
	return 0;
}
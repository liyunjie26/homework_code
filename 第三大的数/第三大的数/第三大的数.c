/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。



示例 1：

输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。

示例 2：

输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。

示例 3：

输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
		if (nums[i]>max)//若大于最大值，则需要判断是否存在第二大值的情况
		{
			if (flag1 == 0)//若第二个数没有放置，则以此放置
			{	second = max;
				max = nums[i];
				flag1 = 1;}
			else//若第二个数放置，则可以改变第三个的值
			{	third = second;
				second = max;
				max = nums[i];
				flag2 = 1;}}
		else//若小于最大值，则需要判断第二个值是否存在，不存在则直接放置
		{
			if (flag1 == 0){
				second = nums[i];
				flag1 = 1;}
			else//若第二个值以放置，则需要判断该值与第二个值的相对大小
			{
				if (nums[i] > second)//若比第二个值大，则后面以此放置
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
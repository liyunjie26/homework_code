/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。



示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。



提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int* A, int begin, int end)
{
	int temp = A[begin];
	A[begin] = A[end];
	A[end] = temp;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int begin = 0;
	int end = ASize - 1;
	while (begin < end)
	{
		if (A[begin] % 2 == 1 && A[end] % 2 == 0)
		{
			swap(A, begin, end);
			begin++;
			end--;
		}
		else if (A[begin] % 2 == 0)
			begin++;
		else
			end--;
	}
	*returnSize = ASize;
	return A;
}


int main()
{
	int arr[] = { 3, 1, 2, 4 };
	int k = 0;
	int* abb = sortArrayByParity(arr, 4, &k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", abb[i]);
	}
	return 0;
}

/*
����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�

����Է���������������κ�������Ϊ�𰸡�



ʾ����

���룺[3,1,2,4]
�����[2,4,3,1]
��� [4,2,3,1]��[2,4,1,3] �� [4,2,1,3] Ҳ�ᱻ���ܡ�



��ʾ��

1 <= A.length <= 5000
0 <= A[i] <= 5000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sort-array-by-parity
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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

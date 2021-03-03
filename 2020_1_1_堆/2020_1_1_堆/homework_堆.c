#include<stdlib.h>
#include<stdio.h>

typedef int HPDataType;

typedef struct Heap

{

	HPDataType* _a;

	int _size;

	int _capacity;

}Heap;
//��Ҫ��һ����ʼ���Ķ�

void InitHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
//��Ҫһ���ռ���ĺ���
void cheakCapacity(Heap* hp)
{
	if (hp == NULL)
		return;
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
}
void Swap(int* arr, int member1, int member2)
{
	int temp = arr[member1];
	arr[member1] = arr[member2];
	arr[member2] = temp;

}
//�ѵĹ�����������Ҫ�������������Լ���������
//��������С���Ӻ���,��������Ĭ����С��
void shiftDown_min(int* arr, int n, int curPose)
{
	int child = 2 * curPose + 1;//��ǰλ���µ�����
	//�ҵ� ���Һ�������С�ģ��ж��Ƿ���Ҫ���н���
	while (child < n)
	{
		if (child + 1 < n&&arr[child] > arr[child + 1])
			child++;
		if (arr[child] < arr[curPose])
		{
			Swap(arr, child, curPose);
			curPose = child;//���µ�ǰλ��
			child = 2 * curPose + 1;
		}
		else
			break;
	}
}
//���µ��������
void shiftDown_max(int* arr, int n, int curPose)
{
	int child = 2 * curPose + 1;//��ǰλ���µ�����
	//�ҵ� ���Һ��������ģ��ж��Ƿ���Ҫ���н���
	while (child < n)
	{
		if (child + 1 < n&&arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[curPose])
		{
			Swap(arr, child, curPose);
			curPose = child;//���µ�ǰλ��
			child = 2 * curPose + 1;
		}
		else
			break;
	}
}
//�ѵ���������
void Heapsort_up_min(HPDataType* arr, int n, int curPose)//С��
{
	int parent = (curPose - 1) / 2;
	while (curPose > 0)
	{
		if (arr[curPose] < arr[parent])
		{
			Swap(arr, curPose, parent);
			curPose = parent;
			parent = (curPose - 1) / 2;
		}
		else
			break;
	}
}

//�ѵ����ϵ���
void Heapsort_up_max(HPDataType* arr, int n, int curPose)//���
{
	int parent = (curPose - 1) / 2;
	while (curPose > 0)
	{
		if (arr[curPose] > arr[parent])
		{
			Swap(arr, curPose, parent);
			curPose = parent;
			parent = (curPose - 1) / 2;
		}
		else
			break;
	}
}


// �ѵĲ��룬Ҫ����������������Ҫ��һ����������ĺ���

void HeapPush_min(Heap* hp, HPDataType x)//С�Ѳ���
{
	//�������
	cheakCapacity(hp);
	//β��
	hp->_a[hp->_size++] = x;
	//����������
	Heapsort_up_min(hp->_a, hp->_size, hp->_size - 1);

}
void HeapPush_max(Heap* hp, HPDataType x)//��Ѳ���
{
	//�������
	cheakCapacity(hp);
	//β��
	hp->_a[hp->_size++] = x;
	//����������
	Heapsort_up_max(hp->_a, hp->_size, hp->_size - 1);

}

// �ѵĹ���
//ʵ�����Ǵ����һ����Ҷ�ӽڵ㿪ʼ�����µ�����֮����������ǰ�����ϵ���
void HeapCreate_min(Heap* hp, HPDataType* a, int n)//��С��,�������ǲ��ý�����ֱ�ӽ������е�Ԫ�ز�����У����ı�ԭ�����˳��
{
	int i=0;
	while (i < n)
	{
		HeapPush_min(hp, a[i]);
		i++;
	}
}

// �ѵ�����

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	free(hp);

}


// �ѵ�ɾ��

void HeapPop_min(Heap* hp)//�����Ѷ�Ԫ�������һ��Ҷ�ӽڵ㣬ɾ��Ҷ�ӽڵ㣬����ʱ�ĶѶ�Ԫ�ؽ�����������
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	shiftDown_min(hp->_a, hp->_size, 0);
}
void HeapPop_max(Heap* hp)//��ѣ������Ѷ�Ԫ�������һ��Ҷ�ӽڵ㣬ɾ��Ҷ�ӽڵ㣬����ʱ�ĶѶ�Ԫ�ؽ�����������
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	shiftDown_max(hp->_a, hp->_size, 0);
}

// ȡ�Ѷ�������

HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// �ѵ����ݸ���

int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�

int HeapEmpty(Heap* hp)
{

	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}



// ��������ж�����

void HeapSort_min(int* a, int n)//��С���󣬵���������ѣ������һ����Ҷ�ӽڵ�������µ���
{
	int curPose = (n - 2) / 2;
	while (curPose >= 0)
	{
		shiftDown_max(a, n, curPose);
		curPose--;
	}
	//�������֮�󣬽��Ѷ�Ԫ����ĩβԪ�ؽ���֮�������������
	int end = n - 1;
	while (end != 0)
	{
		Swap(a, 0, end);
		end--;
		shiftDown_max(a, end+1, 0);
	}
}
void HeapSort_max(int* a, int n)//�Ӵ�С
{
	int curPose = (n - 2) / 2;
	while (curPose >= 0)
	{
		shiftDown_min(a, n, curPose);
		curPose--;
	}
	//�������֮�󣬽��Ѷ�Ԫ����ĩβԪ�ؽ���֮�������������
	int end = n - 1;
	while (end != 0)
	{
		Swap(a, 0, end);
		end--;
		shiftDown_min(a, end + 1, 0);
	}
}




// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣

// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬

// ��Ҫע�⣺

// ������ǰK��������K������С��

// ����С��ǰK��������K�����Ĵ��

void PrintTopK_min(int* a, int n, int k)
{
	//���Ƚ��ж�����
	HeapSort_min(a, n);
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);

	}
}
void PrintTopK_max(int* a, int n, int k)
{
	//���Ƚ��ж�����
	HeapSort_max(a, n);
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);

	}
}
void printARR(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
		printf("%d", a[i]);
}
void TestTopk()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1,32,31,65,64,98,78};
	int n = sizeof(a) / sizeof(a[0]);
	PrintTopK_min(a, n, 8);
	printf("\n");
	PrintTopK_max(a, n, 8);


}
int main()
{
	TestTopk();
	return 0;
}

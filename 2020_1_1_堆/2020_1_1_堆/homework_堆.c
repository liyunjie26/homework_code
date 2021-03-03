#include<stdlib.h>
#include<stdio.h>

typedef int HPDataType;

typedef struct Heap

{

	HPDataType* _a;

	int _size;

	int _capacity;

}Heap;
//需要有一个初始化的堆

void InitHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
//需要一个空间检查的函数
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
//堆的构建与排序需要利用向上排序，以及向下排序
//向下排序小堆子函数,向下排序默认是小堆
void shiftDown_min(int* arr, int n, int curPose)
{
	int child = 2 * curPose + 1;//当前位置下的左孩子
	//找到 左右孩子中最小的，判断是否需要进行交换
	while (child < n)
	{
		if (child + 1 < n&&arr[child] > arr[child + 1])
			child++;
		if (arr[child] < arr[curPose])
		{
			Swap(arr, child, curPose);
			curPose = child;//更新当前位置
			child = 2 * curPose + 1;
		}
		else
			break;
	}
}
//向下调整，大堆
void shiftDown_max(int* arr, int n, int curPose)
{
	int child = 2 * curPose + 1;//当前位置下的左孩子
	//找到 左右孩子中最大的，判断是否需要进行交换
	while (child < n)
	{
		if (child + 1 < n&&arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[curPose])
		{
			Swap(arr, child, curPose);
			curPose = child;//更新当前位置
			child = 2 * curPose + 1;
		}
		else
			break;
	}
}
//堆的向上排序
void Heapsort_up_min(HPDataType* arr, int n, int curPose)//小堆
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

//堆的向上调整
void Heapsort_up_max(HPDataType* arr, int n, int curPose)//大堆
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


// 堆的插入，要进行向上排序，首先要有一个向上排序的函数

void HeapPush_min(Heap* hp, HPDataType x)//小堆插入
{
	//检查容量
	cheakCapacity(hp);
	//尾插
	hp->_a[hp->_size++] = x;
	//走向上排序
	Heapsort_up_min(hp->_a, hp->_size, hp->_size - 1);

}
void HeapPush_max(Heap* hp, HPDataType x)//大堆插入
{
	//检查容量
	cheakCapacity(hp);
	//尾插
	hp->_a[hp->_size++] = x;
	//走向上排序
	Heapsort_up_max(hp->_a, hp->_size, hp->_size - 1);

}

// 堆的构建
//实际上是从最后一个非叶子节点开始走向下调整，之后在依次向前走向上调整
void HeapCreate_min(Heap* hp, HPDataType* a, int n)//建小堆,这里我们采用将采用直接将数组中的元素插入堆中，不改变原数组的顺序
{
	int i=0;
	while (i < n)
	{
		HeapPush_min(hp, a[i]);
		i++;
	}
}

// 堆的销毁

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	free(hp);

}


// 堆的删除

void HeapPop_min(Heap* hp)//交换堆顶元素与最后一个叶子节点，删除叶子节点，将此时的堆顶元素进行向下排序
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	shiftDown_min(hp->_a, hp->_size, 0);
}
void HeapPop_max(Heap* hp)//大堆，交换堆顶元素与最后一个叶子节点，删除叶子节点，将此时的堆顶元素进行向下排序
{
	if (hp == NULL || hp->_size == 0)
		return;
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	shiftDown_max(hp->_a, hp->_size, 0);
}

// 取堆顶的数据

HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// 堆的数据个数

int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空

int HeapEmpty(Heap* hp)
{

	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}



// 对数组进行堆排序

void HeapSort_min(int* a, int n)//从小到大，递增，建大堆，从最后一个非叶子节点进行向下调整
{
	int curPose = (n - 2) / 2;
	while (curPose >= 0)
	{
		shiftDown_max(a, n, curPose);
		curPose--;
	}
	//建堆完成之后，将堆顶元素与末尾元素交换之后进行向下排序
	int end = n - 1;
	while (end != 0)
	{
		Swap(a, 0, end);
		end--;
		shiftDown_max(a, end+1, 0);
	}
}
void HeapSort_max(int* a, int n)//从大到小
{
	int curPose = (n - 2) / 2;
	while (curPose >= 0)
	{
		shiftDown_min(a, n, curPose);
		curPose--;
	}
	//建堆完成之后，将堆顶元素与末尾元素交换之后进行向下排序
	int end = n - 1;
	while (end != 0)
	{
		Swap(a, 0, end);
		end--;
		shiftDown_min(a, end + 1, 0);
	}
}




// TopK问题：找出N个数里面最大/最小的前K个问题。

// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，

// 需要注意：

// 找最大的前K个，建立K个数的小堆

// 找最小的前K个，建立K个数的大堆

void PrintTopK_min(int* a, int n, int k)
{
	//首先进行堆排序
	HeapSort_min(a, n);
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);

	}
}
void PrintTopK_max(int* a, int n, int k)
{
	//首先进行堆排序
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

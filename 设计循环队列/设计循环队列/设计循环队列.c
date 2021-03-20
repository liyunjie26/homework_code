
/*������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

���ʵ��Ӧ��֧�����²�����

MyCircularQueue(k) : �����������ö��г���Ϊ k ��
Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
	Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
		   enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
		   deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
		   isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
		   isFull() : ���ѭ�������Ƿ�������



		   ʾ����

		   MyCircularQueue circularQueue = new MyCircularQueue(3); // ���ó���Ϊ 3
circularQueue.enQueue(1);  // ���� true
circularQueue.enQueue(2);  // ���� true
circularQueue.enQueue(3);  // ���� true
circularQueue.enQueue(4);  // ���� false����������
circularQueue.Rear();  // ���� 3
circularQueue.isFull();  // ���� true
circularQueue.deQueue();  // ���� true
circularQueue.enQueue(4);  // ���� true
circularQueue.Rear();  // ���� 4



��ʾ��

���е�ֵ���� 0 �� 1000 �ķ�Χ�ڣ�
���������� 1 �� 1000 �ķ�Χ�ڣ�
�벻Ҫʹ�����õĶ��п⡣

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/design-circular-queue
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//�涨���г���Ϊk����������0~k-1,ʵ�ʴ洢Ϊk-��Ԫ��
//�� ��front==rear���նӣ���(front-rear+k)%k==1,�����
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
//���ѭ�����п���ʹ������Ľṹ������ƣ�����front��rear֮��Ĺ�ϵ����ѭ��
typedef struct MyCircularQueue
{
	int* arr;
	int Front;
	int Rear;
	int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	struct MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

	queue->arr = (int*)malloc(sizeof(int)*(k+1));
	queue->Front = queue->Rear = 0;
	queue->capacity = k+1;
	return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->Front == obj->Rear)
		return true;
	else
		return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->Front == obj->Rear || obj == NULL)
		return false;
	obj->Front++;
	if (obj->Front == obj->capacity)
		obj->Front = 0;
	return true;
}



int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj == NULL || myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->Rear == 0)
		return obj->arr[obj->capacity - 1];
	else
		return obj->arr[obj->Rear-1];
}


int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj == NULL || myCircularQueueIsEmpty(obj))
		return -1;
	return obj->arr[obj->Front];
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj == NULL)
		return true;//��ѭ�����в���������Ϊ���أ�
	if ((obj->Front + obj->capacity - obj->Rear) % obj->capacity == 1)
		return true;
	else
		return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj == NULL || myCircularQueueIsFull(obj))
		return false;
	obj->arr[obj->Rear] = value;
	obj->Rear++;
	if (obj->Rear == obj->capacity)
		obj->Rear = 0;
	return true;
}
void myCircularQueuePrint(MyCircularQueue* obj)
{
	int start = obj->Front;
	while (!myCircularQueueIsEmpty(obj))
	{
		int op = myCircularQueueFront(obj);
		printf("%d ", op);
		myCircularQueueDeQueue(obj);
		
	}
	obj->Front = start;
}


int main()
{
	int k = 3;
	MyCircularQueue* obj = myCircularQueueCreate(k);
	bool a = myCircularQueueEnQueue(obj, 1);
	bool b = myCircularQueueEnQueue(obj, 2);

	bool c = myCircularQueueEnQueue(obj, 3);

	bool d = myCircularQueueEnQueue(obj, 4);

	myCircularQueuePrint(obj);
	printf("\n");

	bool param_2 = myCircularQueueDeQueue(obj);
	myCircularQueuePrint(obj);
	printf("\n");

	int param_3 = myCircularQueueFront(obj);
	printf("%d", param_3);
	printf("\n");
	bool e = myCircularQueueEnQueue(obj, 4);
	myCircularQueuePrint(obj);
	printf("\n");
	int param_4 = myCircularQueueRear(obj);
	printf("%d", param_4);
	printf("\n");


	bool param_5 = myCircularQueueIsEmpty(obj);

	bool param_6 = myCircularQueueIsFull(obj);
	printf("%d  %d", param_5, param_6);

	myCircularQueueFree(obj);
}
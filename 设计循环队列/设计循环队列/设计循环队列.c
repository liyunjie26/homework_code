
/*设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k) : 构造器，设置队列长度为 k 。
Front : 从队首获取元素。如果队列为空，返回 - 1 。
	Rear : 获取队尾元素。如果队列为空，返回 - 1 。
		   enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
		   deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
		   isEmpty() : 检查循环队列是否为空。
		   isFull() : 检查循环队列是否已满。



		   示例：

		   MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4



提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/design-circular-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//规定队列长度为k，数组坐标0~k-1,实际存储为k-个元素
//即 当front==rear即空队，当(front-rear+k)%k==1,则队满
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
//设计循环队列可以使用数组的结构进行设计，利用front与rear之间的关系进行循环
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
		return true;//若循环队列不存在则作为满载；
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
#define  _CRT_SECURE_NO_WARNINGS
#include"queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,2);
	QueuePush(&q,3);
	QueuePush(&q,4);
	QueuePush(&q,5);
	QueuePush(&q,6);
	while (!QueueEmpty(&q))//空为非零  取反为假
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}

int main()
{
	test1();
	return 0;
}
#include <stdio.h>


/*二叉链表的存储结构定义*/

typedef char Datatype;
typedef struct BiNode
{
	Datatype data;
	struct BiNode *lchild, *rchild;
}BiNode;


/*二叉链表的层序遍历*/
#define MaxSize 100
void LevelOrder(BiNode *root)  //输入为二叉树的根指针
{
	BiNode *q = NULL;           //设置工作指针
	BiNode *Q[MaxSize];         //定义一个指针队列用来存放已经访问过得结点
	int front = -1, rear = -1;  //设置队头队尾两个变量，初始化队列

	if (root = NULL)  return;   //二叉树为空，算法结束
	Q[++rear] = root;           //根指针入队

	while (front != rear)
	{
		q = Q[++front];         //队头元素出队
		printf("%c", q->data);

		if (q->lchild != NULL)  Q[++rear] = q->lchild;
		if (q->rchild != NULL) Q[++rear] = q->rchild;
	}

}

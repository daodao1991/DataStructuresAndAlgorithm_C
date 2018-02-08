#include <stdio.h>


/*��������Ĵ洢�ṹ����*/

typedef char Datatype;
typedef struct BiNode
{
	Datatype data;
	struct BiNode *lchild, *rchild;
}BiNode;


/*��������Ĳ������*/
#define MaxSize 100
void LevelOrder(BiNode *root)  //����Ϊ�������ĸ�ָ��
{
	BiNode *q = NULL;           //���ù���ָ��
	BiNode *Q[MaxSize];         //����һ��ָ�������������Ѿ����ʹ��ý��
	int front = -1, rear = -1;  //���ö�ͷ��β������������ʼ������

	if (root = NULL)  return;   //������Ϊ�գ��㷨����
	Q[++rear] = root;           //��ָ�����

	while (front != rear)
	{
		q = Q[++front];         //��ͷԪ�س���
		printf("%c", q->data);

		if (q->lchild != NULL)  Q[++rear] = q->lchild;
		if (q->rchild != NULL) Q[++rear] = q->rchild;
	}

}

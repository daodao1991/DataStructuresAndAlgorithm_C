#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MaxSize 100

/*�����������Ľ������*/
typedef char DataType;
typedef struct Binode
{
	DataType data;
	struct Binode *lchild, *rchild;
}Binode;


/*����������Ľ���*/
Binode* CreateBiTree(Binode* root)
{

	char ch;
	scanf("%c", &ch);

	if (ch == '#')  root = NULL;
	else
	{
		root = (Binode*)malloc(sizeof(Binode));
		root->data = ch;
		root->lchild = CreateBiTree(root->lchild);
		root->rchild = CreateBiTree(root->rchild);
	}



	return root;
}



/*����������ǰ������ĵݹ��㷨*/
void PreOrder_Recursive(Binode* root)
{
	if (root == NULL)  return;
	else
	{
		printf("%c", root->data);
		PreOrder_Recursive(root->lchild);
		PreOrder_Recursive(root->rchild);
	}
}



/*����������ǰ������ķǵݹ��㷨*/
void PreOrder(Binode* root)
{
	Binode* S[MaxSize];  /*���幤��ջ*/
	Binode* bt = root;
	int top = -1;

	while (bt != NULL || top != -1)
	{
		while (bt != NULL)
		{
			printf("%c", bt->data);
			S[++top] = bt;         /*��bt�д�ŵĽ��ѹ��ջ�У��Ա�֮��ͨ���ý���ҵ�����������*/
			bt = bt->lchild;
		}

		if (top != -1)
		{
			bt = S[top--];
			bt = bt->rchild;
		}
	}
}



int main()
{
	Binode* root = NULL;        /*����������ĸ�ָ�����*/
	printf("������һ����������Ӧ��չ��������ǰ���������:\n");
	root = CreateBiTree(root);
	printf("\n\n");

	printf("�ö������ĸ�����ǣ�%c", root->data);
	printf("\n\n");

	printf("�ö������ġ��ݹ顿ǰ���������Ϊ��\n");
	PreOrder_Recursive(root);
	printf("\n\n");

	printf("�ö������ġ��ǵݹ顿ǰ���������Ϊ��\n");
	PreOrder(root);
	printf("\n\n");

	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MaxSize 100

/*定义二叉链表的结点类型*/
typedef char DataType;
typedef struct Binode
{
	DataType data;
	struct Binode *lchild, *rchild;
}Binode;


/*二叉树链表的建立*/
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



/*二叉树链表前序遍历的递归算法*/
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



/*二叉树链表前序遍历的非递归算法*/
void PreOrder(Binode* root)
{
	Binode* S[MaxSize];  /*定义工作栈*/
	Binode* bt = root;
	int top = -1;

	while (bt != NULL || top != -1)
	{
		while (bt != NULL)
		{
			printf("%c", bt->data);
			S[++top] = bt;         /*将bt中存放的结点压入栈中，以备之后通过该结点找到它的右子树*/
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
	Binode* root = NULL;        /*定义二叉树的根指针变量*/
	printf("请输入一个二叉树对应扩展二叉树的前序遍历序列:\n");
	root = CreateBiTree(root);
	printf("\n\n");

	printf("该二叉树的根结点是：%c", root->data);
	printf("\n\n");

	printf("该二叉树的【递归】前序遍历序列为：\n");
	PreOrder_Recursive(root);
	printf("\n\n");

	printf("该二叉树的【非递归】前序遍历序列为：\n");
	PreOrder(root);
	printf("\n\n");

	system("pause");
	return 0;
}
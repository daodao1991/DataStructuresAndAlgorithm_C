/*********************************************************
***************无向图的深度优先生成树算法*****************
*********************************************************/

/*****以孩子兄弟表示法作为树的存储结构，即二叉链表树********/

typedef struct CSNode
{
	ElemType   data;              //数据域
	struct CSNode  *firstchild;   //指向第一个孩子结点的指针
	struct CSNode  *nextsibling;  //指向第一个孩子结点右兄弟的指针
}CSNode, *CSTree;


void DFSTree(ALGraph G, int v, CSTree &T)
//从第v个顶点出发，深度优先遍历图G，建立以T为根的生成树
{
	int w;
	CSTree p, q;

	boolean first = TRUE;
	visited[v] = TRUE;
	for(w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v,w))
	{
		if(!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode));
			*p = {GetVex(G, w), NULL, NULL};
			
			if(first)               //w是v的第一个未被访问的邻接点
			{
				T->firstchild = p;  //是根的左孩子结点，只在第一次起作用
				first = FALSE;
			}
			else					//w是v的其他的未被访问的邻接点
			{
				q->nextsibling = p; //是上一个邻接点的右兄弟结点
			}
			q = p;
			DFSTree(G, w, q);   //从第w个顶点出发深度优先遍历图G,建立子生成树q
		}
	}
}

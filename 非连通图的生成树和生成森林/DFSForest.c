/*********************************************************
***************无向图的生成森林算法*****************
*********************************************************/

/*****以孩子兄弟链表作为森林的存储结构********/




typedef struct CSNode
{
	ElemType   data;              //数据域
	struct CSNode  *firstchild;   //指向第一个孩子结点的指针
	struct CSNode  *nextsibling;  //指向第一个孩子结点右兄弟的指针
}CSNode, *CSTree;



/***DFSTree算法***/
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



/***图的生成森林算法***/
void DFSForest(ALGraph, CSTree &T)
	//建立无向图G的深度优先生成森林的孩子兄弟链表T
{
	int v;
	CSTree p, q;

	T = NULL;
	for(v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for(v = 0; v < G.vexnum; ++v)
	{
		if(!visited[v])  //第v个顶点为新的生成树的根结点，经历过DFSTree()后，基本上都访问了
		{
			p = (CSTree)malloc(sizeof(CSNode));  //分配根结点
			*p = {GetVex(G, v), NULL, NULL};	 //给结点赋值

			if(!T)
			{
				T = p;   //第一次时起作用，即第一颗生成树的根
			}
			else
			{
				q->nextsibling = p; //是前一颗生成树的根的右兄弟，并且是先有下一句，才能有这句
			}
			q = p;              //q指示当前生成树的根
			DFSTree(G, v, p);   //建立以p为根的生成树
		}
	}
}

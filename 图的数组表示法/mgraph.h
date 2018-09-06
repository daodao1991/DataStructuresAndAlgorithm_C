/****************头文件（图的数组表示法）******************/
/***********************************************************
图的邻接矩阵（Adjacency Matrix）存储方式是用两个数组表示图，即：
一个一维数组存储图中的顶点信息，一个二维数组（即邻接矩阵）存储图中的边或弧的信息
************************************************************/

#define True 1
#define ERROR 0
#define OK 1
#define FALSE 0



/*图的邻接矩阵存储结构*/
#define INFINITY 65535						//表示无穷大，在带权的图中用到，即网
#define MAX_VERTEX_NUM 20					//图中的最大顶点数
#define MAX_INFO 20							//每条弧附带信息的最大长度

typedef int Status;
typedef int VRType;							//顶点关系类型
typedef char InfoType;						//附加信息类型
typedef int VertexType;						//顶点数据类型
typedef enum{DG, DN, UDG, UDN} GraphKind;	//图的种类:分别代表有向图，有向网，无向图，无向网
typedef struct ArcCell {
	VRType  adj;							//顶点关系类型，对无权图用1或0表示是否相邻；对带权图，则为权值类型
	InfoType  *info;						//该弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType  vexs[MAX_VERTEX_NUM];		//顶点向量
	AdjMatrix   arcs;						//邻接矩阵
	int         vexnum, arcnum;				//图的当前顶点数和弧数
	GraphKind   kind;						//图的种类标志
}MGraph;




/*在邻接矩阵存储结构MGraph上对图的构造操作*/
int visited[MAX_VERTEX_NUM];     //数组标记某元素是否被访问过

Status CreateGraph(MGraph *G);   //根据图的种类创建图

Status CreateUDG(MGraph *G);     //创建无向图

Status CreateDG(MGraph *G);      //创建有向图

Status CreateUGN(MGraph *G);     //创建无向网

Status CreateDN(MGraph *G);     //创建有向网


								
/*基本操作*/
//返回某顶点在图中的位置
int LocateVex(MGraph G, VertexType v);

//打印元素
Status PrintElem(VertexType elem);

//深度优先遍历图
Status DFSTraverse(MGraph G, Status(*Visit) (VertexType));

//深度优先递归遍历
void DFS(MGraph G, int i, Status(*Visit) (VertexType));

//返回v的值
VertexType GetVex(MGraph G, int v);

//对v进行赋值
Status PutVex(MGraph *G, int v, VertexType value);

//返回v的第一个邻接顶点
int FirstAdjVex(MGraph G, int v);

//w是v的邻接点，返回v相对于w的下一个邻接点
int NextAdjVex(MGraph G, int v, int w);

//插入一个顶点，但是不进行插入弧
Status InsertVex(MGraph *G, VertexType v);

//删除一个顶点和相关的弧
Status DeleVex(MGraph *G, VertexType v);

//在顶点v,w间插入一段弧或边
Status InsertArc(MGraph *G, VertexType v, VertexType w);

//删除一段弧或边，但是不删除顶点
Status DeleArc(MGraph *G, VertexType v, VertexType w);

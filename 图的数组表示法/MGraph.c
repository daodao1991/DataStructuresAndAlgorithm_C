/*******************具体实现文件**********************/


#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"  //自己创建的头文件，加双引号""，而不是尖括号


/*在邻接矩阵存储结构MGraph上对图的构造操作的实现框架*/
Status CreateGraph(MGraph *G) {
	printf("please enter the kind of the graph(DG:0,DN:1,UDG:2,UDN:3):");
	scanf("%d", &(*G).kind);
	switch ((*G).kind) {
		case UDG:
			return CreateUDG(G);
			break;
		case DG:
			return CreateDG(G);
			break;
		case UDN:
			return CreateUDN(G);
			break;
		case DN:
			return CreateDN(G);
			break;
		default:
			return ERROR;

	}
}
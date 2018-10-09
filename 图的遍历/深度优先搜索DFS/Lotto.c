/*
  题意：k个数（输入保证k个数递增有序）中取6个数，按字典序由小到
  大、每种方案中的6个数递增有序输出所有方案。输入数据不是最后一
  组时，换行。
*/

#include<stdio.h>
#include<string.h>

#define max_num 20  


int n, nums[max_num];
int visited[max_num];
int res[max_num];     /*定义在最上边，即为全局变量*/

void DFS(int cur, int idx)
{
	int i;
	if(cur == 6)
	{
		for(i = 0; i < cur-1; i++)
			printf("%d ", res[i]);
		printf("%d\n", res[cur-1]);
		return;
	}
	
	for(i = idx; i < n; i++)
	{
		if(!visited[i]) //如果这个位置没有被访问过
		{
			visited[i] = 1; //标记
			res[cur] = nums[i];
			DFS(cur+1, i);
			visited[i] = 0; //恢复初始状态
		}
	}
}


int main()
{
	int i;
	int flag = 1;
	while(scanf("%d", &n) != EOF)	
	{
		if(n == 0)
			break;
		else
		{
			if(flag == 1)
				flag = 0;
			else
				printf("\n");
		}

		for(i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		memset(visited, 0, sizeof(visited)); //将visited数组中的所有元素置为0
		DFS(0, 0);
	}
	return 0;
}

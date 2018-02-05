#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

char *str1[4] = { "梅花","黑桃","红桃","方块" };
char *str2[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
char *card[13];  //存储随即产生的纸牌，假设最多发13张牌

void SendCards(int n);
void PrintCards(int n);

int main()
{
	int n;
	printf("请输入发多少张牌：");
	scanf_s("%d", &n);
	SendCards(n);  //随机产生n张纸牌，并存储到数组card中
	PrintCards(n);

	system("pause");
	return 0;
}

void SendCards(int n)
{
	int i, j, k;
	int len1, len2;
	int sign[4][13] = { 0 }; /*用来记录随机产生的每张牌是否之前已经发过，
							   1表示发过，0表示未发过*/
	
	srand((unsigned)time(NULL));
	
	for (k = 0; k < n;)
	{
		i = rand() % 4;  //随机产生花色下标
		j = rand() % 13;  //随机产生点数下标

		if (sign[i][j] == 1)	continue;  /*表示产生的这张牌之前发过  
		!!!注意此处是“==”判断，不是“=”赋值*/
		else
		{
			card[k] = (char*)malloc(10);  //保存一张牌需要6个字节，例如"梅花10"
			len1 = strlen(str1[i]);
			len2 = strlen(str2[j]);
			strcpy_s(card[k], len1 + 1, str1[i]);  //第二个参数为后面要复制的字符串的长度+1
			strcat_s(card[k], len1 + len2 + 1, str2[j]);  //第二个参数为合并字符串后的字符数量+1
			sign[i][j] = 1;
			k++;
		}

	}

}
void PrintCards(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", card[i]);
	}
	printf("\n");
}
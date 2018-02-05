#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

char *str1[4] = { "÷��","����","����","����" };
char *str2[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
char *card[13];  //�洢�漴������ֽ�ƣ�������෢13����

void SendCards(int n);
void PrintCards(int n);

int main()
{
	int n;
	printf("�����뷢�������ƣ�");
	scanf_s("%d", &n);
	SendCards(n);  //�������n��ֽ�ƣ����洢������card��
	PrintCards(n);

	system("pause");
	return 0;
}

void SendCards(int n)
{
	int i, j, k;
	int len1, len2;
	int sign[4][13] = { 0 }; /*������¼���������ÿ�����Ƿ�֮ǰ�Ѿ�������
							   1��ʾ������0��ʾδ����*/
	
	srand((unsigned)time(NULL));
	
	for (k = 0; k < n;)
	{
		i = rand() % 4;  //���������ɫ�±�
		j = rand() % 13;  //������������±�

		if (sign[i][j] == 1)	continue;  /*��ʾ������������֮ǰ����  
		!!!ע��˴��ǡ�==���жϣ����ǡ�=����ֵ*/
		else
		{
			card[k] = (char*)malloc(10);  //����һ������Ҫ6���ֽڣ�����"÷��10"
			len1 = strlen(str1[i]);
			len2 = strlen(str2[j]);
			strcpy_s(card[k], len1 + 1, str1[i]);  //�ڶ�������Ϊ����Ҫ���Ƶ��ַ����ĳ���+1
			strcat_s(card[k], len1 + len2 + 1, str2[j]);  //�ڶ�������Ϊ�ϲ��ַ�������ַ�����+1
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
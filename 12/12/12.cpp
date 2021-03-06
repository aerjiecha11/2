
#include"graph1.h"



void Putlist(adjmgraph*g1)
{
	int i, j;
	int a[maxsize];
	int distance[maxsize], path[maxsize];
	printf("请输入你要生成的路由表的起始路由器是第几个路由器v\n");
	scanf_s("%d", &i);
	if (i > g1->vertices.size)
	{
		printf("错误\n");
		return;
	}
	i--;
	dijkstra(g1, i, distance, path);
	printf("从顶点%d到其他各顶点的最短距离为：\n", i);
	for (j = 0; j < g1->vertices.size; j++)
		if (distance[j] != maxweight) {

			printf("到顶点%d的最短距离为%d\n", j + 1, distance[j]);
		}
}

void Deletevertex(adjmgraph*g1)
{
	int i;
	printf("请输入你要删除的是第几个顶点v\n");
	scanf_s("%d", &i);
	deletevertex(g1, i);

}

void Deleteedge(adjmgraph*g1)
{
	int i, j;
	printf("请输入你要删除的边的两个顶点v1,v2\n");
	scanf_s("%d%d", &i, &j);
	deleteedge(g1, i - 1, j - 1);

}

void Insertedge(adjmgraph*g1)
{
	int i, j, w;
	printf("请输入你要增加的边的两个顶点和其权直v1,v2,w\n");
	scanf_s("%d%d%d", &i, &j, &w);
	insertedge(g1, i - 1, j - 1, w);

}

void menu(adjmgraph*g1) {
	int p;
	printf("**********************网络路由生成************************\n");
	printf("**********************请选择相应实现功能******************\n");
	printf("**********************1.路由表输出并打印******************\n");
	printf("**********************2.删除节点**************************\n");
	printf("**********************3.删除边****************************\n");
	printf("**********************4.填加边**********************\n");
	printf("**********************5.填加节点**********************\n");
	printf("**********************6.退出系统**************************\n");
	printf("**********************请输入你的选择（1~6）***************\n");
	scanf_s("%d", &p);
	if (p < 1 || p>6)
	{
		printf("\n\n输入序号不属于菜单，请重新输入\n\n");
		p = 7;
	}
	switch (p)
	{
	case 1:
		Putlist(g1);
		break;
	case 2:
		Deletevertex(g1);
		break;
	case 3:
		Deleteedge(g1);
		break;
	case 4:
		Insertedge(g1);
		break;
	case 5:
		int vertex;
		printf("输入你要增加的顶点\n");
		scanf_s("%d", &vertex);
		if (vertex < g1->vertices.size) {
			printf("错误\n");
		}
		else {
			insertvertex(g1, vertex);
			Insertedge(g1);
		}
		break;
	case 6:
		exit(0);
		break;
	case 7:
		menu(g1);
	}
	menu(g1);
}




int main()
{
	int i, j, k;
	adjmgraph g1;
	int a[maxsize];
	rowcolweight rcw[100];
	FILE *fp = NULL;
	fopen_s(&fp, "tuoputu.txt", "r");
	fscanf_s(fp, "%d", &i);
	for (k = 0; k < i; k++)
	{
		fscanf_s(fp, "%d", &a[k]);
	}
	fscanf_s(fp, "%d", &j);
	for (k = 0; k < j; k++)
	{
		fscanf_s(fp, "%d%d%d", &rcw[k].row, &rcw[k].col, &rcw[k].weight);
	}
	fclose(fp);
	graphinitiate(&g1);
	_creatgraph(&g1, a, i, rcw, j);
	menu(&g1);
	system("pause");
}

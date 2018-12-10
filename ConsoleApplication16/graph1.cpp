#include"graph1.h"

void graphinitiate(adjmgraph*g) {
	int i, j;
	for (i = 0; i < maxvertics; i++)
		for (j = 0; j < maxvertics; j++) {
			if (i == j) {
				g->edge[i][j] = 0;
			}
			else {
				g->edge[i][j] = maxweight;
			}
		}
	g->numofedge = 0;
	listinitiate(&g->vertices);
}

printf("aerjiecha");

void insertvertex(adjmgraph*g, datatype vertex) {
	if (listinsert(&g->vertices, g->vertices.size, vertex) == 0) {
		printf("插入顶点时空间已满无法插入");
		exit(1);
	}
}

void insertedge(adjmgraph*g, int v1, int v2, int weight) {
	datatype x;
	if (v1 != v2) {
		if ((listget(g->vertices, v1, &x) == 0) || (listget(g->vertices, v2, &x) == 0)) {
			printf("插入边时参数v1和v2越界出错\n");
			exit(1);
		}
		g->edge[v1][v2] = weight;
		g->edge[v2][v1] = weight;
		g->numofedge++;
	}
}

void deleteedge(adjmgraph*g, int v1, int v2) {
	g->edge[v1][v2] = maxweight;
	g->edge[v2][v1] = maxweight;
	g->numofedge--;
}

void deletevertex(adjmgraph*g, int v) {
	int m3, i, j;
	m3 = v - 1;
	if (m3 < 0 || m3 >= g->vertices.size) {
		printf("此链路内没有您想要删除的路由器节点\n");
		exit(0);
	}
	else {
		// for (i = m3; i < g->vertices.size; i++)
		for (j = 0, i = m3; j < g->vertices.size; j++) {
			g->edge[j][i] = maxweight;
		}
		// for (i = m3; i < g->vertices.size; i++)
		for (i = m3, j = 0; j < g->vertices.size; j++)
			g->edge[i][j] = maxweight;
		// for (i = m3; i < g->vertices.size; i++)
		// g->vertices.list[i] = g->vertices.list[i] - 1;
		// g->vertices.size--;
		//printf("删除节点成功\n");
	}
}

int getfirstvex(adjmgraph g, int v) {
	int col;
	datatype x;
	v = v - 1;
	if (listget(g.vertices, v, &x) == 0) {
		printf("取第一个邻接点时参数v越界\n");
		exit(1);
	}
	for (col = 0; col < g.vertices.size; col++)
		if (g.edge[v][col] > 0 && g.edge[v][col] < maxweight)
			return col;
	return-1;
}

void _creatgraph(adjmgraph*g, datatype v[], int n, rowcolweight w[], int e) {
	int i, k;
	graphinitiate(g);
	for (i = 0; i < n; i++) {
		insertvertex(g, v[i]);
	}
	for (k = 0; k < e; k++)
		insertedge(g, w[k].row, w[k].col, w[k].weight);
}
void dijkstra(adjmgraph*g, int v0, int distance[], int path[]) {
	int n = g->vertices.size;
	int*s = (int*)malloc(sizeof(int)*n);
	int mindis, i, j, u;
	FILE*fp = NULL;
	for (i = 0; i < n; i++) {
		distance[i] = g->edge[v0][i];
		s[i] = 0;
		if (i != v0 && distance[i] < maxweight)
			path[i] = v0;
		else path[i] = -1;
	}
	s[v0] = 1;
	for (i = 1; i < n; i++) {
		mindis = maxweight;
		for (j = 0; j < n; j++)
			if (s[j] == 0 && distance[j] < mindis) {
				u = j;
				mindis = distance[j];
			}
		if (mindis == maxweight)
			break;
		s[u] = 1;
		for (j = 0; j < n; j++)
			if (s[j] == 0 && g->edge[u][j] < maxweight&&distance[u] + g->edge[u][j] < distance[j]) {
				distance[j] = distance[u] + g->edge[u][j];
				path[j] = u;
			}
	}
	printf("目的路由    下一跳路由\n");
	fopen_s(&fp, "luyoubiao.txt", "w");
	for (i = 0; i < n; i++) {
		if (i == v0)
			continue;
		j = i;
		while (path[j] != v0) {
			j = path[j];
			if (j == -1)
				break;
		}
		printf("%5d%12d\n", i + 1, j + 1);
		fprintf(fp, "%5d%12d\n", i + 1, j + 1);
	}
	fclose(fp);
}

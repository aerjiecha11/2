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

void insertvertex(adjmgraph*g, datatype vertex) {
	if (listinsert(&g->vertices, g->vertices.size, vertex) == 0) {
		printf("���붥��ʱ�ռ������޷�����");
		exit(1);
	}
}

void insertedge(adjmgraph*g, int v1, int v2, int weight) {
	datatype x;
	if (v1 != v2) {
		if ((listget(g->vertices, v1, &x) == 0) || (listget(g->vertices, v2, &x) == 0)) {
			printf("�����ʱ����v1��v2Խ�����\n");
			exit(1);
		}

		g->edge[v1][v2] = weight;
		g->edge[v2][v1] = weight;
		g->numofedge++;
		FILE *fp = NULL;
		fopen_s(&fp, "tuoputu.txt", "w");
		fprintf_s(fp, "%d\n", g->vertices.size);
		for (int i = 0; i < g->vertices.size; i++) {
			fprintf_s(fp, "%d ", g->vertices.list[i]);
		}
		fprintf_s(fp, "\n");
		fprintf_s(fp, "%d\n", g->numofedge);
		for (int i = 0; i < maxvertics; i++) {
			for (int j = 0; j <= i; j++) {
				if (g->edge[i][j] != maxweight && i != j) {
					fprintf_s(fp, "%d %d %d\n", i, j, g->edge[i][j]);
				}
			}
		}
		fclose(fp);
	}
}

void deleteedge(adjmgraph*g, int v1, int v2) {
	g->edge[v1][v2] = maxweight;
	g->edge[v2][v1] = maxweight;
	g->numofedge--;
	FILE *fp = NULL;
	fopen_s(&fp, "tuoputu.txt", "w");
	fprintf_s(fp, "%d\n", g->vertices.size);
	for (int i = 0; i < g->vertices.size; i++) {
		fprintf_s(fp, "%d ", g->vertices.list[i]);
	}
	fprintf_s(fp, "\n");
	fprintf_s(fp, "%d\n", g->numofedge);
	for (int i = 0; i < maxvertics; i++) {
		for (int j = 0; j <= i; j++) {
			if (g->edge[i][j] != maxweight && i != j) {
				fprintf_s(fp, "%d %d %d\n", i, j, g->edge[i][j]);
			}
		}
	}
	fclose(fp);
}

void deletevertex(adjmgraph*g, int v) {
	int m3, i, j;
	m3 = v - 1;
	if (m3 < 0 || m3 >= g->vertices.size) {
		printf("����·��û������Ҫɾ����·�����ڵ�\n");
	}
	else {
		int x;
		listdelete(&g->vertices, m3, &x);
		for (j = 0, i = m3; j < g->vertices.size; j++) {
			g->edge[j][i] = maxweight;
		}
		for (i = m3, j = 0; j < g->vertices.size; j++)
			g->edge[i][j] = maxweight;
		FILE *fp = NULL;
		fopen_s(&fp, "tuoputu.txt", "w");
		fprintf_s(fp, "%d\n", g->vertices.size);
		for (int i = 0; i < g->vertices.size; i++) {
			fprintf_s(fp, "%d ", g->vertices.list[i]);
		}
		fprintf_s(fp, "\n");
		fprintf_s(fp, "%d\n", g->numofedge);
		for (int i = 0; i < maxvertics; i++) {
			for (int j = 0; j <= i; j++) {
				if (g->edge[i][j] != maxweight && i != j) {
					fprintf_s(fp, "%d %d %d\n", i, j, g->edge[i][j]);
				}
			}
		}
		fclose(fp);
	}
}

/*int getfirstvex(adjmgraph g, int v) {
	int col;
	datatype x;
	v = v - 1;
	if (listget(g.vertices, v, &x) == 0) {
		printf("ȡ��һ���ڽӵ�ʱ����vԽ��\n");
		exit(1);
	}
	for (col = 0; col < g.vertices.size; col++)
		if (g.edge[v][col] > 0 && g.edge[v][col] < maxweight)
			return col;
	return-1;
}

int getnextvex(adjmgraph g, int v1, int v2) {
	int col;
	datatype x;
	if ((listget(g.vertices, v1, &x) == 0) || listget(g.vertices, v2, &x) == 0) {
		printf("ȡ��һ��Ӷ���ʱ����Խ�����\n");
		exit(1);
	}
	if (g.edge[v1][v2] == 0) {
		printf("v2����v1����Ӷ���\n");
		exit(1);
	}

	for (col = v2 + 1; col < g.vertices.size; col++)
		if (g.edge[v1][col] > 0 && g.edge[v1][col] < maxweight)
			return col;
	return -1;
}*/

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
	fopen_s(&fp, "luyoubiao.txt", "w");
	printf("Ŀ��·��    ��һ��·��\n");
	for (i = 0; i < n; i++) {
		if (i == v0)
			continue;
		j = i;
		while (path[j] != v0) {
			j = path[j];
			if (j == -1)
				break;
		}
		if (j != -1) {
			printf("%5d%12d\n", i + 1, j + 1);
			fprintf(fp, "%5d%12d\n", i + 1, j + 1);
		}
	}
	fclose(fp);
}
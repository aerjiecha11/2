#pragma once
#include"graph.h"
void graphinitiate(adjmgraph*g);
void insertvertex(adjmgraph*g, datatype vertex);
void insertedge(adjmgraph*g, int v1, int v2, int weight);
void deleteedge(adjmgraph*g, int v1, int v2);
void dijkstra(adjmgraph*g, int v0, int distance[], int path[]);
void deletevertex(adjmgraph*g, int v);
int getfirstvex(adjmgraph g, int v);
void _creatgraph(adjmgraph*g, datatype v[], int n, rowcolweight w[], int e);
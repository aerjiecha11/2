#include"seqlist.h"

typedef struct {
	int row;
	int col;
	int weight;
}rowcolweight;

typedef struct {
	seqlist vertices;
	int edge[maxvertics][maxvertics];
	int numofedge;
}adjmgraph; 

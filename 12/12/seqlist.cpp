#include"seqlist.h"

void listinitiate(seqlist*l) {
	l->size = 0;
}


int listlength(seqlist l) {
	return l.size;
}

int listinsert(seqlist*l, int i, datatype x) {
	int j;
	if (l->size >= maxsize) {
		printf("顺序表已满无法插入\n");
		return 0;
	}
	else if (i<0 || i>l->size) {
		printf("参数i不合法\n");
		return 0;
	}
	else {
		for (j = l->size; j > i; j--)
			l->list[j] = l->list[j - 1];
		l->list[i] = x;

		l->size++;
		return 1;

	}
}

int listdelete(seqlist*l, int i, datatype*x) {
	int j;
	if (l->size <= 0) {
		printf("顺序表已空无数据元素可删\n");
		return 0;
	}
	else if (i<0 || i>l->size - 1) {
		printf("参数i不合法\n");
		return 0;
	}
	else {
		*x = l->list[i];
		for (j = i + 1; j <= l->size - 1; j++)
			l->list[j - 1] = l->list[j];
		l->size--;
		return 1;

	}
}
int listget(seqlist l, int i, datatype*x) {
	if (i<0 || i>l.size - 1) {
		printf("参数i不合法\n");
		return 0;
	}
	else {
		*x = l.list[i];
		return 1;
	}
}

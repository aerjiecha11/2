
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
typedef int datatype;
#define maxsize 10
#define maxvertics 10
#define maxweight 1000

 typedef struct{
	datatype list[maxsize];
	int size;
}seqlist;

 void listinitiate(seqlist*l);
 int listlength(seqlist l);
 int listinsert(seqlist*l, int i, datatype x);
 int listdelete(seqlist*l, int i, datatype*x);
 int listget(seqlist l, int i, datatype*x);
 
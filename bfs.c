#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int node;
	node *right;

typedef struct graph{
	int N;
	int *visited;
	node *adj_matrix;
}graph;

graph* createGraph(int N){
	graph *ptr;
	ptr=(graph*)malloc(sizeof(graph));
	ptr->

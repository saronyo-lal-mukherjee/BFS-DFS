#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node *right;
}node;

typedef struct graph{
	int N;
	int *visited;
	struct node **adjList;
}graph;

graph* createGraph(int N){
	graph *ptr;
	int i;
	ptr=(graph*)malloc(sizeof(graph));
	ptr->N=N;
	ptr->visited=(int*)malloc(N*sizeof(int));
	ptr->adjList=(node**)malloc(N*sizeof(node*));
	i=0;
	while(i<N){
		ptr->visited[i]=0;
		ptr->adjList[i]=NULL;
		i++;
	}
	return ptr;
}

node* createNode(int val){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->val=val;
	ptr->right=0;
	return ptr;
}

graph* makeGraph();
void makeList(node**,int);

void main(){
	graph *graph;
	graph=makeGraph();
}

graph* makeGraph(){
	graph *graph;
	int N;
	printf("Enter the number of vertices you want::");
	scanf("%d",&N);
	graph=createGraph(N);
	makeList(graph->adjList,N);
	return graph;
}

void makeList(node **adjList,int N){
	int i,u,v;
	node *ptr;
	i=0;
	while(i<N){
		printf("Enter the connected vertices::");
		scanf("%d %d",&u,&v);
		if(adjList[u]==NULL){
			adjList[u]=createNode(v);
		}
		else{
			ptr=adjList[u];
			while(ptr->right!=NULL){
				ptr=ptr->right;
			}
			ptr->right=createNode(v);
		}
		if(adjList[v]==NULL){
			adjList[v]=createNode(u);
		}
		else{
			ptr=adjList[v];
			while(ptr->right!=NULL){
				ptr=ptr->right;
			}
			ptr->right=createNode(u);
		}
		i++;
	}
}


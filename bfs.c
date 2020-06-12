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
	ptr->visited=(int*)malloc((N+1)*sizeof(int));
	ptr->adjList=(node**)malloc((N+1)*sizeof(node*));
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
	ptr->right=NULL;
	return ptr;
}

typedef struct qnode{
	int val;
	struct qnode *right;
}qnode;

qnode* createQnode(int val){
	qnode *ptr;
	ptr=(qnode*)malloc(sizeof(qnode));
	ptr->val=val;
	ptr->right=0;
	return ptr;
}

qnode *queue=0;

void enqueue(int val){
	qnode *ptr,*qtr;
	if(queue==0){
		queue=createQnode(val);
	}
	else{
		ptr=createQnode(val);
		qtr=queue;
		while(qtr->right!=0){
			qtr=qtr->right;
		}
		qtr->right=ptr;
	}
}

int dequeue(){
	int val;
	if(queue==0){
		return -1;
	}
	else{
		val=queue->val;
		queue=queue->right;
		return val;
	}
}


graph* makeGraph();
void makeList(node**,int);
void bfs(graph*,int);

void main(){
	graph *graph;
	int start;
	graph=makeGraph();
	
	printf("Enter the starting node::");
	scanf("%d",&start);
	bfs(graph,start);
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
	int i,u,v,n;
	node *ptr;
	i=0;
	printf("Enter the number of edges::");
	scanf("%d",&n);
	while(i<n){
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
			ptr=adjList[v];\
			while(ptr->right!=NULL){
				ptr=ptr->right;
			}
			ptr->right=createNode(u);
		}
		i++;
	}
}


void bfs(graph *gr,int start){
	int deq;
	node *ptr;
	if(queue==0){
		enqueue(start);
	}
	deq=dequeue();
	printf("%d\n",deq);
	gr->visited[deq]=1;
	ptr=gr->adjList[deq];
	
	while(ptr!=NULL){
		
		if(gr->visited[ptr->val]==0){
			
			enqueue(ptr->val);
		}
		ptr=ptr->right;
		
	}
	
	if(queue!=0){
		bfs(gr,start);
	}
}

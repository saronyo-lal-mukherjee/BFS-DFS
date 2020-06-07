#include<stdio.h>
#include<stddef.h>

#define maxv 10

//Function Definitions

int** adj_matrix();
void display_adj_matrix(int**);

int main()
{
    display_adj_matrix(adj_matrix());
}






int** adj_matrix()
{
	int i,j,v,e,x,y;
	int a[maxv][maxv];
	printf("Enter Number of Vertices in the graph : ");
	scanf("%d",&v);
	for( i = 0 ; i < v ; i++){
        	for( j = 0 ; j < v ; j++){
			a[i][j]=0;
		}
	}
    
	printf("Enter number of edges :");
	scanf("%d",&e);
	printf("%d",a[0][0]);
	for( i = 0 ; i < e ; i++){
		printf("Enter node pairs to initialize edges : ");
        	scanf("%d %d",&x,&y);
        	a[x][y] = 1;
        	a[y][x] = 1;
    	}
    	return a;
}

void display_adj_matrix(int** a)
{
	int size,i,j;
    	size=5;
	printf("Adjacency Matrix\n---------------\n");
	
	for(i=0;i<size;i++)
	{
		
		printf("|");
		
        	for(j=0;j<size;j++)
        	{
			
            		printf("  %d  " , a[i][j]);
			printf("\nDONE\n");
        	}
        	printf("|\n");
	} 
	printf("----------------");
}

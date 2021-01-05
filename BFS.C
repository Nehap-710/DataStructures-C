#include<stdio.h>
#include<stdlib.h>

int n;
int adj[10][10], visited[10], queue[10], stack[10];

void bfs(int adj[10][10], int visited [], int start);
void dfs(int adj[10][10], int visited [], int start);

int main()
{
	int i,j,start;
	printf("\nEnter the number of nodes in graph:");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
		{
		    scanf("%d",&adj[i][j]);
		}
	}
	printf("Enter the starting point:");
	scanf("%d",&start);
	printf("\nBFS Traversal: ");
	bfs(adj,visited,start);
    for(i=0;i<n;i++)
	{
	     visited[i]=0;
	}
	printf("\nDFS Traversal: ");
	dfs(adj,visited,start);
}

void bfs(int adj[10][10], int visited [], int start)
{
    int i;
	int rear=-1;
	int front=-1;
	queue[++rear] = start;
	visited[start]=1;
	while(rear!=front)
	{
	   start=queue[++front];
	   printf("%c \t",start+65);
	   for(i=0;i<n;i++)
	   {
	       if(adj[start][i]==1 && visited[i]==0)
		   {
		       queue[++rear]=i;
			   visited[i]=1;
		   }
	   }
	}
}

void dfs(int adj[10][10], int visited[], int start)
{
    int top=-1, i;
	printf("%c \t",start+65);
	visited[start]=1;
	stack[++top]=start;
	while(top!= -1)
	{
	    start=stack[top];
		for(i=0;i<n;i++)
		{
		    if(adj[start][i]==1 && visited[i]==0)
			{
			    stack[++top]=i;
				printf("%c \t",i+65);
				visited[i]=1;
				break;
			}
		}
		if(i==n)
		{
		    top--;
		}
	}
}


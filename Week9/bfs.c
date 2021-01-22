#include<stdio.h>
int G[20][20],q[20],visited[20],n,front=1,rear=0;
void bfs(int v)
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	  if(G[v][i] && !visited[i])
	   q[++rear]=i;
	   if(front <= rear)
	    bfs(q[front++]);
}
int main()
{
	int v,i,j;
	printf("\n Enter the number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form: \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The nodes which are reachable are:\n");
	for(i=1;i<=n;i++)
		if(visited[i])
			printf("%d\t",i);
		else
			printf("\n %d is not reachable",i);
	return 0;
}
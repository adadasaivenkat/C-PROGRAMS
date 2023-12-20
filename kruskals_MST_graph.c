#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct graph
{
    int vertices;
    int **adj_matrix;
};
struct graph *create_graph(int vertices)
{
    struct graph *temp;
    temp=(struct graph *)malloc(sizeof(struct graph));
    temp->vertices=vertices;
    temp->adj_matrix=(int **)malloc(vertices*sizeof(int *));
    int i,j;
    for(i=0; i<vertices; i++)
    {
        temp->adj_matrix[i]=(int *)malloc(vertices*sizeof(int));
    }
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            temp->adj_matrix[i][j]=0;
        }
    }
    return temp;
}
void add_edge(struct graph *temp, int v1, int v2, int weight)
{
    temp->adj_matrix[v1][v2]=weight;
    temp->adj_matrix[v2][v1]=weight;  //For undirected graph (remove this line for directed graph)
}
int find(int parent[], int i)
{
    while(parent[i]!=-1)
    {
        i=parent[i];
    }
    return i;
}
void kruskal(struct graph *temp, int vertices)
{
    int count=1,a,b,c,d,i,j,min,min_cost=0;         //Here, count is no of edges i.e., count=vertices-1
    int cost[vertices][vertices];
    //Initialize 'cost' matrix with edge weights
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            cost[i][j]=temp->adj_matrix[i][j];
        }
    }
    int parent[vertices];
    for(i=0; i<vertices; i++)
    {
        parent[i]=-1;
    }
    while(count<vertices)
    {
        min=999;
        for(i=0; i<vertices; i++)
        {
            for(j=0; j<vertices; j++)
            {
                if(cost[i][j]!=0 && cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=c=i;
                    b=d=j;
                }
            }
        }
        c=find(parent,c);
        d=find(parent,d);
        if(c!=d)
        {
            printf("Edge cost from %d to %d : %d\n",a,b,min);
            min_cost+=min;
            parent[find(parent,c)]=find(parent,d);
            count++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost of the spanning tree : %d\n",min_cost);
}
int main()
{
    int vertices,edges,v1,v2,weight,i,j;
    printf("Enter the number of vertices : ");
    scanf("%d",&vertices);
    struct graph *temp;
    temp=create_graph(vertices);
    printf("Enter the number of edges : ");
    scanf("%d",&edges);
    for(i=0; i<edges; i++)
    {
        printf("Enter edge (vertex 1, vertex 2 and weight) : ");
        scanf("%d %d %d",&v1,&v2,&weight);
        add_edge(temp,v1,v2,weight);
    }
    printf("Adjaceny matrix : \n");
    for(i=0; i<temp->vertices; i++)
    {
        for(j=0; j<temp->vertices; j++)
        {
            printf("%d\t",temp->adj_matrix[i][j]);
        }
        printf("\n");
    }
    kruskal(temp,vertices);
    return 0;
}
#include<stdio.h>
#define INF 999
int prim(int c[10][10],int n,int s)
{
    int v[10],i,j,sum=0,ver[10],d[10],min,u;
    for(i=1; i<=n; i++)
    {
        ver[i]=s;
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=1; i<=n-1; i++)
    {
        min=INF;
        for(j=1; j<=n; j++)
            if(v[j]==0 && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        v[u]=1;
        sum=sum+d[u];
        printf("\n%d -> %d sum=%d",ver[u],u,sum);
        for(j=1; j<=n; j++)
            if(v[j]==0 && c[u][j]<d[j])
            {
                d[j]=c[u][j];
                ver[j]=u;
            }
    }
    return sum;
}
void main()
{
    int c[10][10],i,j,res,s,n;
    printf("\nEnter n value:");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&c[i][j]);
    printf("\nEnter the souce node:");
    scanf("%d",&s);
    res=prim(c,n,s);
    printf("\nCost=%d",res);
    getch();
}

//output

/*Enter n value:4

Enter the graph data:
4 5 2 1
7 5 9 2
1 7 6 9
0 2 8 5

Enter the souce node:4

4 -> 1 sum=0
4 -> 2 sum=2
1 -> 3 sum=4
Cost=4
#include <stdio.h>
int main()
{
	int a[20][20];int coada[20],viz[20];
	int i,n,e1,p1,j,m,x,y,p,u;
	printf("dati nr de noduri: ");
	scanf("%d",&n);
	printf("dati nr de muchii: ");
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i)
	{
		printf("Muchia cu nr. de ordine %d: ", i);
		scanf("%d%d",&x,&y);
		a[x][y] = 1; a[y][x]=1;
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			viz[i] = 0;
		}
			printf("dati nodul de plecare: %d \n",k);
			viz[k] = 1;
			coada[1] = k;
			p = 1;
			u = 1;
			while( p <= u )
			{
				e1 = coada[p];
				for (int j = 1; j <= n; ++j)
					if ( (a[e1][j] == 1) && (viz[j] == 0) )
					{
						u += 1;
						coada[u] = j;
						viz[j] = 1;
					}
					p += 1;
			}
			for (int i = 1; i <= u; ++i)
			{
				printf("%-5d",coada[i] );
			}
			printf("\n");
	}

	return 0;
}
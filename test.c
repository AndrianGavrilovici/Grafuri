#include <stdio.h>

int matrix(int n)
{
	int a[20][20];
	printf("Introduceti dimensiunea matricii: ");
	scanf("%d",&n);
	++n;
	for (int i = 1; i < n; ++i)
	{
		a[i][i] = 0;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (i < j)
			{
				printf("a[%d,%d]=",i,j);
				scanf("%d",&a[i][j]);
				a[j][i]=a[i][j];
			}
		}
	}
	
}
int cit_virf(int n,int d[20])
{
	int k,x,y,m,a[20][20];
	printf("nr de varfuri: ");scanf("%d",&n);
	printf("nr de muchii: ");scanf("%d",&m);
	++m;
	++n;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
			{
				a[i][j] = 0;
			}	
	}
	for (int k = 1; k < m; ++k)
	{
		printf("Muchia cu nr. de ordine %d: ", k);
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
      
}
int afis_mat(int n)
{
	int a[20][20];
	for (int i = 1; i < n; ++i)
	{
		printf("\n");
		for (int j = 1; j < n; ++j)
		{
			printf("%-4d",a[i][j]);
		}
	}
	printf("\n");
}
int grad(int n,int d[20])
{
	int s1,a[20][20];
	for (int i = 1; i < n; ++i)
	{
		s1 = 0;
		for (int j = 1; j < n; ++j)
		{
			s1 = a[i][j] + s1;
		}
		d[i] = s1;
	}
	for (int i = 1; i < n; ++i)
	{
		printf("d(%d)=%d\n",i,d[i]);
	}
}
int maxim(int n, int *max, int d[20])
{
	*max = d[1];
	for (int i = 1; i < n; ++i)
	{
		if (*max < d[i])
		{
			*max = d[i];
		}
	}
	printf("Nodul cu gradul maximal = %d\n", *max);
}
int minim(int n, int *min, int d[20])
{
	*min = d[1];
	for (int i = 1; i < n; ++i)
	{
		if (*min > d[i])
		{
			*min = d[i];
		}
	}
	printf("Nodul cu gradul minimal = %d\n", *min);
}
int main()
{
	int c,s1,t,i,j,n,min[20],max[20];
	int d[20],a[20][20];
	char p;
	printf("Alegeti prin matricea sau muchii: \n");
	printf("Matricea-m, Muchii-v: ");
	scanf("%c",&p);
	if (p == 'm')
	{
		n = matrix(i);
	}else n = cit_virf(i,d); 
	afis_mat(n);
	grad(n,d);
	maxim(n,max,d);	
	minim(n,min,d);
	if ( (*min == *max) && (*max == n-2) )
	{
		printf("Aceasta este graf complet\n");
	}else printf("Nu este graf complet\n");

	
}
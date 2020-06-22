#include <stdio.h>

int matrix(int n, int b[20][20], int c[20][20])
{
	int a[20][20],t;
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
				a[j][i] = a[i][j];
				t = a[i][j];
				if (t == 1)
				{
					b[i][j] = i;
					c[i][j] = j;
				}
			}
		}
	}
}
int cit_virf(int n, int d[20],int b[20],int c[20])
{
	int x,y,m,a[20][20];
	printf("nr de varfuri: ");scanf("%d",&n);
	do
	{
		printf("nr de muchii: ");scanf("%d",&m);
	}while( m >= n+1 );
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
		b[k] = x;
		c[k] = y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	if (m < n)
	{
		m = n;
	}
	
}
int afis_virf(int n,int b[20],int c[20])
{
	for (int k = 1; k < n; ++k)
	{
		printf("%d %d\n",b[k],c[k]);
	}
	int a[20][20];
	for (int i = 1; i < n; ++i)
	for (int j = 1; j < n; ++j);
}
int afis_virfm(int n,int b[20][20],int c[20][20])
{
	int t,r;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			t = b[i][j];
			r = c[i][j];
			if ( (t > 0) && (r > 0) && (t <= n) && (r <= n) )
			{
				printf("%d %d\n",b[i][j],c[i][j]);
			}
		}
		
	}
	int a[20][20];
	for (int i = 1; i < n; ++i)
	for (int j = 1; j < n; ++j);
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
	int s1,b,c,a[20][20];
	b = 0;
	c = 0;
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
		if (d[i] == 0)
		{
			b += 1;
		}
		if (d[i] == 1)
		{
			c += 1;
		}
	}
	printf("Noduri terminale = %d\n", c);
	printf("Noduri izolate = %d\n",b);
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
	int z,n,t[20],l[20],x[20][20],y[20][20],min[20],max[20];
	int d[20],a[20][20];
	char p,s;
	printf("Alegeti prin Matricea sau Muchii: \n");
	printf("Matricea-m, Muchii-v: ");
	scanf("%c",&p);
	if (p == 'm')
	{
		n = matrix(z,x,y);
	}else 
		if (p == 'v')
		{
			n = cit_virf(z,d,t,l);
		}		
	printf("Alegeti sa se reprezinte prin Matrice sau Muchii: \n");
	printf("Matrice-m, Muchii-v: ");
	scanf("%c",&s);
	
	scanf("%c",&s);
	if (s == 'm')
	{
		afis_mat(n);
	}else if ( (p == 'm') && (s == 'v') )
		{
			afis_virfm(n,x,y);
		} else if ( (p == 'v') && (s == 'v') )
			{
				afis_virf(n,t,l);
			}
	
	
	grad(n,d);
	maxim(n,max,d);	
	minim(n,min,d);
	if ( (*min == *max) && (*max == n-2) )
	{
		printf("Aceasta este graf complet\n");
	}else printf("Nu este graf complet\n");

	
}
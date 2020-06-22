//pracurgere in latime(BREADTH FIRST, recursiv)
#include <stdio.h>
int a[20][20];
int coada[20],viz[20];
int n,p1,m,x,y,u,l;
void parc_latime(int i)
{
	for(int j=0;j<=n;++j)
		if ((a[coada[i]][j]==1)&&(viz[j]==0)){
			u += 1;coada[u] = j;viz[j] = 1;
		}
	if(i<=u)
		parc_latime(i+1);
}
int main()
{
	printf("n= ");
	scanf("%d",&n);
	printf("m= ");
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		printf("Muchia cu nr. de ordine %d: ",i);
		scanf("%d%d",&x,&y);
		a[x][y]=1;a[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		viz[i]=0;
	printf("dati nodul de plecare: ");
	scanf("%d",&p1);
	viz[p1]=1;
	coada[1]=p1;
	u=1;
	parc_latime(l);
	for(int i=1;i<=u;i++)
		printf("%-3d",coada[i]);
	printf("\n");
	return 0;
}